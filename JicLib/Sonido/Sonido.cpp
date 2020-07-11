

// Copyright (c) Microsoft Corp. All rights reserved.
//-----------------------------------------------------------------------------
#define STRICT

#include "Sonido.h"
#undef min // use __min instead
#undef max // use __max instead

//-----------------------------------------------------------------------------
// Name: Sonido::Sonido()
// Desc: Constructs the class.  Call Open() to open a wave file for reading.
//       Then call Read() as needed.  Calling the destructor or Close()
//       will close the file.
//-----------------------------------------------------------------------------
Sonido::Sonido()
{
	m_pwfx = NULL;
	m_hmmio = NULL;
	m_pResourceBuffer = NULL;
	m_dwSize = 0;
	m_bIsReadingFromMemory = FALSE;
	Loaded = false;


}


//-----------------------------------------------------------------------------
// Name: Sonido::~Sonido()
// Desc: Destructs the class
//-----------------------------------------------------------------------------
Sonido::~Sonido()
{

	// All XAudio2 interfaces are released when the engine is destroyed, but being tidy


	SAFE_DELETE_ARRAY(pbWaveData);

	if (!m_bIsReadingFromMemory)
		SAFE_DELETE_ARRAY(m_pwfx);

	SAFE_RELEASE(pXAudio2);
	CoUninitialize();
}


//-----------------------------------------------------------------------------
// Name: Sonido::Open()
// Desc: Opens a wave file for reading
//-----------------------------------------------------------------------------
HRESULT Sonido::Open(LPWSTR strFileName, WAVEFORMATEX* pwfx, DWORD dwFlags)
{
	HRESULT hr;

	m_dwFlags = dwFlags;
	m_bIsReadingFromMemory = FALSE;

	if (m_dwFlags == WAVEFILE_READ)
	{
		if (strFileName == NULL)
			return E_INVALIDARG;
		SAFE_DELETE_ARRAY(m_pwfx);

		m_hmmio = mmioOpen(strFileName, NULL, MMIO_ALLOCBUF | MMIO_READ);

		if (NULL == m_hmmio)
		{
			HRSRC hResInfo;
			HGLOBAL hResData;
			DWORD dwSize;
			VOID* pvRes;

			// Loading it as a file failed, so try it as a resource
			if (NULL == (hResInfo = FindResource(NULL, strFileName, L"WAVE")))
			{
				if (NULL == (hResInfo = FindResource(NULL, strFileName, L"WAV")))
					return NULL;//NULL;//DXTRACE_ERR(L"FindResource", E_FAIL);
			}

			if (NULL == (hResData = LoadResource(GetModuleHandle(NULL), hResInfo)))
				return NULL;//DXTRACE_ERR(L"LoadResource", E_FAIL);

			if (0 == (dwSize = SizeofResource(GetModuleHandle(NULL), hResInfo)))
				return NULL;//DXTRACE_ERR(L"SizeofResource", E_FAIL);

			if (NULL == (pvRes = LockResource(hResData)))
				return NULL;//DXTRACE_ERR(L"LockResource", E_FAIL);

			m_pResourceBuffer = new CHAR[dwSize];
			if (m_pResourceBuffer == NULL)
				return NULL;//DXTRACE_ERR(L"new", E_OUTOFMEMORY);
			memcpy(m_pResourceBuffer, pvRes, dwSize);

			MMIOINFO mmioInfo;
			ZeroMemory(&mmioInfo, sizeof(mmioInfo));
			mmioInfo.fccIOProc = FOURCC_MEM;
			mmioInfo.cchBuffer = dwSize;
			mmioInfo.pchBuffer = (CHAR*)m_pResourceBuffer;

			m_hmmio = mmioOpen(NULL, &mmioInfo, MMIO_ALLOCBUF | MMIO_READ);
		}

		if (FAILED(hr = ReadMMIO()))
		{
			// ReadMMIO will fail if its an not a wave file
			mmioClose(m_hmmio, 0);
			return NULL;//DXTRACE_ERR(L"ReadMMIO", hr);
		}

		if (FAILED(hr = ResetFile()))
			return NULL;//DXTRACE_ERR(L"ResetFile", hr);

		// After the reset, the size of the wav file is m_ck.cksize so store it now
		m_dwSize = m_ck.cksize;
	}
	else
	{
		m_hmmio = mmioOpen(strFileName, NULL, MMIO_ALLOCBUF |
			MMIO_READWRITE |
			MMIO_CREATE);
		if (NULL == m_hmmio)
			return NULL;//DXTRACE_ERR(L"mmioOpen", E_FAIL);

		if (FAILED(hr = WriteMMIO(pwfx)))
		{
			mmioClose(m_hmmio, 0);
			return NULL;//DXTRACE_ERR(L"WriteMMIO", hr);
		}

		if (FAILED(hr = ResetFile()))
			return NULL;//DXTRACE_ERR(L"ResetFile", hr);
	}

	return hr;
}


//-----------------------------------------------------------------------------
// Name: Sonido::OpenFromMemory()
// Desc: copy data to Sonido member variable from memory
//-----------------------------------------------------------------------------
HRESULT Sonido::OpenFromMemory(BYTE* pbData, ULONG ulDataSize,
	WAVEFORMATEX* pwfx, DWORD dwFlags)
{
	m_pwfx = pwfx;
	m_ulDataSize = ulDataSize;
	m_pbData = pbData;
	m_pbDataCur = m_pbData;
	m_bIsReadingFromMemory = TRUE;

	if (dwFlags != WAVEFILE_READ)
		return E_NOTIMPL;

	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: Sonido::ReadMMIO()
// Desc: Support function for reading from a multimedia I/O stream.
//       m_hmmio must be valid before calling.  This function uses it to
//       update m_ckRiff, and m_pwfx.
//-----------------------------------------------------------------------------
HRESULT Sonido::ReadMMIO()
{
	MMCKINFO ckIn;           // chunk info. for general use.
	PCMWAVEFORMAT pcmWaveFormat;  // Temp PCM structure to load in.

	memset(&ckIn, 0, sizeof(ckIn));

	m_pwfx = NULL;

	if ((0 != mmioDescend(m_hmmio, &m_ckRiff, NULL, 0)))
		return NULL;//DXTRACE_ERR(L"mmioDescend", E_FAIL);

	// Check to make sure this is a valid wave file
	if ((m_ckRiff.ckid != FOURCC_RIFF) ||
		(m_ckRiff.fccType != mmioFOURCC('W', 'A', 'V', 'E')))
		return NULL;//DXTRACE_ERR(L"mmioFOURCC", E_FAIL);

	// Search the input file for for the 'fmt ' chunk.
	ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
	if (0 != mmioDescend(m_hmmio, &ckIn, &m_ckRiff, MMIO_FINDCHUNK))
		return NULL;//DXTRACE_ERR(L"mmioDescend", E_FAIL);

	// Expect the 'fmt' chunk to be at least as large as <PCMWAVEFORMAT>;
	// if there are extra parameters at the end, we'll ignore them
	if (ckIn.cksize < (LONG)sizeof(PCMWAVEFORMAT))
		return NULL;//DXTRACE_ERR(L"sizeof(PCMWAVEFORMAT)", E_FAIL);

	// Read the 'fmt ' chunk into <pcmWaveFormat>.
	if (mmioRead(m_hmmio, (HPSTR)&pcmWaveFormat,
		sizeof(pcmWaveFormat)) != sizeof(pcmWaveFormat))
		return NULL;//DXTRACE_ERR(L"mmioRead", E_FAIL);

	// Allocate the waveformatex, but if its not pcm format, read the next
	// word, and thats how many extra bytes to allocate.
	if (pcmWaveFormat.wf.wFormatTag == WAVE_FORMAT_PCM)
	{
		m_pwfx = (WAVEFORMATEX*)new CHAR[sizeof(WAVEFORMATEX)];
		if (NULL == m_pwfx)
			return NULL;//DXTRACE_ERR(L"m_pwfx", E_FAIL);

		// Copy the bytes from the pcm structure to the waveformatex structure
		memcpy(m_pwfx, &pcmWaveFormat, sizeof(pcmWaveFormat));
		m_pwfx->cbSize = 0;
	}
	else
	{
		// Read in length of extra bytes.
		WORD cbExtraBytes = 0L;
		if (mmioRead(m_hmmio, (CHAR*)&cbExtraBytes, sizeof(WORD)) != sizeof(WORD))
			return NULL;//DXTRACE_ERR(L"mmioRead", E_FAIL);

		m_pwfx = (WAVEFORMATEX*)new CHAR[sizeof(WAVEFORMATEX)+cbExtraBytes];
		if (NULL == m_pwfx)
			return NULL;//DXTRACE_ERR(L"new", E_FAIL);

		// Copy the bytes from the pcm structure to the waveformatex structure
		memcpy(m_pwfx, &pcmWaveFormat, sizeof(pcmWaveFormat));
		m_pwfx->cbSize = cbExtraBytes;

		// Now, read those extra bytes into the structure, if cbExtraAlloc != 0.
		if (mmioRead(m_hmmio, (CHAR*)(((BYTE*)&(m_pwfx->cbSize)) + sizeof(WORD)),
			cbExtraBytes) != cbExtraBytes)
		{
			//SAFE_DELETE(m_pwfx);
			return NULL;//DXTRACE_ERR(L"mmioRead", E_FAIL);
		}
	}

	// Ascend the input file out of the 'fmt ' chunk.
	if (0 != mmioAscend(m_hmmio, &ckIn, 0))
	{
		//SAFE_DELETE(m_pwfx);
		return NULL;//DXTRACE_ERR(L"mmioAscend", E_FAIL);
	}

	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: Sonido::ResetFile()
// Desc: Resets the internal m_ck pointer so reading starts from the
//       beginning of the file again
//-----------------------------------------------------------------------------
HRESULT Sonido::ResetFile()
{
	if (m_bIsReadingFromMemory)
	{
		m_pbDataCur = m_pbData;
	}
	else
	{
		if (m_hmmio == NULL)
			return CO_E_NOTINITIALIZED;

		if (m_dwFlags == WAVEFILE_READ)
		{
			// Seek to the data
			if (-1 == mmioSeek(m_hmmio, m_ckRiff.dwDataOffset + sizeof(FOURCC),
				SEEK_SET))
				return NULL;//DXTRACE_ERR(L"mmioSeek", E_FAIL);

			// Search the input file for the 'data' chunk.
			m_ck.ckid = mmioFOURCC('d', 'a', 't', 'a');
			if (0 != mmioDescend(m_hmmio, &m_ck, &m_ckRiff, MMIO_FINDCHUNK))
				return NULL;//DXTRACE_ERR(L"mmioDescend", E_FAIL);
		}
		else
		{
			// Create the 'data' chunk that holds the waveform samples.
			m_ck.ckid = mmioFOURCC('d', 'a', 't', 'a');
			m_ck.cksize = 0;

			if (0 != mmioCreateChunk(m_hmmio, &m_ck, 0))
				return NULL;//DXTRACE_ERR(L"mmioCreateChunk", E_FAIL);

			if (0 != mmioGetInfo(m_hmmio, &m_mmioinfoOut, 0))
				return NULL;//DXTRACE_ERR(L"mmioGetInfo", E_FAIL);
		}
	}

	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: Sonido::Read()
// Desc: Reads section of data from a wave file into pBuffer and returns
//       how much read in pdwSizeRead, reading not more than dwSizeToRead.
//       This uses m_ck to determine where to start reading from.  So
//       subsequent calls will be continue where the last left off unless
//       Reset() is called.
//-----------------------------------------------------------------------------
HRESULT Sonido::Read(BYTE* pBuffer, DWORD dwSizeToRead, DWORD* pdwSizeRead)
{
	if (m_bIsReadingFromMemory)
	{
		if (m_pbDataCur == NULL)
			return CO_E_NOTINITIALIZED;
		if (pdwSizeRead != NULL)
			*pdwSizeRead = 0;

		if ((BYTE*)(m_pbDataCur + dwSizeToRead) >
			(BYTE*)(m_pbData + m_ulDataSize))
		{
			dwSizeToRead = m_ulDataSize - (DWORD)(m_pbDataCur - m_pbData);
		}

#pragma warning( disable: 4616 )    // disable warning about warning number '22104' being out of range
#pragma warning( disable: 22104 )   // disable PREfast warning during static code analysis
		CopyMemory(pBuffer, m_pbDataCur, dwSizeToRead);
#pragma warning( default: 22104 )
#pragma warning( default: 4616 )

		if (pdwSizeRead != NULL)
			*pdwSizeRead = dwSizeToRead;

		return S_OK;
	}
	else
	{
		MMIOINFO mmioinfoIn; // current status of m_hmmio

		if (m_hmmio == NULL)
			return CO_E_NOTINITIALIZED;
		if (pBuffer == NULL || pdwSizeRead == NULL)
			return E_INVALIDARG;

		*pdwSizeRead = 0;

		if (0 != mmioGetInfo(m_hmmio, &mmioinfoIn, 0))
			return NULL;//DXTRACE_ERR(L"mmioGetInfo", E_FAIL);

		UINT cbDataIn = dwSizeToRead;
		if (cbDataIn > m_ck.cksize)
			cbDataIn = m_ck.cksize;

		m_ck.cksize -= cbDataIn;

		for (DWORD cT = 0; cT < cbDataIn; cT++)
		{
			// Copy the bytes from the io to the buffer.
			if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead)
			{
				if (0 != mmioAdvance(m_hmmio, &mmioinfoIn, MMIO_READ))
					return NULL;//DXTRACE_ERR(L"mmioAdvance", E_FAIL);

				if (mmioinfoIn.pchNext == mmioinfoIn.pchEndRead)
					return NULL;//DXTRACE_ERR(L"mmioinfoIn.pchNext", E_FAIL);
			}

			// Actual copy.
			*((BYTE*)pBuffer + cT) = *((BYTE*)mmioinfoIn.pchNext);
			mmioinfoIn.pchNext++;
		}

		if (0 != mmioSetInfo(m_hmmio, &mmioinfoIn, 0))
			return NULL;//DXTRACE_ERR(L"mmioSetInfo", E_FAIL);

		*pdwSizeRead = cbDataIn;

		return S_OK;
	}
}


//-----------------------------------------------------------------------------
// Name: Sonido::Close()
// Desc: Closes the wave file
//-----------------------------------------------------------------------------
HRESULT Sonido::Close()
{
	if (m_dwFlags == WAVEFILE_READ)
	{
		if (m_hmmio != NULL)
		{
			mmioClose(m_hmmio, 0);
			m_hmmio = NULL;
		}
		SAFE_DELETE_ARRAY(m_pResourceBuffer);
	}
	else
	{
		m_mmioinfoOut.dwFlags |= MMIO_DIRTY;

		if (m_hmmio == NULL)
			return CO_E_NOTINITIALIZED;

		if (0 != mmioSetInfo(m_hmmio, &m_mmioinfoOut, 0))
			return NULL;//DXTRACE_ERR(L"mmioSetInfo", E_FAIL);

		// Ascend the output file out of the 'data' chunk -- this will cause
		// the chunk size of the 'data' chunk to be written.
		if (0 != mmioAscend(m_hmmio, &m_ck, 0))
			return NULL;//DXTRACE_ERR(L"mmioAscend", E_FAIL);

		// Do this here instead...
		if (0 != mmioAscend(m_hmmio, &m_ckRiff, 0))
			return NULL;//DXTRACE_ERR(L"mmioAscend", E_FAIL);

		mmioSeek(m_hmmio, 0, SEEK_SET);

		if (0 != (INT)mmioDescend(m_hmmio, &m_ckRiff, NULL, 0))
			return NULL;//DXTRACE_ERR(L"mmioDescend", E_FAIL);

		m_ck.ckid = mmioFOURCC('f', 'a', 'c', 't');

		if (0 == mmioDescend(m_hmmio, &m_ck, &m_ckRiff, MMIO_FINDCHUNK))
		{
			DWORD dwSamples = 0;
			mmioWrite(m_hmmio, (HPSTR)&dwSamples, sizeof(DWORD));
			mmioAscend(m_hmmio, &m_ck, 0);
		}

		// Ascend the output file out of the 'RIFF' chunk -- this will cause
		// the chunk size of the 'RIFF' chunk to be written.
		if (0 != mmioAscend(m_hmmio, &m_ckRiff, 0))
			return NULL;//DXTRACE_ERR(L"mmioAscend", E_FAIL);

		mmioClose(m_hmmio, 0);
		m_hmmio = NULL;
	}

	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: Sonido::WriteMMIO()
// Desc: Support function for reading from a multimedia I/O stream
//       pwfxDest is the WAVEFORMATEX for this new wave file.
//       m_hmmio must be valid before calling.  This function uses it to
//       update m_ckRiff, and m_ck.
//-----------------------------------------------------------------------------
HRESULT Sonido::WriteMMIO(WAVEFORMATEX* pwfxDest)
{
	DWORD dwFactChunk; // Contains the actual fact chunk. Garbage until WaveCloseWriteFile.
	MMCKINFO ckOut1;

	memset(&ckOut1, 0, sizeof(ckOut1));

	dwFactChunk = (DWORD)-1;

	// Create the output file RIFF chunk of form type 'WAVE'.
	m_ckRiff.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	m_ckRiff.cksize = 0;

	if (0 != mmioCreateChunk(m_hmmio, &m_ckRiff, MMIO_CREATERIFF))
		return NULL;//DXTRACE_ERR(L"mmioCreateChunk", E_FAIL);

	// We are now descended into the 'RIFF' chunk we just created.
	// Now create the 'fmt ' chunk. Since we know the size of this chunk,
	// specify it in the MMCKINFO structure so MMIO doesn't have to seek
	// back and set the chunk size after ascending from the chunk.
	m_ck.ckid = mmioFOURCC('f', 'm', 't', ' ');
	m_ck.cksize = sizeof(PCMWAVEFORMAT);

	if (0 != mmioCreateChunk(m_hmmio, &m_ck, 0))
		return NULL;//DXTRACE_ERR(L"mmioCreateChunk", E_FAIL);

	// Write the PCMWAVEFORMAT structure to the 'fmt ' chunk if its that type.
	if (pwfxDest->wFormatTag == WAVE_FORMAT_PCM)
	{
		if (mmioWrite(m_hmmio, (HPSTR)pwfxDest,
			sizeof(PCMWAVEFORMAT)) != sizeof(PCMWAVEFORMAT))
			return NULL;//DXTRACE_ERR(L"mmioWrite", E_FAIL);
	}
	else
	{
		// Write the variable length size.
		if ((UINT)mmioWrite(m_hmmio, (HPSTR)pwfxDest,
			sizeof(*pwfxDest) + pwfxDest->cbSize) !=
			(sizeof(*pwfxDest) + pwfxDest->cbSize))
			return NULL;//DXTRACE_ERR(L"mmioWrite", E_FAIL);
	}

	// Ascend out of the 'fmt ' chunk, back into the 'RIFF' chunk.
	if (0 != mmioAscend(m_hmmio, &m_ck, 0))
		return NULL;//DXTRACE_ERR(L"mmioAscend", E_FAIL);

	// Now create the fact chunk, not required for PCM but nice to have.  This is filled
	// in when the close routine is called.
	ckOut1.ckid = mmioFOURCC('f', 'a', 'c', 't');
	ckOut1.cksize = 0;

	if (0 != mmioCreateChunk(m_hmmio, &ckOut1, 0))
		return NULL;//DXTRACE_ERR(L"mmioCreateChunk", E_FAIL);

	if (mmioWrite(m_hmmio, (HPSTR)&dwFactChunk, sizeof(dwFactChunk)) !=
		sizeof(dwFactChunk))
		return NULL;//DXTRACE_ERR(L"mmioWrite", E_FAIL);

	// Now ascend out of the fact chunk...
	if (0 != mmioAscend(m_hmmio, &ckOut1, 0))
		return NULL;//DXTRACE_ERR(L"mmioAscend", E_FAIL);

	return S_OK;
}


//-----------------------------------------------------------------------------
// Name: Sonido::Write()
// Desc: Writes data to the open wave file
//-----------------------------------------------------------------------------
HRESULT Sonido::Write(UINT nSizeToWrite, BYTE* pbSrcData, UINT* pnSizeWrote)
{
	UINT cT;

	if (m_bIsReadingFromMemory)
		return E_NOTIMPL;
	if (m_hmmio == NULL)
		return CO_E_NOTINITIALIZED;
	if (pnSizeWrote == NULL || pbSrcData == NULL)
		return E_INVALIDARG;

	*pnSizeWrote = 0;

	for (cT = 0; cT < nSizeToWrite; cT++)
	{
		if (m_mmioinfoOut.pchNext == m_mmioinfoOut.pchEndWrite)
		{
			m_mmioinfoOut.dwFlags |= MMIO_DIRTY;
			if (0 != mmioAdvance(m_hmmio, &m_mmioinfoOut, MMIO_WRITE))
				return NULL;//DXTRACE_ERR(L"mmioAdvance", E_FAIL);
		}

		*((BYTE*)m_mmioinfoOut.pchNext) = *((BYTE*)pbSrcData + cT);
		(BYTE*)m_mmioinfoOut.pchNext++;

		(*pnSizeWrote)++;
	}

	return S_OK;
}

HRESULT Sonido::LoadAsset(LPCWSTR file)
{
	HRESULT hr = S_OK;

	pMasteringVoice = NULL;

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	pXAudio2 = NULL;
	pMasteringVoice = NULL;

	UINT32 flags = 0;
#ifdef _DEBUG
	flags |= XAUDIO2_DEBUG_ENGINE;
#endif

	if (FAILED(hr = XAudio2Create(&pXAudio2, flags)))
	{
		CoUninitialize();
		MessageBox(NULL, L"Failed to initialize Sonido\nFailed to init XAudio2 engine: %#X", L"Error", MB_OK);
	}

	if (FAILED(hr = pXAudio2->CreateMasteringVoice(&pMasteringVoice)))
	{
		wprintf(L"Failed creating mastering voice: %#X\n", hr);
		SAFE_RELEASE(pXAudio2);
		CoUninitialize();

		MessageBox(NULL, L"Failed to initialize Sonido\nFailed creating mastering voice: %#X", L"Error", MB_OK);
	}

	//
	// Locate the wave file
	//
	WCHAR strFilePath[MAX_PATH];
	if (FAILED(hr = FindMediaFileCch(strFilePath, MAX_PATH, (LPCWSTR)file)))
	{
		MessageBox(NULL, L"Failed to find media file: %s\n", L"Error", MB_OK);
		return hr;
	}

	//
	// Read in the wave file
	//
	if (FAILED(hr = Open(strFilePath, NULL, WAVEFILE_READ)))
	{
		MessageBox(NULL, L"Failed reading WAV file", L"Error", MB_OK);
		return hr;
	}

	// Calculate how many bytes and samples are in the wave
	DWORD cbWaveSize = GetSize();

	// Read the sample data into memory
	pbWaveData = new BYTE[cbWaveSize];

	if (FAILED(hr = Read(pbWaveData, cbWaveSize, &cbWaveSize)))
	{
		MessageBox(NULL, L"Failed reading WAV data", L"Error", MB_OK);
		SAFE_DELETE_ARRAY(pbWaveData);
		return hr;
	}

	if (FAILED(hr = Close()))
	{
		MessageBox(NULL, L"Failed closing WAV file", L"Error", MB_OK);
		return hr;
	}



	Loaded = true;

	return hr;
}

WAVEFORMATEX* Sonido::GetFormat()
{
	return m_pwfx;
}

DWORD Sonido::GetSize()
{
	return m_dwSize;
}

HRESULT Sonido::Play(LPCWSTR szFilename)
{
	HRESULT hr = S_OK;

	if (!Loaded)
		LoadAsset(szFilename);

	IXAudio2SourceVoice* pSourceVoice;

	// Create the source voice
	if (FAILED(hr = pXAudio2->CreateSourceVoice(&pSourceVoice, GetFormat())))
	{
		wprintf(L"Error %#X creating source voice\n", hr);
		SAFE_DELETE_ARRAY(pbWaveData);
		return hr;
	}

	// Submit the wave sample data using an XAUDIO2_BUFFER structure
	XAUDIO2_BUFFER buffer = { 0 };
	buffer.pAudioData = pbWaveData;
	buffer.Flags = XAUDIO2_END_OF_STREAM;  // tell the source voice not to expect any data after this buffer
	buffer.AudioBytes = GetSize();


	if (FAILED(hr = pSourceVoice->SubmitSourceBuffer(&buffer)))
	{
		wprintf(L"Error %#X submitting source buffer\n", hr);
		pSourceVoice->DestroyVoice();
		SAFE_DELETE_ARRAY(pbWaveData);
		return hr;
	}

	hr = pSourceVoice->Start(0);

	//pSourceVoice->DestroyVoice();

	return hr;
}

XAUDIO2_VOICE_STATE Sonido::GetState()
{
	XAUDIO2_VOICE_STATE state;
	//pSourceVoice->GetState(&state);
	return state;
}

HRESULT Sonido::FindMediaFileCch(WCHAR* strDestPath, int cchDest, LPCWSTR strFilename)
{
	bool bFound = false;

	if (NULL == strFilename || strFilename[0] == 0 || NULL == strDestPath || cchDest < 10)
		return E_INVALIDARG;

	// Get the exe name, and exe path
	WCHAR strExePath[MAX_PATH] = { 0 };
	WCHAR strExeName[MAX_PATH] = { 0 };
	WCHAR* strLastSlash = NULL;
	GetModuleFileName(NULL, strExePath, MAX_PATH);
	strExePath[MAX_PATH - 1] = 0;
	strLastSlash = wcsrchr(strExePath, TEXT('\\'));
	if (strLastSlash)
	{
		wcscpy_s(strExeName, MAX_PATH, &strLastSlash[1]);

		// Chop the exe name from the exe path
		*strLastSlash = 0;

		// Chop the .exe from the exe name
		strLastSlash = wcsrchr(strExeName, TEXT('.'));
		if (strLastSlash)
			*strLastSlash = 0;
	}

	wcscpy_s(strDestPath, cchDest, strFilename);
	if (GetFileAttributes(strDestPath) != 0xFFFFFFFF)
		return S_OK;

	// Search all parent directories starting at .\ and using strFilename as the leaf name
	WCHAR strLeafName[MAX_PATH] = { 0 };
	wcscpy_s(strLeafName, MAX_PATH, strFilename);

	WCHAR strFullPath[MAX_PATH] = { 0 };
	WCHAR strFullFileName[MAX_PATH] = { 0 };
	WCHAR strSearch[MAX_PATH] = { 0 };
	WCHAR* strFilePart = NULL;

	GetFullPathName(L".", MAX_PATH, strFullPath, &strFilePart);
	if (strFilePart == NULL)
		return E_FAIL;

	while (strFilePart != NULL && *strFilePart != '\0')
	{
		swprintf_s(strFullFileName, MAX_PATH, L"%s\\%s", strFullPath, strLeafName);
		if (GetFileAttributes(strFullFileName) != 0xFFFFFFFF)
		{
			wcscpy_s(strDestPath, cchDest, strFullFileName);
			bFound = true;
			break;
		}

		swprintf_s(strFullFileName, MAX_PATH, L"%s\\%s\\%s", strFullPath, strExeName, strLeafName);
		if (GetFileAttributes(strFullFileName) != 0xFFFFFFFF)
		{
			wcscpy_s(strDestPath, cchDest, strFullFileName);
			bFound = true;
			break;
		}

		swprintf_s(strSearch, MAX_PATH, L"%s\\..", strFullPath);
		GetFullPathName(strSearch, MAX_PATH, strFullPath, &strFilePart);
	}
	if (bFound)
		return S_OK;

	// On failure, return the file as the path but also return an error code
	wcscpy_s(strDestPath, cchDest, strFilename);

	return HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
}
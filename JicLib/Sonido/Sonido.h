//----------------------------------------------
//
// ALL this code has been taken from the DX SDK
//
// Copyright (c) Microsoft Corp. All rights reserved.
//----------------------------------------------
#pragma once
#include "RCInterfaces.h"

#ifndef DXUTWAVEFILE_H
#define DXUTWAVEFILE_H

//-----------------------------------------------------------------------------
// Typing macros 
//-----------------------------------------------------------------------------
#define WAVEFILE_READ   1
#define WAVEFILE_WRITE  2

#include <xaudio2.h>

class Sonido
{
public:
	WAVEFORMATEX* m_pwfx;        // Pointer to WAVEFORMATEX structure
	HMMIO m_hmmio;       // MM I/O handle for the WAVE
	MMCKINFO m_ck;          // Multimedia RIFF chunk
	MMCKINFO m_ckRiff;      // Use in opening a WAVE file
	DWORD m_dwSize;      // The size of the wave file
	MMIOINFO m_mmioinfoOut;
	DWORD m_dwFlags;
	BOOL m_bIsReadingFromMemory;
	BYTE* m_pbData;
	BYTE* m_pbDataCur;
	ULONG m_ulDataSize;
	CHAR* m_pResourceBuffer;

protected:
	HRESULT ReadMMIO();
	HRESULT WriteMMIO(WAVEFORMATEX* pwfxDest);

	IXAudio2* pXAudio2;
	IXAudio2MasteringVoice* pMasteringVoice = NULL;

public:
	BYTE* pbWaveData;
	bool Loaded;

	DECLDIR XAUDIO2_VOICE_STATE GetState();

	DECLDIR Sonido();
	DECLDIR virtual ~Sonido();

	DECLDIR HRESULT LoadAsset(LPCWSTR file);

	DECLDIR HRESULT Open(LPWSTR strFileName, WAVEFORMATEX* pwfx, DWORD dwFlags);
	DECLDIR HRESULT OpenFromMemory(BYTE* pbData, ULONG ulDataSize, WAVEFORMATEX* pwfx, DWORD dwFlags);
	DECLDIR HRESULT Close();

	DECLDIR HRESULT Read(BYTE* pBuffer, DWORD dwSizeToRead, DWORD* pdwSizeRead);
	DECLDIR HRESULT Write(UINT nSizeToWrite, BYTE* pbData, UINT* pnSizeWrote);

	DECLDIR DWORD  GetSize();
	DECLDIR HRESULT ResetFile();
	DECLDIR WAVEFORMATEX* GetFormat();

	DECLDIR HRESULT FindMediaFileCch(WCHAR* strDestPath, int cchDest, LPCWSTR strFilename);

	DECLDIR HRESULT Play(LPCWSTR szFilename);
};

#endif // DXUTWAVEFILE_H

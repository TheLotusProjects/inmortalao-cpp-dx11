/*
	Author: Jose Ignacio Castelli
	Email: joseignaciocastelli@gmail.com
	Github: https://github.com/JicLotus
	Medium Page: https://medium.com/@joseignaciocastelli92
	Date: 01/01/2017
*/


#include "Programa.h"


Programa::Programa()
{
	graphic = 0;
	inputTeclas = 0;
}


Programa::~Programa()
{
}


bool Programa::Inicializar()
{
	graphic = new Graphic();
	return true;
}


void Programa::Shutdown()
{

	if (inputTeclas)
	{
		delete inputTeclas;
		inputTeclas = 0;
	}

	ShutdownWindows();

	if (graphic)
	{
		graphic->shutDown();
		delete graphic;
		graphic = 0;
	}

	return;
}


void Programa::Run()
{
	MSG msg;
	bool done, result;

	ZeroMemory(&msg, sizeof(MSG));

	done = false;

	personaje* pj = new personaje();

	int screenWidth, screenHeight;

	screenWidth = 1000;
	screenHeight = 1000;

	InitializeWindows(screenWidth, screenHeight);

	graphic->inicializar(screenWidth, screenHeight, m_hwnd, screenWidth, screenHeight, pj);
	
	inputTeclas = new InputTeclas();
	inputTeclas->Initialize();

	while (!done)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			result = Frame();
			if (!result)done = true;
			graphic->move(inputTeclas);
		}

	}

	return;
}


bool Programa::Frame()
{
	bool result;

	if (inputTeclas->IsKeyDown(VK_ESCAPE))
		return false;

	result = graphic->frame();

	if (!result)
		return false;

	return true;
}


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);

LRESULT CALLBACK Programa::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{

	if (ImGui_ImplWin32_WndProcHandler(hwnd, umsg, wparam, lparam))
		return true;

	switch (umsg)
	{
	case WM_KEYDOWN:
	{
		inputTeclas->KeyDown((unsigned int)wparam);
		return 0;
	}

	case WM_KEYUP:
	{
		inputTeclas->KeyUp((unsigned int)wparam);
		return 0;
	}

	default:
	{
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}

	}
}


void Programa::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;


	// Get an external pointer to this object.	
	ApplicationHandle = this;

	// Get the instance of this application.
	m_hinstance = GetModuleHandle(NULL);

	// Give the application a name.
	m_applicationName = L"Engine";

	// Setup the windows class with default settings.
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register the window class.
	RegisterClassEx(&wc);

	// Determine the resolution of the clients desktop screen.
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	bool a = false;
	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if (a)
	{
		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = posY = 0;
	}
	else
	{
		// If windowed then set it to 800x600 resolution.
		screenWidth = 1024;
		screenHeight = 768;

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}


	// Create the window with the screen settings and get the handle to it.
	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	
	ShowCursor(true);

	return;
}


void Programa::ShutdownWindows()
{
	ShowCursor(true);


	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	// Remove the application instance.
	UnregisterClass(m_applicationName, m_hinstance);
	m_hinstance = NULL;

	
	return;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	default:
	{
		return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
	}


	}
}
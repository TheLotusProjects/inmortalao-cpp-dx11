/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "Grafica.h"



Grafica::Grafica()
{
	FULL_SCREEN = false;
	VSYNC_ENABLED = true;
	SCREEN_DEPTH = 1000.0f;
	SCREEN_NEAR = 0.1f;
	directx11 = 0;
	camara = 0;
	tiempoTardado = 0.0;
	ticksPerFrame = 0.0;
}

particula* Grafica::getTempParticula()
{
	return particula->getTempParticula();
}

administradorRecursos* Grafica::getAdministrador()
{
	return administrador;
}

personaje* Grafica::getPj()
{
	return pj;
}

bool Grafica::inicializar(int anchoPantallaParam, int altoPantallaParam, HWND hwnd, int anchoResolucion, int altoResolucion, personaje* pjParam)
{

	
	anchoPantalla = anchoPantallaParam;
	altoPantalla = altoPantallaParam;

	directx11 = new Directx11();

	bool result = directx11->Initialize(anchoPantalla, altoPantalla, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR,anchoResolucion,altoResolucion);

	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	recursos = new Recursos(directx11->GetDevice(), hwnd);
	recursos->cargar();

	fps = new Fps();
	fps->Initialize();

	timer = new Timer();
	timer->Initialize();

	pj = pjParam;
	
	administrador = new administradorRecursos(recursos, directx11, pj);
	
	texto = new DibujadorTexto(directx11, recursos);
	texto->cargar(anchoPantalla,altoPantalla);

	pj->setParams(recursos,directx11, anchoPantalla, altoPantalla);

	camara = new Camara();
	camara->InitializeProjectionMatrix((float)D3DX_PI / 4.0f, (float)anchoPantalla / (float)altoPantalla, SCREEN_NEAR, SCREEN_DEPTH);
	camara->InitializeOthoMatrix(anchoPantalla, altoPantalla, SCREEN_NEAR, SCREEN_DEPTH);
	camara->SetPosition(0.0f, 0.0f, -1.0f);

	//sonido.LoadAsset(L"./Recursos/Wav/201.wav");
	
	int nroMapa = pj->getNroMapa();
	administrador->setMapaActual(nroMapa);

	return true;
}
/*
HWND Grafica::InitializeWindows(int& screenWidth, int& screenHeight)
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

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if (FULL_SCREEN)
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
		screenWidth = 800;
		screenHeight = 600;

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

	// Hide the mouse cursor.
	ShowCursor(false);

	return;
}
*/


bool Grafica::frame()
{


	directx11->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	camara->Update();
	D3DXMATRIX projMatrix = camara->GetOrthoMatrix();
	D3DXMATRIX viewMatrix = camara->GetViewMatrix();
	D3DXMATRIX worldMatrix;
	directx11->GetWorldMatrix(worldMatrix);
	

	double fpss = fps->GetFps();
	

	std::ostringstream strs;
	strs << fpss;
	std::string str = strs.str();
	std::string mensaje = str + " FPS";
	
	directx11->TurnZBufferOff();

	administrador->dibujarRangoMapaActual(pj->getPossX(), pj->getPossY(), projMatrix, viewMatrix, ticksPerFrame,worldMatrix);
	texto->dibujar(mensaje, viewMatrix, projMatrix,worldMatrix);



	directx11->TurnZBufferOn();
	directx11->EndScene();

	
	fps->Frame();
	timer->Frame();
	tiempoTardado = timer->GetTime();
	ticksPerFrame = tiempoTardado * 0.029;

	return true;
}

void Grafica::setKey(int key)
{
	if (!pj->estaCaminando())
	{
		if (key == 37)
		{
			pj->caminarIzquierda();
			administrador->setScrolling();
			//sonido.Play(L"./Recursos/Wav/201.wav");
		}
		else if (key == 39)
		{
			pj->caminarDerecha();
			administrador->setScrolling();
			//sonido.Play(L"./Recursos/Wav/201.wav");
		}
		else if (key == 38)
		{
			pj->caminarArriba();
			administrador->setScrolling();
			//sonido.Play(L"./Recursos/Wav/201.wav");
		}
		else if (key == 40)
		{
			pj->caminarAbajo();
			administrador->setScrolling();
			//sonido.Play(L"./Recursos/Wav/201.wav");
		}
	}

}

bool Grafica::fullScreen()
{
	return FULL_SCREEN;
}

void Grafica::shutDown()
{
	if (directx11)
	{
		directx11->Shutdown();
		delete directx11;
		directx11 = 0;
	}

	if (camara)
	{
		delete camara;
		camara = NULL;
	}

}



Recursos* Grafica::getRecursos()
{
	return recursos;
}

Grafica::~Grafica()
{
}

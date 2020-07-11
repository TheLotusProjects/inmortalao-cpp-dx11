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
	VSYNC_ENABLED = false;
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

bool Grafica::inicializar(int anchoPantallaParam, int altoPantallaParam, HWND hwnd, int anchoResolucion, int altoResolucion)
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

	particula = new DibujadorParticula(directx11,recursos);
	texto = new DibujadorTexto(directx11, recursos);
	texto->cargar(anchoPantalla,altoPantalla);

	camara = new Camara();
	camara->InitializeProjectionMatrix((float)D3DX_PI / 4.0f, (float)anchoPantalla / (float)altoPantalla, SCREEN_NEAR, SCREEN_DEPTH);
	camara->InitializeOthoMatrix(anchoPantalla, altoPantalla, SCREEN_NEAR, SCREEN_DEPTH);
	camara->SetPosition(0.0f, 0.0f, -1.0f);

	return true;
}


bool Grafica::frame()
{
	timer->Frame();
	fps->Frame();

	directx11->BeginScene(0.0f, 0.0f, 0.0f, 0.0f);

	camara->Update();
	
	D3DXMATRIX projMatrix = camara->GetOrthoMatrix();
	D3DXMATRIX viewMatrix = camara->GetViewMatrix();
	D3DXMATRIX worldMatrix;
	directx11->GetWorldMatrix(worldMatrix);


	double fpss = fps->GetFps();
	std::ostringstream strs;
	strs << fpss;
	std::string str = strs.str();
	std::string mensaje = "99999: " + str;

	directx11->TurnZBufferOff();
	directx11->TurnOnAlphaBlending();

	texto->dibujar(mensaje, viewMatrix, projMatrix, worldMatrix);
	particula->dibujar(ticksPerFrame, anchoPantalla / 2.0, altoPantalla / 2.0, viewMatrix, projMatrix, worldMatrix);

	directx11->TurnOffAlphaBlending();
	directx11->TurnZBufferOn();
	directx11->EndScene();


	tiempoTardado = timer->GetTime();
	ticksPerFrame = tiempoTardado * 0.029;

	return true;
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

void Grafica::cargarParticula(int indexParticula)
{
	particula->cargar(indexParticula,anchoPantalla,altoPantalla);
}

Recursos* Grafica::getRecursos()
{
	return recursos;
}

Grafica::~Grafica()
{
}

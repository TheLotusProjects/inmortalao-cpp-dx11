/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "Graphic.h"



Graphic::Graphic()
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

particula* Graphic::getTempParticula()
{
	return particula->getTempParticula();
}

administradorRecursos* Graphic::getAdministrador()
{
	return administrador;
}

void Graphic::move(InputTeclas* input)
{
	
	if (input->IsKeyDown(37)) {
		pj->caminarIzquierda();
		administrador->setScrolling();
	}
	if (input->IsKeyDown(39)) {
		pj->caminarDerecha();
		administrador->setScrolling();
	}
	if (input->IsKeyDown(38)) {
		pj->caminarArriba();
		administrador->setScrolling();
	}
	if (input->IsKeyDown(40)) {
		pj->caminarAbajo();
		administrador->setScrolling();
	}


}

personaje* Graphic::getPj()
{
	return pj;
}

bool Graphic::inicializar(int anchoPantallaParam, int altoPantallaParam, HWND hwnd, int anchoResolucion, int altoResolucion, personaje* pjParam)
{


	anchoPantalla = anchoPantallaParam;
	altoPantalla = altoPantallaParam;

	directx11 = new Directx11();

	bool result = directx11->Initialize(anchoPantalla, altoPantalla, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR, anchoResolucion, altoResolucion);

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
	texto->cargar(anchoPantalla, altoPantalla);

	
	inventory = new Inventory(directx11, recursos);
	inventory->load(anchoPantalla, altoPantalla);

	console = new Console(directx11, recursos);
	console->load(anchoPantalla, altoPantalla);
	

	pj->setParams(recursos, directx11, anchoPantalla, altoPantalla);

	camara = new Camara();
	camara->InitializeProjectionMatrix((float)D3DX_PI / 4.0f, (float)anchoPantalla / (float)altoPantalla, SCREEN_NEAR, SCREEN_DEPTH);
	camara->InitializeOthoMatrix(anchoPantalla, altoPantalla, SCREEN_NEAR, SCREEN_DEPTH);
	camara->SetPosition(0.0f, 0.0f, -1.0f);

	//sonido.LoadAsset(L"./Recursos/Wav/201.wav");

	int nroMapa = pj->getNroMapa();
	administrador->setMapaActual(nroMapa);

	//SetUp ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(directx11->GetDevice(),directx11->GetDeviceContext());
	
	ImGui::StyleColorsLight();


	return true;
}


bool Graphic::frame()
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

	administrador->dibujarRangoMapaActual(pj->getPossX(), pj->getPossY(), projMatrix, viewMatrix, ticksPerFrame, worldMatrix);
	texto->dibujar(mensaje, viewMatrix, projMatrix, worldMatrix);
	
	
	//////////////////////////////////
	//////////////////////////////////

	
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();


	inventory->dibujar(mensaje, viewMatrix, projMatrix, worldMatrix);
	console->dibujar(mensaje, viewMatrix, projMatrix, worldMatrix);

	
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());


	//////////////////////////////////
	//////////////////////////////////

	directx11->TurnZBufferOn();
	directx11->EndScene();

	fps->Frame();
	timer->Frame();
	tiempoTardado = timer->GetTime();
	ticksPerFrame = tiempoTardado * 0.029;

	return true;
}

void Graphic::setKey(int key)
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

bool Graphic::fullScreen()
{
	return FULL_SCREEN;
}

void Graphic::shutDown()
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



Recursos* Graphic::getRecursos()
{
	return recursos;
}

Graphic::~Graphic()
{
}

#pragma once

#include "Camara.h"
#include "DibujadorTexto.h"
#include "DibujadorParticula.h"
#include "personaje.h"
#include "Fps.h"
#include "administradorRecursos.h"
#include "Sonido.h"
#include "InputTeclas.h"
#include "../GUI/Inventory.h"
#include "../GUI/Console.h"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_win32.h"
#include "../ImGui/imgui_impl_dx11.h"

class Graphic
{
public:
	Graphic();
	~Graphic();
	bool inicializar(int anchoPantalla, int altoPantalla, HWND hwnd, int anchoResolucion, int altoResolucion, personaje* pjParam);
	bool frame();
	void shutDown();
	bool fullScreen();
	personaje* getPj();
	Recursos* getRecursos();
	particula* getTempParticula();
	void setKey(int key);
	administradorRecursos* getAdministrador();
	void move(InputTeclas* input);
private:
	bool FULL_SCREEN;
	bool VSYNC_ENABLED;
	float SCREEN_DEPTH;
	float SCREEN_NEAR;
	Directx11* directx11;
	Camara* camara;
	Recursos* recursos;
	Timer* timer;
	Fps* fps;
	DibujadorParticula* particula;
	DibujadorTexto* texto;
	DibujadorTexto* textoPosicion;
	Inventory* inventory;
	Console* console;
	float tiempoTardado, ticksPerFrame;
	int anchoPantalla, altoPantalla;
	personaje* pj;
	administradorRecursos* administrador;
	Grafico* grhPrueba;
	Sonido* sonido;
};


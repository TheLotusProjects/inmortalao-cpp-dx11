#pragma once

#include "Camara.h"

#include "DibujadorTexto.h"
#include "DibujadorParticula.h"

#include "Fps.h"

class Grafica
{
public:
	Grafica();
	~Grafica();
	bool inicializar(int anchoPantalla, int altoPantalla, HWND hwnd, int anchoResolucion, int altoResolucion);
	bool frame();
	void shutDown();
	void cargarParticula(int indexParticula);
	bool fullScreen();
	Recursos* getRecursos();
	particula* getTempParticula();
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
	float tiempoTardado, ticksPerFrame;
	int anchoPantalla, altoPantalla;
};


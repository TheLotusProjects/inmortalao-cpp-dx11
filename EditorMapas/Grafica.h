#pragma once

#include "Camara.h"

#include "DibujadorTexto.h"
#include "DibujadorParticula.h"
#include "personaje.h"
#include "Fps.h"
#include "administradorRecursos.h"

#include "Sonido.h"


class Grafica
{
public:
	Grafica();
	~Grafica();
	bool inicializar(int anchoPantalla, int altoPantalla, HWND hwnd, int anchoResolucion, int altoResolucion,personaje* pjParam);
	bool frame();
	void shutDown();
	bool fullScreen();
	void cargarMapa(int nroMapa);
	personaje* getPj();
	Recursos* getRecursos();
	particula* getTempParticula();
	void setKey(int key);
	administradorRecursos* getAdministrador();
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
	float tiempoTardado, ticksPerFrame;
	int anchoPantalla, altoPantalla;
	personaje* pj;
	administradorRecursos* administrador;
	Grafico* grhPrueba;
	Sonido sonido;
};


#pragma once

#include "personaje.h"
#include "mapa.h"
#include "Recursos.h"
#include "textura.h"
#include "capa1.h"
#include "capa2.h"
#include "capa3.h"
#include "capa4.h"

class administradorRecursos
{
private:
	int nroMapaActual;
	Recursos* recursos;
	mapa* mapaActual;
	capa1* Capa1;
	capa2* Capa2;
	capa3* Capa3;
	capa4* Capa4;
	int nroTrigger,x0,y0;
	int scrollX,scrollY;
	bool pararScrolling;
	personaje* pj;
public:
	administradorRecursos(Recursos* recursosParam, Directx11* directx11, personaje* pjParam);
	void dibujarRangoMapaActual(int x, int y, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, float ticksPerFrame, D3DXMATRIX worldMatrix);
	void dibujarPersonajeActual();
	void dibujarPersonajesRango();
	void dibujarItemsRango();
	void dibujarParticulasRango();
	void dibujarEfectosRango();
	void setScrolling();
	void dibujarTextoRango();
	void setMapaActual(int numeroMapa);
};


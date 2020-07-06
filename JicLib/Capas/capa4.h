#pragma once

#include "Grafico.h"
#include <map>

#define ALPHA_INICIAL 250
#define INCREMENTO_ALPHA_TECHO 10
#define CONTADOR_ALPHA_TECHO 1

class capa4
{
public:
	capa4(Recursos* recursosParam, Directx11* renderParam);
	void dibujar(int x, int y, int nroTrigger, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix);
	void setMapaActual(mapa* mapaActual);
	void preCargaGraficos();
	void controlAphaTecho(int nroTrigger);
	~capa4();
private:
	int nroCapa;
	int alphaInicial = ALPHA_INICIAL;
	int altoVision = 13;
	int anchoVision = 17;
	int contador = 0;
	mapa* mapaActual;
	Recursos* recursos;
	Directx11* directx11;
	void renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix, int nroTrigger);
	std::map <int, Grafico*>* graficos;
};


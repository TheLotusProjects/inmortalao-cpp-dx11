#pragma once

#include "Grafico.h"
#include <map>

class capa2
{
public:
	capa2(Recursos* recursosParam, Directx11* renderParam);
	void dibujar(int x, int y, int nroTrigger, float scrollX, float	 scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix);
	void setMapaActual(mapa* mapaActual);
	void preCargaGraficos();
	~capa2();
private:
	int nroCapa;
	int altoVision = 13;
	int anchoVision = 17;
	mapa* mapaActual;
	Recursos* recursos;
	Directx11* directx11;
	void renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix);
	std::map <int, Grafico*>* graficos;
};


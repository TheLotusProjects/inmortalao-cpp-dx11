/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "Grafico.h"
#include <map>

class capa1
{
public:
	capa1(Recursos* recursosParam, Directx11* directx11Param);
	void dibujar(int x, int y, int nroTrigger, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix);
	void setMapaActual(mapa* mapaActual);
	void preCargaGraficos();
	~capa1();
private:
	int nroCapa;
	int altoVision = 19;//13;
	int anchoVision = 25;//17;
	mapa* mapaActual;
	Recursos* recursos;
	Directx11* directx11;
	void renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix);
	std::map <int, Grafico*>* graficos;
};


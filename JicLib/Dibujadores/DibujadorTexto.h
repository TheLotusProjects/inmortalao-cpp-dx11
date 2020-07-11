/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "Dibujador.h"

class DibujadorTexto : public Dibujador
{
public:
	DibujadorTexto(Directx11* directx11Param, Recursos* recursosParam);
	void dibujar(std::string mensaje, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void cargar(int anchoPantalla,int altoPantalla);
	~DibujadorTexto();
private:
	std::map <int, Grafico*>* texto;
	Recursos* recursos;
	Directx11* directx11;
};


/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "Dibujador.h"

class DibujadorEscudo
{
public:
	DibujadorEscudo(Directx11* directx11Param);
	~DibujadorEscudo();
	void cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo);
	void dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void setCaminar(bool caminar);
	void setDireccion(int direccionParam);
private:
	Directx11* directx11;
	std::map <int, Grafico*>* graficos;
	int direccion;
};


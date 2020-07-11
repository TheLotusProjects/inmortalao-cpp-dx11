/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once

#include "Dibujador.h"

class DibujadorCuerpo : public Dibujador
{
public:
	DibujadorCuerpo(Directx11* directx11Param);
	void cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo);
	void dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix, float framesPerSecond);
	void setCaminar(bool caminar);
	void setDireccion(int direccionParam);
	~DibujadorCuerpo();
private:
	std::map <int, Grafico*>* graficos;
	int direccion;
	Directx11* directx11;
};


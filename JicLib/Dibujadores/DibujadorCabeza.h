/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "Dibujador.h"
#include "lightshaderclass.h"

class DibujadorCabeza
{
public:
	DibujadorCabeza(Directx11* directx11Param);
	void cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo);
	void dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void setDireccion(int direccionParam);
	~DibujadorCabeza();
private:
	Grafico* grafico;
	Directx11* directx11;
	LightShaderClass* m_LightShader;
	std::map<int, Grafico*>* graficos;
	int direccion;
};


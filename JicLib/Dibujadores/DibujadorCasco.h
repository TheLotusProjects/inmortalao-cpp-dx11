#pragma once
#include "Dibujador.h"

class DibujadorCasco
{
public:
	DibujadorCasco(Directx11* directx11Param);
	~DibujadorCasco();
	void cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo);
	void dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void setDireccion(int direccionParam);
private:
	int direccion;
	Grafico* grafico;
	Directx11* directx11;
	std::map<int,Grafico*>* graficos;
};


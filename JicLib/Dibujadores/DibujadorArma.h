#pragma once
#include "Dibujador.h"

class DibujadorArma
{
public:
	DibujadorArma(Directx11* directx11Param);
	~DibujadorArma();
	void cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo);
	void dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void setCaminar(bool caminar);
	void setDireccion(int direccionParam);
private:
	Directx11* directx11;
	std::map <int, Grafico*>* graficos;
	int direccion;
};


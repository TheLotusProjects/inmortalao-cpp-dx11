#pragma once
#include "Dibujador.h"

class DibujadorParticula : public Dibujador
{
public:
	DibujadorParticula(Directx11* directx11Param, Recursos* recursosParam);
	void dibujar(float ticksPerFrame, int x, int y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix);
	void cargar(int indexParticula,int anchoPantalla,int altoPantalla);
	particula* getTempParticula();
	~DibujadorParticula();
private:
	std::map <int, Grafico*>* graficos;
	particula* tempParticula;
	Directx11* directx11;
	Recursos* recursos;
};


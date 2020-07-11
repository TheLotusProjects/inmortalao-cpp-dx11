/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "DibujadorEscudo.h"


DibujadorEscudo::DibujadorEscudo(Directx11* directx11Param)
{
	directx11 = directx11Param;
	graficos = new std::map<int, Grafico*>();
	direccion = SOUTH;
}

void DibujadorEscudo::cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo)
{
	Grafico* grafico;
	for (int i = 1; i <= 4; i++){
		grafico = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
		grafico->setDimensionPantalla(anchoPantalla, altoPantalla);
		int indexCuerpo = recursos->getEscudos()->getGrh(nroCuerpo, NORTH+i-1);
		grafico->InitializeAnimatedSprite(indexCuerpo);
		grafico->ajustarImagen();
		(*graficos)[i] = grafico;
	}
}

void DibujadorEscudo::setDireccion(int direccionParam)
{
	direccion = direccionParam;
}

void DibujadorEscudo::dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix)
{
	(*graficos)[direccion]->setFramesPerSecond(10);
	(*graficos)[direccion]->SetPosition(x, y);
	(*graficos)[direccion]->Update(worldMatrix);
	(*graficos)[direccion]->dibujar(directx11->GetDeviceContext(), viewMatrix, projMatrix);
}

void DibujadorEscudo::setCaminar(bool caminar)
{
	for (int i = 1; i <= 4; i++)
		(*graficos)[i]->setEmpezado(caminar);
}

DibujadorEscudo::~DibujadorEscudo()
{
}

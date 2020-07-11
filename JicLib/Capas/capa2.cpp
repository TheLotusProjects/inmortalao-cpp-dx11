/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "capa2.h"


capa2::capa2(Recursos* recursosParam, Directx11* directx11Param)
{
	recursos = recursosParam;
	directx11 = directx11Param;

	graficos = new std::map<int, Grafico*>();
	nroCapa = 1;
}

void capa2::dibujar(int x0, int y0, int nroTrigger, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix)
{
	int indexGrafico;
	for (int y = -2; y<altoVision+2; y++)
	{
		for (int x = -2; x<anchoVision+2; x++)
		{
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			renderGrafico(indexGrafico, x, y,scrollX,scrollY,projMatrix,viewMatrix,worldMatrix);
		}
	}
}

void capa2::renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix)
{
	if (indexGrafico > 0)
	{
		int cantidadPosicionesX = recursos->GetTileWGrafico(indexGrafico);
		if (cantidadPosicionesX != 1)x = x * 32 - cantidadPosicionesX * (32 / 2) + 32 / 2 +scrollX;
		else{ x = x * 32+scrollX; }
		int cantidadPosicionesY = recursos->GetTileHGrafico(indexGrafico);
		if (cantidadPosicionesY != 1)y = y * 32 - cantidadPosicionesY * 32 + 32 + scrollY;
		else{ y = y * 32 + scrollY; }

		//x = x * 32 + scrollX; y = y * 32 + scrollY;
/*		if (!(graficos->find(indexGrafico) != graficos->end())){
			(*graficos)[indexGrafico] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
			(*graficos)[indexGrafico]->setDimensionPantalla(544, 416);
			(*graficos)[indexGrafico]->definirTextura(indexGrafico);

			(*graficos)[indexGrafico]->InitializeSprite();
		
			(*graficos)[indexGrafico]->ajustarImagen();
		}
	*/	
		
		(*graficos)[indexGrafico]->SetPosition(x, y);
		(*graficos)[indexGrafico]->girar(0.0,worldMatrix);
		(*graficos)[indexGrafico]->dibujar(directx11->GetDeviceContext(), projMatrix, viewMatrix);

	}
}

void capa2::preCargaGraficos()
{

	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x<100; x++)
		{

			int indexGrafico = mapaActual->getIndexGrafico(x, y, 1);

			if (indexGrafico != 0){
				if (!(graficos->find(indexGrafico) != graficos->end())){

					(*graficos)[indexGrafico] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
					(*graficos)[indexGrafico]->setDimensionPantalla(544, 416);
					(*graficos)[indexGrafico]->definirTextura(indexGrafico);

					(*graficos)[indexGrafico]->InitializeSprite();

					(*graficos)[indexGrafico]->ajustarImagen();
				}
			}
		}
	}
}

void capa2::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa2::~capa2()
{
}

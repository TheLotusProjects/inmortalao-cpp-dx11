/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "capa3.h"


capa3::capa3(Recursos* recursosParam, Directx11* directx11Param)
{
	recursos = recursosParam;
	directx11 = directx11Param;
	graficos = new std::map<int, Grafico*>();
	particulas = new std::map<int, DibujadorParticula*>();
	nroCapa = 2;
}

void capa3::dibujar(int x0, int y0, int nroTrigger, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, int ticksPerFrame, D3DXMATRIX worldMatrix)
{
	int indexGrafico, indexGraficoObj, indexGraficoNpc, indexParticle,indexGrhParticle;
	int xParticle, yParticle;
	int tempParticula;
	int ytemp;

	for (int y = -4; y<altoVision+4; y++)
	{
		for (int x = -4; x<anchoVision+4; x++)
		{
			indexGraficoObj = mapaActual->getObjGrhIndex(x0 + x, y0 + y);
			renderGrafico(indexGraficoObj, x, y, scrollX, scrollY, 0 , projMatrix, viewMatrix,worldMatrix);
			
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			renderGrafico(indexGrafico, x, y, scrollX, scrollY, 0, projMatrix, viewMatrix,worldMatrix);
			
			mapaActual->getLightValue(x0 + x, y0 + y);
			
			if (mapaActual->getLuz(x0 + x, y0 + y)>0) {
				int a = 1;
			}

			if (mapaActual->hayParticula(x0 + x, y0 + y))
			{
				tempParticula = mapaActual->getParticula(x0 + x, y0 + y);
				cargarParticula(tempParticula,x,y,scrollX,scrollY,projMatrix,viewMatrix,ticksPerFrame,worldMatrix);
			}
		}
	}
}

void capa3::cargarParticula(int tempParticula, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, int ticksPerFrame, D3DXMATRIX worldMatrix)
{
	if (!(particulas->find(tempParticula) != particulas->end())){
		(*particulas)[tempParticula] = new DibujadorParticula(directx11, recursos);
		(*particulas)[tempParticula]->cargar(tempParticula, 544, 416);
	}

	x = x * 32 + scrollX;
	y = y * 32 + scrollY;

	directx11->TurnOnAlphaBlending();
	(*particulas)[tempParticula]->dibujar(ticksPerFrame, x, y, viewMatrix, projMatrix,worldMatrix);
	directx11->TurnOffAlphaBlending();
}

void capa3::renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, int alpha, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix)
{

	if (indexGrafico > 0)
	{
		int cantidadPosicionesX = recursos->GetTileWGrafico(indexGrafico);
		
		if (cantidadPosicionesX != 1)x = x * 32 - cantidadPosicionesX * (32 / 2) + 32 / 2 + scrollX;
		else{ x = x * 32 + scrollX; }
		
		int cantidadPosicionesY = recursos->GetTileHGrafico(indexGrafico);

		if (cantidadPosicionesY != 1)y = y * 32 - cantidadPosicionesY * 32 + 32 + scrollY;
		else{ y = y * 32 + scrollY; }
		
		
		
/*		if (!(graficos->find(indexGrafico) != graficos->end())){
			(*graficos)[indexGrafico] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
			(*graficos)[indexGrafico]->setDimensionPantalla(544, 416);
			
			
			if (recursos->GetFrameCount(indexGrafico) > 1){
				(*graficos)[indexGrafico]->InitializeAnimatedSprite(1,indexGrafico);
			}
			else{
				(*graficos)[indexGrafico]->definirTextura(indexGrafico);
				(*graficos)[indexGrafico]->InitializeSprite();
			}
			
			(*graficos)[indexGrafico]->ajustarImagen();
		}
	*/	
		
		(*graficos)[indexGrafico]->SetPosition(x, y);
		if (recursos->GetFrameCount(indexGrafico) > 1)
			(*graficos)[indexGrafico]->Update(worldMatrix);
		else
			(*graficos)[indexGrafico]->girar(0.0,worldMatrix);

		(*graficos)[indexGrafico]->dibujar(directx11->GetDeviceContext(), projMatrix, viewMatrix);
	}
}

void capa3::preCargaGraficos()
{
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x<100; x++)
		{

			int indexGrafico = mapaActual->getIndexGrafico(x, y, 2);
			loadGrh(indexGrafico);
			int indexGraficoObj = mapaActual->getObjGrhIndex(x, y);
			loadGrh(indexGraficoObj);

		}
	}
}

void capa3::loadGrh(int indexGrafico)
{
	if (indexGrafico != 0){
		if (!(graficos->find(indexGrafico) != graficos->end())){

			(*graficos)[indexGrafico] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
			(*graficos)[indexGrafico]->setDimensionPantalla(544, 416);


			if (recursos->GetFrameCount(indexGrafico) > 1){
				(*graficos)[indexGrafico]->InitializeAnimatedSprite(indexGrafico,1);
			}
			else{
				(*graficos)[indexGrafico]->definirTextura(indexGrafico);
				(*graficos)[indexGrafico]->InitializeSprite();
			}

			(*graficos)[indexGrafico]->ajustarImagen();

		}
	}
}


void capa3::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa3::~capa3()
{
}

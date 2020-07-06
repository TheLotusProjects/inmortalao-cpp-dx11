#include "capa4.h"


capa4::capa4(Recursos* recursosParam, Directx11* directx11Param)
{
	recursos = recursosParam;
	directx11 = directx11Param;
	graficos = new std::map<int, Grafico*>();
	nroCapa = 3;
}

void capa4::dibujar(int x0, int y0, int nroTrigger, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix)
{
	int indexGrafico;
	for (int y = -4; y<altoVision+4; y++)
	{
		for (int x = -3; x<anchoVision+3; x++)
		{
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			renderGrafico(indexGrafico, x, y,scrollX, scrollY,projMatrix,viewMatrix,worldMatrix, nroTrigger);
		}
	}
	controlAphaTecho(nroTrigger);
}

void capa4::renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix, int nroTrigger)
{
	if (indexGrafico > 0)
	{
		int cantidadPosicionesX = recursos->GetTileWGrafico(indexGrafico);
		if (cantidadPosicionesX != 1)x = x * 32 - cantidadPosicionesX * (32 / 2) + 32 / 2+scrollX;
		else{ x = x * 32 + scrollX; }
		int cantidadPosicionesY = recursos->GetTileHGrafico(indexGrafico);
		if (cantidadPosicionesY != 1)y = y * 32 - cantidadPosicionesY * 32 + 32+scrollY;
		else{ y = y * 32 + scrollY; }

/*		if (!(graficos->find(indexGrafico) != graficos->end())){
			(*graficos)[indexGrafico] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
			(*graficos)[indexGrafico]->setDimensionPantalla(544, 416);
			(*graficos)[indexGrafico]->definirTextura(indexGrafico);
			(*graficos)[indexGrafico]->InitializeSprite();
			(*graficos)[indexGrafico]->ajustarImagen();
		}*/
		
		
		(*graficos)[indexGrafico]->SetPosition(x, y);
		(*graficos)[indexGrafico]->girar(0.0,worldMatrix);
		
		if (nroTrigger > 0) directx11->TurnOnAlphaBlending();
		(*graficos)[indexGrafico]->dibujar(directx11->GetDeviceContext(), projMatrix, viewMatrix, alphaInicial);
		if (nroTrigger > 0) directx11->TurnOffAlphaBlending();
	}
}


void capa4::controlAphaTecho(int nroTrigger)
{
	if (nroTrigger > 0 && alphaInicial >0 && contador == CONTADOR_ALPHA_TECHO){
		alphaInicial -= INCREMENTO_ALPHA_TECHO;
		contador = 0;
	}
	else if (contador == CONTADOR_ALPHA_TECHO && alphaInicial < ALPHA_INICIAL && nroTrigger == 0){ alphaInicial += INCREMENTO_ALPHA_TECHO; contador = 0; }

	if (contador < CONTADOR_ALPHA_TECHO){ contador++; }
	else{ contador = 0; }
}

void capa4::preCargaGraficos()
{
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x<100; x++)
		{
			int indexGrafico = mapaActual->getIndexGrafico(x, y, 3);

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

void capa4::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa4::~capa4()
{
}

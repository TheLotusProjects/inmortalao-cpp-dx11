/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "capa1.h"
#include <vector>

capa1::capa1(Recursos* recursosParam, Directx11* directx11Param)
{
	recursos = recursosParam;
	directx11 = directx11Param;
	graficos = new std::map<int, Grafico*>();
	nroCapa = 0;
}

void capa1::dibujar(int x0, int y0, int nroTrigger, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix)
{
	int indexGrafico;
	//std::vector <long>* index = new std::vector<long>();
	
	for (int y = -10; y < altoVision + 1; y++)
	{
		for (int x = -10; x < anchoVision + 1; x++)
		{
			indexGrafico = mapaActual->getIndexGrafico(x0 + x, y0 + y, nroCapa);
			/*if (indexGrafico > 0)
			{
				index->push_back(indexGrafico);
			}*/
			renderGrafico(indexGrafico, x, y, scrollX, scrollY, projMatrix, viewMatrix, worldMatrix);	
		}
	}
	/*
	for (int i = 0; i< index->size(); i++){
		(*graficos)[(*index)[i]]->dibujar(directx11->GetDeviceContext(), projMatrix, viewMatrix);
	}*/

}

void capa1::renderGrafico(int indexGrafico, float x, float y, float scrollX, float scrollY, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX worldMatrix)
{
	if (indexGrafico > 0)
	{
		x = x * 32 + scrollX; y = y * 32 + scrollY;
		(*graficos)[indexGrafico]->SetPosition(x, y);
		(*graficos)[indexGrafico]->Update(worldMatrix);
		(*graficos)[indexGrafico]->dibujar(directx11->GetDeviceContext(), projMatrix, viewMatrix);
	}
}

void capa1::preCargaGraficos()
{
	
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x<100; x++)
		{
			
				int indexGrafico = mapaActual->getIndexGrafico(x, y, 0);

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
	}


}

void capa1::setMapaActual(mapa* mapaActualParam)
{
	mapaActual = mapaActualParam;
}

capa1::~capa1()
{
}

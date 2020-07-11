/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "DibujadorCabeza.h"


DibujadorCabeza::DibujadorCabeza(Directx11* directx11Param)
{
	directx11 = directx11Param;
	graficos = new std::map<int,Grafico*>();
	direccion = SOUTH;
}

void DibujadorCabeza::cargar(Recursos* recursos, int anchoPantalla, int altoPantalla, int nroCuerpo)
{
	Grafico* grafico;


	for (int i = 1;i<=4;i++)
	{
		grafico = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
		grafico->setDimensionPantalla(anchoPantalla, altoPantalla);
		int indexCuerpo = recursos->getCabezas()->getGrh(nroCuerpo, NORTH+i-1);
		grafico->definirTextura(indexCuerpo);
		grafico->InitializeSprite();
		grafico->ajustarImagen();
		(*graficos)[i] = grafico;
	}

	//m_LightShader = new LightShaderClass;
	//m_LightShader->Initialize(directx11->GetDevice(), directx11->getHwnd());
}

void DibujadorCabeza::setDireccion(int direccionParam)
{
	direccion = direccionParam;
}

void DibujadorCabeza::dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix)
{
	(*graficos)[direccion]->SetPosition(x, y);
	(*graficos)[direccion]->Update(worldMatrix);
	(*graficos)[direccion]->dibujar(directx11->GetDeviceContext(), viewMatrix, projMatrix);


	/*
	D3DXVECTOR4 diffuseColor[1];
	D3DXVECTOR4 lightPosition[1];
	
	diffuseColor[0] = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	lightPosition[0] = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 1.0f);
	m_LightShader->Render(directx11->GetDeviceContext(), 6, grafico->getWorldMatrix(), viewMatrix, projMatrix, grafico->getTextura()->getTextura(), diffuseColor, lightPosition);
	*/
}


DibujadorCabeza::~DibujadorCabeza()
{
}

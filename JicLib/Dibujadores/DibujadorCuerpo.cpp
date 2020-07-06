#include "DibujadorCuerpo.h"


DibujadorCuerpo::DibujadorCuerpo(Directx11* directx11Param)
{
	directx11 = directx11Param;
	graficos = new std::map<int, Grafico*>();
	direccion = SOUTH;
}



void DibujadorCuerpo::cargar(Recursos* recursos,int anchoPantalla,int altoPantalla,int nroCuerpo)
{
	Grafico* tempGrafico;
	for (int i = 1; i <= 4; i++){
		tempGrafico = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
		tempGrafico->setDimensionPantalla(anchoPantalla, altoPantalla);
		int indexCuerpo = recursos->getCuerpos()->getGrh(nroCuerpo,NORTH+i-1);
		tempGrafico->InitializeAnimatedSprite(indexCuerpo);
		tempGrafico->ajustarImagen();
		(*graficos)[i] = tempGrafico;
	}
}

void DibujadorCuerpo::setDireccion(int direccionParam)
{
	direccion = direccionParam;
}

void DibujadorCuerpo::dibujar(float x, float y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix, float framesPerSecond)
{
	(*graficos)[direccion]->setFramesPerSecond(framesPerSecond);
	(*graficos)[direccion]->SetPosition(x, y);
	(*graficos)[direccion]->Update(worldMatrix);
	(*graficos)[direccion]->dibujar(directx11->GetDeviceContext(), viewMatrix, projMatrix);
}

void DibujadorCuerpo::setCaminar(bool caminar)
{
	for (int i = 1; i<=4; i++)
		(*graficos)[i]->setEmpezado(caminar);
}

DibujadorCuerpo::~DibujadorCuerpo()
{
}

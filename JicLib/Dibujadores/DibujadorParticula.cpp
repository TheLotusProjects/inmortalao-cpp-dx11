/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "DibujadorParticula.h"


DibujadorParticula::DibujadorParticula(Directx11* directx11Param, Recursos* recursosParam)
{
	directx11 = directx11Param;
	recursos = recursosParam;
}

void DibujadorParticula::dibujar(float ticksPerFrame, int x, int y, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix)
{
	int indexGrhParticle;
	int xParticle;
	int yParticle;
	double angulo;
	Grafico* grafico;

	if (tempParticula->getAliveCounter())
	{

		float incrementoFrame = tempParticula->getFrameCounter() + ticksPerFrame;
		tempParticula->setFrameCounter(incrementoFrame);

		if (tempParticula->getFrameCounter() > tempParticula->getSpeed()){
			tempParticula->setFrameCounter(0.0);
			tempParticula->setMovement(false);
		}
		else{ tempParticula->setMovement(true); }

		for (int i = 0; i<tempParticula->getNumParticles(); i++){
			tempParticula->dibujar(i);
			indexGrhParticle = tempParticula->getParticleGrhIndex(i);
			yParticle = tempParticula->getParticleY(i);
			xParticle = tempParticula->getParticleX(i);
			angulo = tempParticula->getIndividualAngle(i);


			if (indexGrhParticle > 0){

				(*graficos)[i]->SetPosition(x + xParticle, y + yParticle);
				(*graficos)[i]->girar(angulo,worldMatrix);
				(*graficos)[i]->dibujar(directx11->GetDeviceContext(), viewMatrix, projMatrix);

			}
		}

		if (tempParticula->getMovement())
		{
			if (!tempParticula->getNeverDie())
			{
				tempParticula->decrementarAliveCounter();
			}
		}

	}
}

void DibujadorParticula::cargar(int indexParticula,int anchoPantalla, int altoPantalla)
{
	//if (tempParticula) delete tempParticula;

	tempParticula = recursos->getParticula(indexParticula);
	int indexGrhParticle;

	graficos = new std::map<int, Grafico*>();

	for (int i = 0; i<tempParticula->getNumParticles(); i++){
		if ((*graficos)[i]) delete (*graficos)[i];
		tempParticula->dibujar(i);
		indexGrhParticle = tempParticula->getParticleGrhIndex(i);

		(*graficos)[i] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
		(*graficos)[i]->setDimensionPantalla(anchoPantalla, altoPantalla);
		(*graficos)[i]->definirTextura(indexGrhParticle);
		(*graficos)[i]->InitializeSprite();
		(*graficos)[i]->setColor(tempParticula->getColorInt()[0], tempParticula->getColorInt()[1], tempParticula->getColorInt()[2], tempParticula->getColorInt()[3]);
		(*graficos)[i]->ajustarImagen();
	}
}


particula* DibujadorParticula::getTempParticula()
{
	return tempParticula;
}

DibujadorParticula::~DibujadorParticula()
{
}

/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "administradorRecursos.h"

administradorRecursos::administradorRecursos(Recursos* recursosParam, Directx11* directx11, personaje* pjParam)
{
	recursos = recursosParam;
	pj = pjParam;
	Capa1 = new capa1(recursos, directx11);
	Capa2 = new capa2(recursos, directx11);
	Capa3 = new capa3(recursos, directx11);
	Capa4 = new capa4(recursos, directx11);
	scrollX = 0.0;
	scrollY = 0.0;
}

void administradorRecursos::dibujarRangoMapaActual(int X, int Y, D3DXMATRIX projMatrix, D3DXMATRIX viewMatrix, float ticksPerFrame, D3DXMATRIX worldMatrix)
{
	//El 8 y 6 porque se redondea para abajo
	//(en mitades de pantalla mostrada)
	x0 = X - 8; y0 = Y - 6;
	if (x0 < 0){ x0 = 8 - X; }
	if (y0 < 0){ y0 = 6 - Y; }

	nroTrigger = mapaActual->getTrigger(X, Y);

	if (pj->estaCaminando())
	{
		if (pj->getSentidoX() != 0){
			scrollX = scrollX + pj->getSentidoX() * ticksPerFrame * 5.2;
			if (scrollX <= 0 && pj->getSentidoX() < 0 || scrollX >= 0 && pj->getSentidoX()>0){
				scrollX = 0; pj->setMovimiento(false); pj->setSentidoX(0);
			}
		}
		if (pj->getSentidoY() != 0){
 			scrollY = scrollY + pj->getSentidoY() * ticksPerFrame * 5.2;
			if (scrollY <= 0 && pj->getSentidoY() < 0 || scrollY >= 0 && pj->getSentidoY()>0){
				scrollY = 0; pj->setMovimiento(false); pj->setSentidoY(0);
			}
		}
	}

	Capa1->dibujar(x0,y0, nroTrigger,scrollX,scrollY,projMatrix,viewMatrix,worldMatrix);
	Capa2->dibujar(x0, y0, nroTrigger,scrollX,scrollY,projMatrix,viewMatrix,worldMatrix);
	pj->dibujar(viewMatrix, projMatrix, worldMatrix, ticksPerFrame);
	Capa3->dibujar(x0, y0, nroTrigger, scrollX, scrollY, projMatrix, viewMatrix, ticksPerFrame*10, worldMatrix);
	Capa4->dibujar(x0, y0, nroTrigger,scrollX, scrollY,projMatrix,viewMatrix,worldMatrix);
}

void administradorRecursos::setScrolling()
{
	pj->setMovimiento(true);
	scrollX = 32 * pj->getSentidoX();
	scrollY = 32 * pj->getSentidoY();

	pj->setSentidoX(pj->getSentidoX()*-1);
	pj->setSentidoY(pj->getSentidoY()*-1);
}

void administradorRecursos::dibujarPersonajeActual()
{
}

void administradorRecursos::dibujarPersonajesRango()
{
}

void administradorRecursos::dibujarItemsRango()
{
}

void administradorRecursos::dibujarParticulasRango()
{
}

void administradorRecursos::dibujarEfectosRango()
{
}

void administradorRecursos::dibujarTextoRango()
{
}

void administradorRecursos::setMapaActual(int numeroMapa)
{
	nroMapaActual = numeroMapa;
	mapaActual = recursos->getMapa(numeroMapa);
	Capa1->setMapaActual(mapaActual);
	Capa1->preCargaGraficos();
	Capa2->setMapaActual(mapaActual);
	Capa2->preCargaGraficos();
	Capa3->setMapaActual(mapaActual);
	Capa3->preCargaGraficos();
	Capa4->setMapaActual(mapaActual);
	Capa4->preCargaGraficos();
}


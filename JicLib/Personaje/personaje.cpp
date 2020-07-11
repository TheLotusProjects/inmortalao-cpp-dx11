/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "personaje.h"

personaje::personaje()
{
	possX =40;
	possY = 40;
	nroMapa = 1;

	caminando = false;
}

void personaje::setParams(Recursos* recursos,Directx11* directx11Param, int anchoPantallaParam, int altoPantallaParam)
{
	directx11 = directx11Param;
	anchoPantalla = anchoPantallaParam;
	altoPantalla = altoPantallaParam;

	possXCuerpo= anchoPantalla / 2.0 - 16;
	possYCuerpo= altoPantalla / 2.0 - 16;

	possXCabeza = possXCuerpo + 5;
	possYCabeza = possYCuerpo -8;

	possXArma = possXCuerpo;
	possYArma = possYCuerpo;

	possXEscudo = possXCuerpo;

	possYEscudo = possYCuerpo;

	possXCasco = possXCuerpo+5;
	possYCasco = possYCuerpo-8;

	
	cuerpo = new DibujadorCuerpo(directx11);
	cuerpo->cargar(recursos, anchoPantalla, altoPantalla, 1);
	cuerpo->setCaminar(caminando);

	cabeza = new DibujadorCabeza(directx11);
	cabeza->cargar(recursos, anchoPantalla, altoPantalla, 1);
	
	arma = new DibujadorArma(directx11);
	arma->cargar(recursos, anchoPantalla, altoPantalla, 24);

	escudo = new DibujadorEscudo(directx11);
	escudo->cargar(recursos, anchoPantalla, altoPantalla, 11);

	casco = new DibujadorCasco(directx11);
	casco->cargar(recursos, anchoPantalla, altoPantalla,9);

}

void personaje::caminarArriba()
{
	cuerpo->setDireccion(NORTH);
	cabeza->setDireccion(NORTH);
 	casco->setDireccion(NORTH);
	escudo->setDireccion(NORTH);
	arma->setDireccion(NORTH);
	sentidoY = -1;
	possY--;
}

void personaje::caminarAbajo()
{
	cuerpo->setDireccion(SOUTH);
	cabeza->setDireccion(SOUTH);
	casco->setDireccion(SOUTH);
	escudo->setDireccion(SOUTH);
	arma->setDireccion(SOUTH);
	sentidoY = 1;
	possY++;
}

void personaje::caminarDerecha()
{
	cuerpo->setDireccion(EAST);
	cabeza->setDireccion(EAST);
	casco->setDireccion(EAST);
	escudo->setDireccion(EAST);
	arma->setDireccion(EAST);
	sentidoX = 1;
	possX++;
}

void personaje::caminarIzquierda()
{
	cuerpo->setDireccion(WEST);
	cabeza->setDireccion(WEST);
	casco->setDireccion(WEST);
	escudo->setDireccion(WEST);
	arma->setDireccion(WEST);
	sentidoX = -1;
	possX--;
}

int personaje::getPossX()
{
	return possX;
}

int personaje::getPossY()
{
	return possY;
}

int personaje::getNroMapa()
{
	return nroMapa;
}

void personaje::setNroMapa(int nroMapaParam)
{
	nroMapa= nroMapaParam;
}


void personaje::setSentidoX(int sentidoParam)
{
	sentidoX = sentidoParam;
}

void personaje::setSentidoY(int sentidoParam)
{
	sentidoY = sentidoParam;
}

int personaje::getSentidoX()
{
	return sentidoX;
}

int personaje::getSentidoY()
{
	return sentidoY;
}

bool personaje::estaCaminando()
{
	return caminando;
}

void personaje::dibujar(D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix, float framesPerSecond)
{
	cuerpo->dibujar(possXCuerpo,possYCuerpo,viewMatrix,projMatrix, worldMatrix,framesPerSecond);
	cabeza->dibujar(possXCabeza, possYCabeza, viewMatrix, projMatrix, worldMatrix);
	arma->dibujar(possXArma, possYArma, viewMatrix, projMatrix, worldMatrix);
	escudo->dibujar(possXEscudo, possYEscudo, viewMatrix, projMatrix,worldMatrix);
	casco->dibujar(possXCasco, possYCasco, viewMatrix, projMatrix, worldMatrix);
}

void personaje::setMovimiento(bool caminandoParam)
{
	caminando = caminandoParam;
	cuerpo->setCaminar(caminando);
	arma->setCaminar(caminando);
	escudo->setCaminar(caminando);
}
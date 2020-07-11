/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include "DibujadorCuerpo.h"
#include "DibujadorCasco.h"
#include "DibujadorArma.h"
#include "DibujadorEscudo.h"
#include "DibujadorCabeza.h"

class personaje
{
public:
	personaje();
	int getPossX();
	int getPossY();
	int getNroMapa();
	void setNroMapa(int nroMapaParam);
	int getSentidoX();
	int getSentidoY();
	void setMovimiento(bool caminandoParam);
	bool estaCaminando();
	void caminarArriba();
	void caminarAbajo();
	void caminarDerecha();
	void caminarIzquierda();
	void setSentidoX(int sentidoParam);
	void setSentidoY(int sentidoParam);
	void setParams(Recursos* recursos, Directx11* directx11Param, int anchoPantalla, int altoPantalla);
	void dibujar(D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix, float framesPerSecond);
private:
	int possX;
	int possY;
	int sentidoX;
	int sentidoY;
	bool caminando = false;
	int altoPantalla, anchoPantalla;
	int nroMapa;
	DibujadorCuerpo* cuerpo;
	DibujadorCabeza* cabeza;
	DibujadorArma* arma;
	DibujadorEscudo* escudo;
	DibujadorCasco* casco;
	Directx11* directx11;
	float possXCuerpo, possYCuerpo;
	float possXCasco, possYCasco;
	float possXArma, possYArma;
	float possXEscudo, possYEscudo;
	float possXCabeza, possYCabeza;
};
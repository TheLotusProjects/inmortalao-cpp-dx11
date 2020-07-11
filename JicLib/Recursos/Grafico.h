/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once

#include "Textura.h"
#include "Recursos.h"
#include "AnimatedSprite.h"
#include <math.h>

class Grafico
{
public:
	Grafico(Recursos* recursosParam, ID3D11Device* renderParam, ID3D11DeviceContext* deviceContextParam,float blendParam);
	~Grafico();
	void dibujar(ID3D11DeviceContext* deviceContex, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix,float blendAmount = 0.5f);
	void InitializeSprite();
	void InitializeAnimatedSprite( int indexGrafico, float animationSpeed = 1.0f, bool isLooping = true);
	void Update(D3DXMATRIX worldMatrix);
	void girar(float angulo , D3DXMATRIX worldMatrix);
	void definirTextura(int indexGrafico);
	void SetVelocity(float x, float y);
	void setDimensionPantalla(int anchoPantalla, int altoPantalla);
	void SetPosition(float x, float y);
	void setNumFrames(int indexGrafico);
	void ajustarImagen();
	void setColor(unsigned char* color1Param, unsigned char* color2Param, unsigned char* color3Param, unsigned char* color4Param);
	void setFramesPerSecond(int framesPerSecond);
	void setEmpezado(bool empezado);
	D3DMATRIX getWorldMatrix();
	Textura* getTextura();
private:
	Textura* cargarImagen(int indexGrafico);
	void getDimensionesGrafico(int indexGrafico);
	Textura* cargarGrafico(int numeroGrafico, std::string strNumeroGrafico);
	Recursos* recursos;
	Textura* graficoTextura;
	ID3D11Device* render;
	int Sx, Sy, W,H;
	D3DXVECTOR4 m_position;
	D3DXVECTOR4 m_velocity;
	D3DXMATRIX m_worldMatrix;
	Sprite* m_sprite;
	int numeroGrafico;
	ID3D11DeviceContext* deviceContext;
	float blend;
	int anchoPantalla, altoPantalla;
	int numFrames;
};


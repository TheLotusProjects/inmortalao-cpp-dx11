/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#ifndef _AnimatedSprite_H
#define _AnimatedSprite_H

#include "Sprite.h"
#include "Timer.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(Recursos* recursos, int Sx, int Sy, int grhSpeedParam);
	virtual ~AnimatedSprite(void);
	void setEmpezado(bool empezadoParam);
	void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, Shader* shader, int textureFileName, int numFramesParam);
	void Update();
	void Render(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix);
	void setDimensiones(int W, int H, std::map<int, int>* sXParam , std::map<int, int>* sYParam);
	void setFramePerSecond(int framesPerSecondParam);

private:
	ID3D11DeviceContext* m_deviceContext;
	ini* iniGrafico;
	float m_maxFrames;
	int height, weight;
	std::map<int, int>* sX;
	std::map<int, int>* sY;
	float acumulacionSx, acumulacionSy;
	int framesPerSecond;
	int grhSpeed;
	float m_currentFrame, m_previousFrame;
	float m_currentSpeed;
	bool empezado;
};

#endif
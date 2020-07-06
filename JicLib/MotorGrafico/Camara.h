#ifndef _Camara_H
#define _Camara_H

#include "Directx11.h"

class Camara
{
public:
	Camara(void);
	~Camara(void);

	void InitializeOthoMatrix(int screenWidth, int screenHeight, float screenNear, float screenFar);
	void InitializeProjectionMatrix(float fov, float screenAspect, float screenNear, float screenFar);
	void Update();

	D3DXMATRIX GetViewMatrix();
	D3DXMATRIX GetProjectionMatrix();
	D3DXMATRIX GetOrthoMatrix();

	void SetPosition(float x, float y, float z);

private:
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	D3DXMATRIX m_viewMatrix;
	D3DXMATRIX m_projectionMatrix;
	D3DXMATRIX m_orthoMatrix;
};

#endif
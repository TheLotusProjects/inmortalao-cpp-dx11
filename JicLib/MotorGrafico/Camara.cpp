/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "Camara.h"

Camara::Camara(void)
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;

	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;
}

Camara::~Camara(void)
{
}

void Camara::InitializeOthoMatrix(int screenWidth, int screenHeight, float screenNear, float screenFar)
{
	//XMStoreFloat4x4(&m_orthoMatrix, XMMatrixOrthographicLH((float)screenWidth, (float)screenHeight, screenNear, screenFar));
	D3DXMatrixOrthoLH(&m_orthoMatrix, (float)screenWidth, (float)screenHeight, screenNear, screenFar);
}

void Camara::InitializeProjectionMatrix(float fov, float screenAspect, float screenNear, float screenFar)
{
	//XMStoreFloat4x4(&m_projectionMatrix, XMMatrixPerspectiveFovLH(fov, screenAspect, screenNear, screenFar));
	D3DXMatrixPerspectiveFovLH(&m_projectionMatrix, fov, screenAspect, screenNear, screenFar);
}

void Camara::Update()
{
	D3DXVECTOR3 up;
	D3DXVECTOR3 position;
	D3DXVECTOR3 lookAt;
	float radians;


	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	// Setup the position of the camera in the world.
	position.x = m_positionX;
	position.y = m_positionY;
	position.z = m_positionZ;

	// Calculate the rotation in radians.
	radians = m_rotationY * 0.0174532925f;

	// Setup where the camera is looking.
	lookAt.x = sinf(radians) + m_positionX;
	lookAt.y = m_positionY;
	lookAt.z = cosf(radians) + m_positionZ;

	// Create the view matrix from the three vectors.
	D3DXMatrixLookAtLH(&m_viewMatrix, &position, &lookAt, &up);
}


D3DXMATRIX Camara::GetViewMatrix()
{
	return m_viewMatrix;
}

D3DXMATRIX Camara::GetProjectionMatrix()
{
	return m_projectionMatrix;
}

D3DXMATRIX Camara::GetOrthoMatrix()
{
	return m_orthoMatrix;
}

void Camara::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
}
/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/


#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(Recursos* recursos,int Sx,int Sy,int grhSpeedParam) : Sprite(recursos,Sx,Sy)
{
	grhSpeed = grhSpeedParam;
	empezado = true;
	m_previousFrame = -1;
	m_currentFrame = 0;
	framesPerSecond = 0.0;
	m_currentSpeed = 0.0;
}

AnimatedSprite::~AnimatedSprite(void)
{
}

void AnimatedSprite::setEmpezado(bool empezadoParam)
{
	empezado = empezadoParam;
}

void AnimatedSprite::setDimensiones(int W, int H, std::map<int, int>* sXParam, std::map<int, int>* sYParam)
{
	weight = W;
	height = H;
	sX = sXParam;
	sY = sYParam;
	framesPerSecond = 0.0;
}

void AnimatedSprite::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, Shader* shader, int textureFileName, int numFrames)
{

	m_maxFrames = numFrames;

	Sprite::Initialize(device,deviceContext, shader, textureFileName, weight, height, true);

	m_deviceContext = deviceContext;
}

void AnimatedSprite::setFramePerSecond(int framesPerSecondParam)
{
	if (framesPerSecondParam>=0)
		framesPerSecond = framesPerSecondParam;
}

void AnimatedSprite::Update()
{
	
	
	if (empezado) {
		if (m_currentFrame >= m_maxFrames)
			m_currentFrame = 0;
		else
			m_currentFrame++;
	}
	else 
	{
		m_currentFrame = 0;
	}

	if (m_previousFrame == m_currentFrame) return;


	D3D11_MAPPED_SUBRESOURCE mappedRecursos;
	VertexBuffer::VertexType* vertices = m_vertexBuffer->GetVertices();



	float ancho = ((*sX)[m_currentFrame]) / (float)m_texture->GetWidth();
	float ancho2 = ((*sX)[m_currentFrame] + W - 1) / (float)m_texture->GetWidth();

	float alto = ((*sY)[m_currentFrame]) / (float)m_texture->GetWidth();
	float alto2 = ((*sY)[m_currentFrame] + H - 1) / (float)m_texture->GetHeight();

	/*

	ancho		   ancho2
	alto-----------alto
	|			   |
	|			   |
	|			   |
	|			   |
	ancho----------ancho2
	alto2		   alto2

	*/


	vertices[0].uv.x = ancho;
	vertices[0].uv.y = alto2;

	vertices[1].uv.x = ancho;
	vertices[1].uv.y = alto;

	vertices[2].uv.x = ancho2;
	vertices[2].uv.y = alto;

	vertices[3].uv.x = ancho2;
	vertices[3].uv.y = alto2;
	

	//lock the vertex buffer so it written to
	HRESULT result = m_deviceContext->Map(m_vertexBuffer->GetVertexBuffer(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedRecursos);
	if (FAILED(result))
	{
		return;
	}

	VertexBuffer::VertexType* verticesPtr = (VertexBuffer::VertexType*)mappedRecursos.pData;
	memcpy(verticesPtr, (void*)vertices, sizeof(VertexBuffer::VertexType) * m_vertexBuffer->GetVertexCount());

	m_deviceContext->Unmap(m_vertexBuffer->GetVertexBuffer(), 0);

	//update previous frame
	m_previousFrame = m_currentFrame;
}

void AnimatedSprite::Render(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix)
{
	Sprite::Render(deviceContext, worldMatrix, viewMatrix, projectionMatrix);
}

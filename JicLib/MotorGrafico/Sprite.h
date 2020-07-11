/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#ifndef _Sprite_H
#define _Sprite_H

#include "VertexBuffer.h"
#include "Textura.h"
#include "Shader.h"
#include "Recursos.h"

class Sprite
{
public:
	Sprite(Recursos* recursosParam, int SxParam, int SyParam);
	virtual ~Sprite(void);

	virtual void Initialize(ID3D11Device* device, ID3D11DeviceContext* m_deviceContext, Shader* shader, int textureFileName, int weight, int height, bool isWriteAble = false);
	virtual void Update(){}
	void UpdateASD();
	virtual void Render(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix, float blendAmount = 0.5f);
	void setColor(unsigned char* color1Param, unsigned char* color2Param, unsigned char* color3Param, unsigned char* color4Param);
	Textura* getTexture();
protected:
	VertexBuffer* m_vertexBuffer;
	ID3D11DeviceContext* m_deviceContext;
	Textura* m_texture;
	Shader* m_shader;
	Recursos* recursos;
	float m_size;
	int Sx, Sy;
	int H, W;
	D3DXVECTOR4 color1, color2, color3, color4;
};

#endif
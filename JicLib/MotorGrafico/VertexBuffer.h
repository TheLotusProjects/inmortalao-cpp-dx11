/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include "Shader.h"

class VertexBuffer
{
public:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 uv;
		D3DXVECTOR4 color;
	};

	VertexBuffer(int heightParam, int weightParam);
	~VertexBuffer(void);

	bool Initialize(ID3D11Device* device, Shader* shader, bool writeable = false);
	void Render(ID3D11DeviceContext* deviceContext);

	VertexType* GetVertices();
	ID3D11Buffer* GetVertexBuffer();
	int GetIndexCount();
	int GetVertexCount();

private:
	int height, weight;
	ID3D11Buffer* m_vertexBuffer;
	ID3D11Buffer* m_indexBuffer;
	int m_vertexCount;
	int m_indexCount;
	VertexType* m_vertices;
	Shader* m_shader;
};

#endif
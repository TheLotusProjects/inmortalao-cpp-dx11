#include "Sprite.h"

Sprite::Sprite(Recursos* recursosParam, int SxParam,int SyParam)
{
	m_vertexBuffer = NULL;
	m_texture = NULL;

	Sx = SxParam;
	Sy = SyParam;

	recursos = recursosParam;

	color1= D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	color2 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	color3 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	color4 = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
}

Textura* Sprite::getTexture()
{
	return m_texture;
}

Sprite::~Sprite(void)
{
	if (m_vertexBuffer)
	{
		delete m_vertexBuffer;
		m_vertexBuffer = NULL;
	}
}


void Sprite::Render(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix, float blendAmount)
{
	m_deviceContext = deviceContext;

	if (m_texture)
	{
		//m_shader->SetShaderParamters(deviceContext, m_texture->getTextura());
		m_shader->SetShaderParamters(deviceContext, worldMatrix, viewMatrix, projectionMatrix, m_texture->getTextura(),blendAmount);

		m_vertexBuffer->Render(deviceContext);
	}

}

void Sprite::Initialize(ID3D11Device* device,ID3D11DeviceContext* m_deviceContextParam, Shader* shader, int textureFileName, int weight, int height, bool isWriteAble)
{
	m_shader = shader;

	W = weight, H = height;

	m_deviceContext = m_deviceContextParam;

	//if (!recursos->haveVertexBuffer()){
		m_vertexBuffer = new VertexBuffer(height,weight);
		m_vertexBuffer->Initialize(device, shader, true);
		//recursos->setVertexBuffer(m_vertexBuffer);
	//}
	//else{ m_vertexBuffer = recursos->getVertexBuffer(); }
	

	if (textureFileName != NULL)
	{
		m_texture = recursos->getTexturaGrafico(textureFileName);
	}

}



void Sprite::UpdateASD()
{
	D3D11_MAPPED_SUBRESOURCE mappedRecursos;
	VertexBuffer::VertexType* vertices = m_vertexBuffer->GetVertices();
	

	float ancho, ancho2;
	float alto,alto2;

	ancho = Sx / (float)m_texture->GetWidth();
	ancho2 = (Sx + W) / (float)m_texture->GetWidth();

	alto2 = Sy / (float)m_texture->GetHeight();
	alto = (Sy + H) / (float)m_texture->GetHeight();


	
	vertices[0].uv.x = ancho;
	vertices[0].uv.y = alto;
	vertices[0].color = color1;

	vertices[1].uv.x = ancho;
	vertices[1].uv.y = alto2;
	vertices[1].color = color2;

	vertices[2].uv.x = ancho2;
	vertices[2].uv.y = alto2;
	vertices[2].color = color3;

	vertices[3].uv.x = ancho2;
	vertices[3].uv.y = alto;
	vertices[3].color = color4;


	//lock the vertex buffer so it written to
	HRESULT result = m_deviceContext->Map(m_vertexBuffer->GetVertexBuffer(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedRecursos);
	if (FAILED(result))
	{
		return;
	}

	VertexBuffer::VertexType* verticesPtr = (VertexBuffer::VertexType*)mappedRecursos.pData;
	memcpy(verticesPtr, (void*)vertices, sizeof(VertexBuffer::VertexType) * m_vertexBuffer->GetVertexCount());

	m_deviceContext->Unmap(m_vertexBuffer->GetVertexBuffer(), 0);
}

void Sprite::setColor(unsigned char* color1Param, unsigned char* color2Param, unsigned char* color3Param, unsigned char* color4Param)
{
	color1 = D3DXVECTOR4((int)color1Param[2] / 255.0f, (int)color1Param[1] / 255.0f, (int)color1Param[0] / 255.0f, 1.0f);
	color2 = D3DXVECTOR4((int)color2Param[2] / 255.0f, (int)color2Param[1] / 255.0f, (int)color2Param[0] / 255.0f, 1.0f);
	color3 = D3DXVECTOR4((int)color3Param[2] / 255.0f, (int)color3Param[1] / 255.0f, (int)color3Param[0] / 255.0f, 1.0f);
	color4 = D3DXVECTOR4((int)color4Param[2] / 255.0f, (int)color4Param[1] / 255.0f, (int)color4Param[0] / 255.0f, 1.0f);
}
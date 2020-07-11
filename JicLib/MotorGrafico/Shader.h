/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#ifndef _SHADER_H
#define _SHADER_H


#include "Directx11.h"
#include <fstream>


using namespace std;


class Shader
{
private:
	struct MatrixBufferType
	{
		D3DXMATRIX worldMatrix;
		D3DXMATRIX viewMatrix;
		D3DXMATRIX projectionMatrix;
	};

	struct TransparentBufferType
	{
		float blendAmount;
		D3DXVECTOR3 padding;
	};


	void OutputShadeErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, WCHAR* shaderFileName);
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	string m_name;
	ID3D11Buffer* m_transparentBuffer;

protected:
	virtual bool Initialize(ID3D11Device* device, HWND hwnd, WCHAR* shaderFileName);
	bool m_initialized;

public:
	Shader(ID3D11Device* device, HWND hwnd, WCHAR* shaderFileName);
	virtual ~Shader(void);

	virtual void Begin(ID3D11DeviceContext* deviceContext, int indexCount);
	virtual void End(ID3D11DeviceContext* deviceContext);

	//bool SetShaderParamters(ID3D11DeviceContext* deviceContext, );
	bool SetShaderParamters(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, float blendAmount);

	void cargar(ID3D11Device* device, HWND hwnd, WCHAR* shaderFileName);
	ID3D11SamplerState* m_sampleState;
};

#endif
#include "Textura.h"



Textura::Textura()
{
}

ID3D11ShaderResourceView* Textura::getTextura()
{
	return textura;
}

bool Textura::cargar(ID3D11Device* device,const wchar_t* fileName)
{
	HRESULT result;


	//load the texture
	//result = CreateWICTextureFromFile(device, fileName, NULL, &textura, NULL);
	result = D3DX11CreateShaderResourceViewFromFile(device, fileName, NULL, NULL, &textura, NULL);

	if (FAILED(result))
	{
		return false;
	}

	//get width and height
	ID3D11Resource* resource = 0;
	textura->GetResource(&resource);

	ID3D11Texture2D* texture2D = 0;
	result = resource->QueryInterface(&texture2D);

	if (SUCCEEDED(result))
	{
		D3D11_TEXTURE2D_DESC desc;
		texture2D->GetDesc(&desc);

		m_width = desc.Width;
		m_height = desc.Height;
	}

	texture2D->Release();
	resource->Release();

	return true;

}



int Textura::GetWidth()
{
	return m_width;
}

int Textura::GetHeight()
{
	return m_height;
}

Textura::~Textura()
{
}

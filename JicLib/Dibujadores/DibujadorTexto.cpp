#include "DibujadorTexto.h"


DibujadorTexto::DibujadorTexto(Directx11* directx11Param,Recursos* recursosParam)
{
	directx11 = directx11Param;
	recursos = recursosParam;
}

void DibujadorTexto::dibujar(std::string mensaje, D3DXMATRIX viewMatrix, D3DXMATRIX projMatrix, D3DXMATRIX worldMatrix)
{
	for (int i = 0; i < mensaje.length(); i++)
	{
		char letra = mensaje[i];
		if (letra != 32)
		{
			(*texto)[letra]->SetPosition(5 + i * 8, 8);
			(*texto)[letra]->girar(0.0,worldMatrix);
			(*texto)[letra]->dibujar(directx11->GetDeviceContext(), viewMatrix, projMatrix);
		}
	}
}

void DibujadorTexto::cargar(int anchoPantalla,int altoPantalla)
{
	std::string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&`'*#=[]\"<>{}^~|_@$\\αινσϊ";

	texto = new std::map<int, Grafico*>();

	for (int i = 0; i < caracteres.length(); i++)
	{
		char a = caracteres[i];
		if (a != 32)
		{
			int indexLetra = recursos->getIndexLetra(a);
			(*texto)[a] = new Grafico(recursos, directx11->GetDevice(), directx11->GetDeviceContext(), 0.5);
			(*texto)[a]->setDimensionPantalla(anchoPantalla, altoPantalla);
			(*texto)[a]->definirTextura(indexLetra);
			(*texto)[a]->InitializeSprite();
			(*texto)[a]->ajustarImagen();
		}
	}
}

DibujadorTexto::~DibujadorTexto()
{
}

/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#ifndef _Textura_H
#define _Textura_H


#include "Directx11.h"


class Textura
{
public:
	Textura();
	~Textura();
	bool cargar(ID3D11Device* device, const wchar_t* fileName);
	int GetWidth();
	int GetHeight();
	ID3D11ShaderResourceView* getTextura();
private:
	int m_width;
	int m_height;
	ID3D11ShaderResourceView* textura;
};

#endif
#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"

class cuerpos
{
public:
	cuerpos();
	void cargar();
	int getGrh(int nroCuerpo,int direccion);
	~cuerpos();
private:
	std::map<int, bodydata>* Cuerpos;
};


#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"

class cabezas
{
public:
	cabezas();
	void cargar();
	int getGrh(int nroCuerpo, int direccion);
	~cabezas();
private:
	std::map<int, headdata>* Cabezas;
};


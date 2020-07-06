#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"

class cascos
{
public:
	cascos();
	void cargar();
	int getGrh(int nroCuerpo, int direccion);
	~cascos();
private:
	std::map<int, headdata>* Cascos;
};


#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"
class armas
{
public:
	armas();
	void cargar();
	int getGrh(int nroCuerpo, int direccion);
	~armas();
private:
	std::string getValueArchivo(std::ifstream* archivo);
	std::map <int,weaponanimdata>* Armas;
};


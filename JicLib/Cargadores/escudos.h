/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"


class escudos
{
public:
	escudos();
	void cargar();
	int getGrh(int nroCuerpo, int direccion);
	~escudos();
private:
	std::string getValueArchivo(std::ifstream* archivo);
	std::map<int, shielddata>* Escudos;
};


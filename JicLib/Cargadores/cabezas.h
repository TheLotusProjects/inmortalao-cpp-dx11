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


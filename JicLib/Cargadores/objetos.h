/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include <map>
#include "type.h"
#include <sstream>
#include <fstream>
#include <iostream>

class objetos
{
private:
	std::map<int, localeObj>* Objetos;
public:
	objetos();
	void cargar();
	int getIndexGrh(short int indexObj);
	~objetos();
};


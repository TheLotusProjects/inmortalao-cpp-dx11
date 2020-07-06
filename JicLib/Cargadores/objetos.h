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


#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "type.h"

class fxs
{
public:
	fxs();
	void cargar();
	~fxs();
private:
	std::map<int, fxdata>* Fxs;
};


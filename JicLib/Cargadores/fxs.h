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

class fxs
{
public:
	fxs();
	void cargar();
	~fxs();
private:
	std::map<int, fxdata>* Fxs;
};


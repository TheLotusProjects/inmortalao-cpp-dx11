/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once
#include <map>

class Texto
{
public:
	Texto();
	void cargar();
	int getIndexLetra(int ascii);
	int getIndexSombreLetra(int ascii);
	~Texto();
private:
	std::map<int, int>* fuentes;
	std::map<int, int>* fuentesSombra;
};


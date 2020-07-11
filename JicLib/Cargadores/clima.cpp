/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "clima.h"


clima::clima()
{
}

void clima::cargar()
{
	dia.a = 255;
	dia.b = 255;
	dia.r = 255;
	dia.g = 255;

	noche.a = 255;
	noche.b = 170;
	noche.r = 170;
	noche.g = 170;

	tarde.a = 255;
	tarde.b = 200;
	tarde.r = 230;
	tarde.g = 200;

	maniana.a = 255;
	maniana.b = 230;
	maniana.r = 200;
	maniana.g = 200;
}

clima::~clima()
{
}

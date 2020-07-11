/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#pragma once


struct color
{
	short int a;
	short int b;
	short int r;
	short int g;
};

class clima
{
public:
	clima();
	void cargar();
	~clima();
private:
	color dia;
	color noche;
	color tarde;
	color maniana;
};


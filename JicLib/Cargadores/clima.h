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


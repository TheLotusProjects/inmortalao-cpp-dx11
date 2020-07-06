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


#pragma once
#include "particula.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

class particulas
{
public:
	particulas();
	void cargar();
	int getCantidadParticulas();
	particula* getParticula(int indexParticula);
	~particulas();
private:
	std::string getValueArchivo(std::ifstream* archivo);
	std::map <int, particula*>* Particulas;
	std::string cantidadParticulas;
};


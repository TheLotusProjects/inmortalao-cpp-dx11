#include "escudos.h"


escudos::escudos()
{
	Escudos = new std::map<int, shielddata>();
}

void escudos::cargar()
{

	std::ifstream archivo("./Recursos/Init/escudos.dat");


	std::string linea, numeroArma;

	std::getline(archivo, linea);
	std::getline(archivo, linea);
	std::stringstream stream(linea);
	std::string param;

	std::getline(stream, param, '=');
	std::getline(stream, param, '\n');
	std::string cantidadArmas = param;

	shielddata tempEscudo;

	do
	{
		std::getline(archivo, linea);
		std::stringstream stream(linea);
		std::string param;
		std::getline(stream, param, '[');
		std::getline(stream, param, ']');
		numeroArma = param;

		tempEscudo.shieldwalk[SOUTH].grhindex = atoi(getValueArchivo(&archivo).c_str());
		tempEscudo.shieldwalk[EAST].grhindex = atoi(getValueArchivo(&archivo).c_str());
		tempEscudo.shieldwalk[WEST].grhindex = atoi(getValueArchivo(&archivo).c_str());
		tempEscudo.shieldwalk[NORTH].grhindex = atoi(getValueArchivo(&archivo).c_str());

		(*Escudos)[atoi(numeroArma.c_str())] = tempEscudo;

	} while (cantidadArmas != numeroArma);

	archivo.close();
}

std::string escudos::getValueArchivo(std::ifstream* archivo)
{
	std::string param, linea;
	std::getline(*archivo, linea);
	std::stringstream stream(linea);
	std::getline(stream, param, '=');
	std::getline(stream, param, '\n');
	return param;
}


int escudos::getGrh(int nroCuerpo, int direccion)
{
	return (*Escudos)[nroCuerpo].shieldwalk[direccion].grhindex;
}

escudos::~escudos()
{
}

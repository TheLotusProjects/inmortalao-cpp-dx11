#include "armas.h"


armas::armas()
{
	Armas = new std::map<int, weaponanimdata>();
}


void armas::cargar()
{


	std::ifstream archivo("./Recursos/Init/armas.dat");


	std::string linea, numeroArma;

	std::getline(archivo, linea);
	std::getline(archivo, linea);
	std::stringstream stream(linea);
	std::string param;

	std::getline(stream, param, '=');
	std::getline(stream, param, '\n');
	std::string cantidadArmas = param;

	weaponanimdata weaponTemp;

	do
	{
		std::getline(archivo, linea);
		std::stringstream stream(linea);
		std::string param;
		std::getline(stream, param, '[');
		std::getline(stream, param, ']');
		numeroArma = param;

		weaponTemp.weaponanim[NORTH].grhindex = atoi(getValueArchivo(&archivo).c_str());
		weaponTemp.weaponanim[EAST].grhindex = atoi(getValueArchivo(&archivo).c_str());
		weaponTemp.weaponanim[SOUTH].grhindex = atoi(getValueArchivo(&archivo).c_str());
		weaponTemp.weaponanim[WEST].grhindex = atoi(getValueArchivo(&archivo).c_str());

		(*Armas)[atoi(numeroArma.c_str())] = weaponTemp;

	} while (cantidadArmas != numeroArma);

	archivo.close();
}

int armas::getGrh(int nroCuerpo, int direccion)
{
	return (*Armas)[nroCuerpo].weaponanim[direccion].grhindex;
}

std::string armas::getValueArchivo(std::ifstream* archivo)
{
	std::string param, linea;
	std::getline(*archivo, linea);
	std::stringstream stream(linea);
	std::getline(stream, param, '=');
	std::getline(stream, param, '\n');
	return param;
}

armas::~armas()
{
}

/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "objetos.h"


objetos::objetos()
{
	Objetos = new std::map<int, localeObj>();
}

void objetos::cargar()
{
	std::ifstream ptrArchivo("./Recursos/Init/locale_obj_es.ind");
	std::string linea;

	localeObj tempObj;
	int contador=0;

	while (std::getline(ptrArchivo, linea))
	{
		contador++;
		std::stringstream stream(linea);
		std::string param;

		std::getline(stream, param, '|');
		tempObj.name = param;
		std::getline(stream, param, '|');
		tempObj.grh = atoi(param.c_str());
		std::getline(stream, param, '|');
		tempObj.type = atoi(param.c_str());


		(*Objetos)[contador] = tempObj;
	}

	ptrArchivo.close();
}

int objetos::getIndexGrh(short int indexObj)
{
	return (*Objetos)[indexObj].grh;
}

objetos::~objetos()
{
}

/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "cascos.h"


cascos::cascos()
{
	Cascos = new std::map<int,headdata>();
}


void cascos::cargar()
{
	short int numcascos, tempint;
//Esto es un comentario
	std::ifstream fentrada("./Recursos/Init/cascos.ind", std::ios::in | std::ios::binary);
	//la cabecera 
	fentrada.seekg(255 + 4 + 4);
	fentrada.read(reinterpret_cast<char *>(&numcascos), sizeof(short int));
	
	headdata tempCasco;

	for (int i = 0; i<numcascos; i++){
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempCasco.head[NORTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempCasco.head[EAST].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempCasco.head[SOUTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempCasco.head[WEST].grhindex = tempint;

		(*Cascos)[i] = tempCasco;
	}
	fentrada.close();
}

int cascos::getGrh(int nroCuerpo, int direccion)
{
	return (*Cascos)[nroCuerpo].head[direccion].grhindex;
}

cascos::~cascos()
{
}

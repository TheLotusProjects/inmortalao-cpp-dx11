/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "cuerpos.h"


cuerpos::cuerpos()
{
	Cuerpos = new std::map<int, bodydata>();
}

void cuerpos::cargar()
{
	short int numbodys, tempint;

	std::ifstream fentrada("./Recursos/Init/personajes.ind", std::ios::in | std::ios::binary);
	//la cabecera 
	fentrada.seekg(255 + 4 + 4);
	fentrada.read(reinterpret_cast<char *>(&numbodys), sizeof(short int));
	
	bodydata tempBody;
	
	for (int i = 0; i<numbodys; i++){
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempBody.walk[NORTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempBody.walk[EAST].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempBody.walk[SOUTH].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempBody.walk[WEST].grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempBody.headoffset.x = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempBody.headoffset.y = tempint;

		(*Cuerpos)[i] = tempBody;
	}
	fentrada.close();
}

int cuerpos::getGrh(int nroCuerpo, int direccion)
{
	return (*Cuerpos)[nroCuerpo].walk[direccion].grhindex;
}

cuerpos::~cuerpos()
{

}

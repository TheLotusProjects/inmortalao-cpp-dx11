#include "fxs.h"


fxs::fxs()
{
	Fxs = new std::map<int, fxdata>();
}

void fxs::cargar()
{
	short int numfxs, tempint;

	std::ifstream fentrada("./Recursos/Init/fxs.ind", std::ios::in | std::ios::binary);
	//la cabecera 
	fentrada.seekg(255 + 4 + 4);
	fentrada.read(reinterpret_cast<char *>(&numfxs), sizeof(short int));
	

	fxdata tempFx;

	for (int i = 0; i<numfxs; i++){
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempFx.fx.grhindex = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempFx.offsetx = tempint;
		fentrada.read(reinterpret_cast<char *>(&tempint), sizeof(short int));
		tempFx.offsety = tempint;

		(*Fxs)[i] = tempFx;
	}
	fentrada.close();
}

fxs::~fxs()
{
}

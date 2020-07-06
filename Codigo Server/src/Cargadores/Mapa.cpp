#include "Mapa.h"

Mapa::Mapa()
{

}

Mapa::~Mapa()
{

}


/*
mapa::mapa(int numeroMapaParam)
{
	numeroMapa = numeroMapaParam;
	Objetos = objetosParam;
	Particulas = particulasParam;
	this->cargar();
}

void mapa::crea(){
	mapdata = new tmapblock*[100];
	for (int i = 0; i<100; i++)	mapdata[i] = new tmapblock[100];
};

void mapa::limpia(){
	if (mapdata == NULL) return;
	for (int x = 0; x<100; x++){
		for (int y = 0; y<100; y++){
			memset(&mapdata[x][y], 0, sizeof(tmapblock));
		}
	}
};

void mapa::cargar()
{
	std::stringstream stream;
	std::string strNumeroMapa;
	stream << numeroMapa;
	strNumeroMapa = stream.str();

	this->crea();
	this->limpia();

	std::ifstream fentrada("./Recursos/MapasFormatoFacil/" + strNumeroMapa + ".txt");

	tmapheader encabezadoMapa;
	tmapsize dimensionMapa;
	tmapdat datosMapa;
	tdatosbloqueados* bloqueos;
	short int** capa1;
	tdatosgrh* capa2;
	tdatosgrh* capa3;
	tdatosgrh* capa4;
	tdatostrigger* triggers;
	tdatosluces* luces;
	tdatosparticulas* particulas;
	tdatosobjs* objetos;
	tdatosnpc* npcs;
	

	std::string linea;
	
	////////ENCABEZADO
	std::getline(fentrada, linea);
	encabezadoMapa.numerobloqueados = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numerolayers[0] = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numerolayers[1] = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numerolayers[2] = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numerotriggers = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numeroluces = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numeroparticulas = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numeronpcs = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numeroobjs = atoi(linea.c_str());
	std::getline(fentrada, linea);
	encabezadoMapa.numerote = atoi(linea.c_str());
	////////////////////////////////////////////

	//////////////DIMENSION MAPA
	std::getline(fentrada, linea);
	dimensionMapa.xmax = atoi(linea.c_str());
	std::getline(fentrada, linea);
	dimensionMapa.xmin = atoi(linea.c_str());
	std::getline(fentrada, linea);
	dimensionMapa.ymax = atoi(linea.c_str());
	std::getline(fentrada, linea);
	dimensionMapa.ymin = atoi(linea.c_str());
	///////////////////

	//////////////Datos mapa
	std::getline(fentrada, linea);
	strcpy(datosMapa.map_name,linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.battleMod, linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.backUpMode, linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.restrict_mode, linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.music_number, linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.zone, linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.terrain, linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.ambient, linea.c_str());
	std::getline(fentrada, linea);
	datosMapa.base_light = atoi(linea.c_str());
	std::getline(fentrada, linea);
	datosMapa.graficoLetra = atoi(linea.c_str());
	std::getline(fentrada, linea);
	datosMapa.extra1 = atoi(linea.c_str());
	std::getline(fentrada, linea);
	datosMapa.extra2 = atoi(linea.c_str());
	std::getline(fentrada, linea);
	strcpy(datosMapa.extra3, linea.c_str());
	/////////

	int x, y;
	//////////////////CAPA 1
	for (long j = 0;j<100;j++)
	{
		for (long i = 0;i<100;i++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			std::getline(stream, param, '-');
			std::getline(stream, param, '-');
			mapdata[i][j].graphic[0].grhindex = atoi(param.c_str());
		}
	}
	/////////////////////////

	//////////////BLOQUEOS
	
	if (encabezadoMapa.numerobloqueados > 0)
	{
		bloqueos = new tdatosbloqueados[encabezadoMapa.numerobloqueados];
		for (long j = 0; j<encabezadoMapa.numerobloqueados; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str())-1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str())-1;
			bloqueos[j].x = x;
			bloqueos[j].y= y;
			mapdata[x][y].blocked = 1;
		}
	}
	////////////////

	//////////////CAPA 2
	if (encabezadoMapa.numerolayers[0] > 0)
	{
		capa2 = new tdatosgrh[encabezadoMapa.numerolayers[0]];
		for (long j = 0; j<encabezadoMapa.numerolayers[0]; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			capa2[j].x = x;
			capa2[j].y = y;
			std::getline(stream, param, '-');
			capa2[j].grhindex = atoi(param.c_str());
			mapdata[x][y].graphic[1].grhindex = capa2[j].grhindex;
		}
	}
	////////////////

	//////////////CAPA 3
	if (encabezadoMapa.numerolayers[1]> 0)
	{
		capa3 = new tdatosgrh[encabezadoMapa.numerolayers[1]];
		for (long j = 0; j<encabezadoMapa.numerolayers[1]; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			capa3[j].x = x;
			capa3[j].y = y;
			std::getline(stream, param, '-');
			capa3[j].grhindex = atoi(param.c_str());
			mapdata[x][y].graphic[2].grhindex = capa3[j].grhindex;
		}
	}
	////////////////


	//////////////CAPA 4

	if (encabezadoMapa.numerolayers[2] > 0)
	{
		capa4 = new tdatosgrh[encabezadoMapa.numerolayers[2]];
		for (long j = 0; j<encabezadoMapa.numerolayers[2]; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			capa4[j].x = x;
			capa4[j].y = y;
			std::getline(stream, param, '-');
			capa4[j].grhindex = atoi(param.c_str());
			mapdata[x][y].graphic[3].grhindex = capa4[j].grhindex;
		}
	}
	////////////////


	//////////////TRIGGERS
	if (encabezadoMapa.numerotriggers > 0)
	{
		triggers = new tdatostrigger[encabezadoMapa.numerotriggers];
		for (long j = 0; j<encabezadoMapa.numerotriggers; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			triggers[j].x = x;
			triggers[j].y = y;
			std::getline(stream, param, '-');
			triggers[j].trigger = atoi(param.c_str());
			mapdata[x][y].trigger = triggers[j].trigger;
		}
	}
	////////////////


	//////////////NUMERO PARTICULAS
	if (encabezadoMapa.numeroparticulas > 0)
	{
		particulas = new tdatosparticulas[encabezadoMapa.numeroparticulas];
		for (long j = 0; j<encabezadoMapa.numeroparticulas; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			particulas[j].x = x;
			particulas[j].y = y;
			std::getline(stream, param, '-');
			particulas[j].particula = atoi(param.c_str());

			mapdata[x][y].hayParticula = true;
			mapdata[x][y].Particula = Particulas->getParticula(particulas[j].particula);
		}
	}
	////////////////


	//////////////NUMERO LUCES

	if (encabezadoMapa.numeroluces > 0)
	{
		luces = new tdatosluces[encabezadoMapa.numeroluces];
		for (long j = 0; j<encabezadoMapa.numeroluces; j++)
		{
			if (luces[j].color != 0)
			{
				std::getline(fentrada, linea);
				std::stringstream stream(linea);
				std::string param;
				std::getline(stream, param, '-');
				x = atoi(param.c_str()) - 1;
				std::getline(stream, param, '-');
				y = atoi(param.c_str()) - 1;
				luces[j].x = x;
				luces[j].y = y;
				std::getline(stream, param, '-');
				luces[j].rango = atoi(param.c_str());
				std::getline(stream, param, '-');
				luces[j].color = atoi(param.c_str());
			}
		}
	}
	////////////////


	//////////////NUMERO OBJS
	if (encabezadoMapa.numeroobjs > 0)
	{
		objetos = new tdatosobjs[encabezadoMapa.numeroobjs];
		for (long j = 0; j<encabezadoMapa.numeroobjs; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			objetos[j].x = x;
			objetos[j].y = y;
			std::getline(stream, param, '-');
			objetos[j].objIndex = atoi(param.c_str());
			std::getline(stream, param, '-');
			objetos[j].objAmmount = atoi(param.c_str());
			mapdata[x][y].objgrh.grhindex = Objetos->getIndexGrh(objetos[j].objIndex);
		}
	}
	////////////////

	//////////////NUMERO NPCS
	if (encabezadoMapa.numeronpcs > 0)
	{
		npcs = new tdatosnpc[encabezadoMapa.numeronpcs];
		for (long j = 0; j<encabezadoMapa.numeronpcs; j++)
		{
			std::getline(fentrada, linea);
			std::stringstream stream(linea);
			std::string param;
			std::getline(stream, param, '-');
			x = atoi(param.c_str()) - 1;
			std::getline(stream, param, '-');
			y = atoi(param.c_str()) - 1;
			npcs[j].x = x;
			npcs[j].y = y;
			std::getline(stream, param, '-');
			npcs[j].NpcIndex = atoi(param.c_str());
		}
	}
	////////////////
}

void mapa::guardar(int nroMapa)
{

}

int mapa::getIndexGrafico(int x, int y,int capa)
{
	int indice;
	indice= mapdata[x][y].graphic[capa].grhindex;
	return indice;
}

int mapa::getTrigger(int x, int y)
{
	int trigger;
	trigger = mapdata[x][y].trigger;
	return trigger;
}

////////////////////////////////////////////
		///////////OBJETOS///////
////////////////////////////////////////////

short int mapa::getIndexObj(int x,int y)
{
	short int grhIndexObj;
	grhIndexObj = mapdata[x][y].objinfo.objindex;
	return grhIndexObj;
}

short int mapa::getObjAmount(int x, int y)
{
	return mapdata[x][y].objinfo.amount;
}

unsigned int mapa::getEsFijoObj(int x, int y)
{
	return mapdata[x][y].objinfo.EsFijo;
}

unsigned int mapa::getTipeObj(int x, int y)
{
	return mapdata[x][y].objinfo.tipe;
}

unsigned int mapa::getAngleObj(int x, int y)
{
	return mapdata[x][y].objgrh.angle;
}

unsigned int mapa::getFrameCounterObj(int x, int y)
{
	return mapdata[x][y].objgrh.framecounter;
}

int mapa::getObjGrhIndex(int x, int y)
{
	return mapdata[x][y].objgrh.grhindex;
}

short int mapa::getLoopsObj(int x, int y)
{
	return mapdata[x][y].objgrh.Loops;
}

unsigned int mapa::getSpeedCounterObj(int x, int y)
{
	return mapdata[x][y].objgrh.speedcounter;
}

unsigned int mapa::getStartedObj(int x, int y)
{
	return mapdata[x][y].objgrh.started;
}

////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////

unsigned int mapa::getBlocked(int x, int y)
{
	return mapdata[x][y].blocked;
}

short int mapa::getCharIndex(int x, int y)
{
	return mapdata[x][y].charindex;
}

int* mapa::getColor(int x, int y)
{
	return mapdata[x][y].color;
}

short int mapa::getEffectIndex(int x, int y)
{
	return mapdata[x][y].effectIndex;
}

short int mapa::getFx(int x, int y)
{
	return mapdata[x][y].fx;
}

grh mapa::getFxGrh(int x, int y)
{
	return mapdata[x][y].fxGrh;
}

int* mapa::getLightValue(int x, int y)
{
	return mapdata[x][y].light_value;
}

short int mapa::getLuz(int x, int y)
{
	return mapdata[x][y].luz;
}

short int mapa::getNpcIndex(int x, int y)
{
	return mapdata[x][y].npcindex;
}

particula* mapa::getParticula(int x, int y)
{
	return mapdata[x][y].Particula;
}

worldpos mapa::getTileExit(int x, int y)
{
	return mapdata[x][y].tileexit;
}

bool mapa::hayParticula(int x, int y)
{
	return mapdata[x][y].hayParticula;
}

mapa::~mapa()
{
}
*/

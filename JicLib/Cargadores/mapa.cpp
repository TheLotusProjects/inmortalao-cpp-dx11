#include "mapa.h"


mapa::mapa(int numeroMapaParam, objetos* objetosParam,particulas* particulasParam)
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
		for (int y =0; y<100; y++){
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

	tmapheader encabezadoMapa;
	tmapsize dimensionMapa;
	tmapdat datosMapa;
	int capa1[100][100];
	tdatosgrh* capa2;
	tdatosgrh* capa3;
	tdatosgrh* capa4;
	tdatostrigger* triggers;
	tdatosluces* luces;
	tdatosparticulas* particulas;
	tdatosobjs* objetos;
	tdatosnpc* npcs;


	std::string linea;

	std::ifstream source("./Recursos/Maps/mapa" + strNumeroMapa + ".csm", std::ios_base::binary);
	bool exits = source.good();



	////////ENCABEZADO
	int intBytes;

	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numerobloqueados = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numerolayers[0] = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numerolayers[1] = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numerolayers[2] = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numerotriggers = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numeroluces = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numeroparticulas = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numeronpcs = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numeroobjs = intBytes;
	source.read((char*)&intBytes, sizeof(intBytes));
	encabezadoMapa.numerote = intBytes;

	//////////////DIMENSION MAPA

	short int shortBytes;
	source.read((char*)&shortBytes, sizeof(shortBytes));
	dimensionMapa.xmax = shortBytes;
	source.read((char*)&shortBytes, sizeof(shortBytes));
	dimensionMapa.xmin = shortBytes;
	source.read((char*)&shortBytes, sizeof(shortBytes));
	dimensionMapa.ymax = shortBytes;
	source.read((char*)&shortBytes, sizeof(shortBytes));
	dimensionMapa.ymin = shortBytes;
	///////////////////


	//////////////Datos mapa
	source.read((char*)&datosMapa.map_name, sizeof(datosMapa.map_name));
	source.read((char*)&datosMapa.battleMod, sizeof(datosMapa.battleMod));
	source.read((char*)&datosMapa.backUpMode, sizeof(datosMapa.backUpMode));
	source.read((char*)&datosMapa.restrict_mode, sizeof(datosMapa.restrict_mode));
	source.read((char*)&datosMapa.music_number, sizeof(datosMapa.music_number));
	source.read((char*)&datosMapa.zone, sizeof(datosMapa.zone));
	source.read((char*)&datosMapa.terrain, sizeof(datosMapa.terrain));
	source.read((char*)&datosMapa.ambient, sizeof(datosMapa.ambient));
	source.read((char*)&datosMapa.base_light, sizeof(datosMapa.base_light));
	source.read((char*)&datosMapa.graficoLetra, sizeof(datosMapa.graficoLetra));
	source.read((char*)&datosMapa.extra1, sizeof(datosMapa.extra1));
	source.read((char*)&datosMapa.extra2, sizeof(datosMapa.extra2));
	source.read((char*)&datosMapa.extra3, sizeof(datosMapa.extra3));

	source.read((char*)&capa1, sizeof(capa1));
	
	int x, y;
	//////////////////CAPA 1
	for (long j = 0;j<100;j++)
	{
		for (long i = 0;i<100;i++)
		{
			if (capa1[j][i]>0) {
				mapdata[i][j].graphic[0].grhindex = capa1[j][i];
			}
		}
	}
	/////////////////////////
	


	tdatosbloqueados* bloqueos = new tdatosbloqueados[encabezadoMapa.numerobloqueados];

	//////////////BLOQUEOS
	if (encabezadoMapa.numerobloqueados > 0)
	{
		
		for (long j = 0; j < encabezadoMapa.numerobloqueados; j++)
		{

			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes;

			if (x > 0 || y > 0) {
				bloqueos[j].x = x - 1;
				bloqueos[j].y = y - 1;
				mapdata[x - 1][y - 1].blocked = 1;
			}
		}
	}
	////////////////
	
	
	//////////////CAPA 2
	if (encabezadoMapa.numerolayers[0] > 0)
	{
		capa2 = new tdatosgrh[encabezadoMapa.numerolayers[0]];
		for (long j = 0; j<encabezadoMapa.numerolayers[0]; j++)
		{
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes-1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes-1;

			capa2[j].x = x;
			capa2[j].y = y;

			source.read((char*)&intBytes, sizeof(intBytes));
			capa2[j].grhindex = intBytes;
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
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes - 1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes - 1;

			capa3[j].x = x;
			capa3[j].y = y;
			
			source.read((char*)&intBytes, sizeof(intBytes));
			capa3[j].grhindex = intBytes;
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
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes - 1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes - 1;

			capa4[j].x = x;
			capa4[j].y = y;

			source.read((char*)&intBytes, sizeof(intBytes));
			capa4[j].grhindex = intBytes;
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
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes - 1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes - 1;

			triggers[j].x = x;
			triggers[j].y = y;
			
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int trigger = shortBytes;

			triggers[j].trigger = trigger;
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
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes - 1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes - 1;

			particulas[j].x = x;
			particulas[j].y = y;
			
			source.read((char*)&intBytes, sizeof(intBytes));
			short int particle = intBytes;
			particulas[j].particula = particle;

			mapdata[x][y].hayParticula = true;
			mapdata[x][y].Particula = particulas[j].particula;//Particulas->getParticula(particulas[j].particula);
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

				source.read((char*)&shortBytes, sizeof(shortBytes));
				short int x = shortBytes - 1;
				source.read((char*)&shortBytes, sizeof(shortBytes));
				short int y = shortBytes - 1;

				luces[j].x = x;
				luces[j].y = y;
				
				source.read((char*)&intBytes, sizeof(intBytes));
				int range = intBytes;

				luces[j].rango = intBytes;
				
				char charBytes;
				source.read((char*)&charBytes, sizeof(charBytes));
				luces[j].color = charBytes;
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

			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes - 1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes - 1;


			objetos[j].x = x;
			objetos[j].y = y;


			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int objindex = shortBytes;
			objetos[j].objIndex = objindex;
			
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int objAmmount = shortBytes;
			objetos[j].objAmmount = objAmmount;
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

			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int x = shortBytes - 1;
			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int y = shortBytes - 1;

			npcs[j].x = x;
			npcs[j].y = y;

			source.read((char*)&shortBytes, sizeof(shortBytes));
			short int npcIndex = shortBytes;
			npcs[j].NpcIndex = npcIndex;
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

int mapa::getParticula(int x, int y)
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

char* mapa::getNombre()
{
	return datos.map_name;
}

mapa::~mapa()
{
}

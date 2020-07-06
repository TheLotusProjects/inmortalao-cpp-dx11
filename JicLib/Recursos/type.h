#pragma once
#include "particulas.h"

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4


struct tmapheader{
	int numerobloqueados;
	int numerolayers[3];
	int numerotriggers;
	int numeroluces;
	int numeroparticulas;
	int numeronpcs;
	int numeroobjs;
	int numerote;
};

struct tdatosbloqueados{
	short int x;
	short int y;
};

struct tdatosgrh{
	short int x;
	short int y;
	int grhindex;
};

struct tmapsize{
	short int xmax;
	short int xmin;
	short int ymax;
	short int ymin;
};


struct tmapdat{
	char map_name[64];
	char battleMod;
	char backUpMode;
	char restrict_mode[4];
	char music_number[16];
	char zone[16];
	char terrain[16];
	char ambient[16];
	int base_light;
	int graficoLetra;
	int extra1;
	int extra2;
	char extra3[32];
};

struct grh{
	int grhindex;
	unsigned char framecounter;
	unsigned char speedcounter;
	unsigned char started;
	short int Loops;
	unsigned char angle;
};

struct obj{
	short int objindex;
	short int amount;
	unsigned int tipe;
	unsigned int EsFijo;
};

struct worldpos{
	short int map;
	short int x;
	short int y;
};

struct tmapblock{
	grh graphic[4];
	short int charindex;
	grh objgrh;
	int light_value[4];
	short int luz;
	int color[3];
	int Particula;
	bool hayParticula;
	short int effectIndex;
	short int npcindex;
	obj objinfo;
	worldpos tileexit;
	unsigned char blocked;
	short int fx;
	grh fxGrh;
	short int trigger;
};

struct tdatostrigger{
	short int x;
	short int y;
	short int trigger;
};

struct tdatosparticulas
{
	short int x;
	short int y;
	int particula;
};

struct tdatosluces
{
	short int x;
	short int y;
	int color;
	char rango;
};

struct tdatosobjs
{
	short int x;
	short int y;
	short int objIndex;
	short int objAmmount;
};

struct tdatosnpc
{
	short int x;
	short int y;
	short int NpcIndex;
};

struct weaponanimdata{
	grh weaponanim[8];
	unsigned char weaponattack;
};

struct headdata{
	grh head[8];
};


struct position{
	short int x;
	short int y;
};

struct bodydata{
	grh walk[8];
	position headoffset;
};

struct shielddata{
	grh shieldwalk[8];
};

struct fxdata{
	grh fx;
	int offsetx;
	int offsety;
};

struct localeObj{
	std::string name;
	int type;
	int grh;
};
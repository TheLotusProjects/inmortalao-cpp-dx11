#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string> 

class Mapa
{
public:
	Mapa();
	~Mapa();
};

/*

class mapa
{
public:
	mapa(int numeroMapaParam);

	int getIndexGrafico(int x, int y,int capa);
	int getTrigger(int x, int y);
	short int getIndexObj(int x, int y);
	short int getObjAmount(int x, int y);
	unsigned int getEsFijoObj(int x, int y);
	unsigned int getTipeObj(int x, int y);
	unsigned int getAngleObj(int x, int y);
	unsigned int getFrameCounterObj(int x, int y);
	int getObjGrhIndex(int x, int y);
	short int getLoopsObj(int x, int y);
	unsigned int getSpeedCounterObj(int x, int y);
	unsigned int getStartedObj(int x, int y);
	unsigned int getBlocked(int x, int y);
	short int getCharIndex(int x, int y);
	int* getColor(int x, int y);
	short int getEffectIndex(int x, int y);
	short int getFx(int x, int y);
	grh getFxGrh(int x, int y);
	int* getLightValue(int x, int y);
	short int getLuz(int x, int y);
	short int getNpcIndex(int x, int y);
	particula* getParticula(int x, int y);
	worldpos getTileExit(int x, int y);
	bool hayParticula(int x, int y);
	void guardar(int nroMapa);
	~mapa();
	
private:
	void mapa::crea();
	tmapblock** mapdata;
	particulas* Particulas;
	objetos* Objetos;
	void cargar();
	void limpia();
	int numeroMapa;
};

*/

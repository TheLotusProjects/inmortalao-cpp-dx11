#pragma once
#include <map>
#include <iostream>
#include <fstream>

struct graficoData{
	short int sx;
	short int sy;
	short int filenum;
	short int pixelwidth;
	short int pixelheight;
	float tilewidth;
	float tileheight;
	short int numframes;
	short int* frames;
	short int speed;
};

class ini
{
public:
	ini();
	void cargarIndicesGraficos();
	int getNumeroArchivo(int index);
	int getXindex(int index);
	int getYindex(int index);
	int getWindex(int index);
	int getHindex(int index);
	int getTileW(int index);
	int getTileH(int index);
	int getFrameCount(int index);
	int getIndexFrame(int index, int frame);
	int getGrhSpeed(int index);
	int getCantidadIndexaciones();
	~ini();
private:
	std::map<int, graficoData>* graficosIndex;
};


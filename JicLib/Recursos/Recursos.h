#pragma once


#include "Textura.h"
#include "Shader.h"

#include "ini.h"
#include "mapa.h"
#include "ini.h"
#include "particulas.h"
#include "Texto.h"
#include "clima.h"
#include "cuerpos.h"
#include "cabezas.h"
#include "cascos.h"
#include "fxs.h"
#include "armas.h"
#include "escudos.h"
#include "objetos.h"
#include "VertexBuffer.h"
#include <map>

class Recursos
{
public:
	Recursos(ID3D11Device* dx11DeviceParam, HWND hwndParam);
	Shader* getShader();
	void cargarShader();
	bool cargar();
	mapa* getMapa(int nroMapa);
	int GetGrafico(int index);
	int GetXGrafico(int index);
	int GetYGrafico(int index);
	int GetWGrafico(int index);
	int GetHGrafico(int index);
	int GetTileHGrafico(int index);
	int GetTileWGrafico(int index);
	int GetFrameCount(int index);
	int GetSpeedGrh(int index);
	int getCantidadParticulas();
	int getIndexFrame(int index, int frame);
	int getIndexLetra(int ascii);

	bool haveVertexBuffer(int height,int weight);
	VertexBuffer* getVertexBuffer(int height,int weight);
	void Recursos::setVertexBuffer(VertexBuffer* vtx, int height, int weight);

	int getIndexSombraLetra(int ascii);
	int getCantidadIndexGraficos();
	char* getNombreMapa(int nroMapa);
	bool estaGraficoCargado(int nroGrafico);
	void setGrafico(Textura* grafico, int nroGrafico);
	particula* getParticula(int indexParticula);
	Textura* getTexturaGrafico(int nroGrafico);
	Textura* cargarGrafico(int numeroGrafico, std::string strNumeroGrafico);

	cascos* getCascos();
	cuerpos* getCuerpos();
	cabezas* getCabezas();
	armas* getArmas();
	escudos* getEscudos();
	objetos* getObjetos();

	~Recursos();
private:
	bool cargarMapa(int nroMapa);
	bool cargarIni();
	std::map <int, mapa*>* mapas;
	std::map <int, Textura*>* graficosCargados;
	std::map <tuple<int,int>, VertexBuffer*>* vertexBuffers;
	particulas* Particulas;
	ini* indexGraficos;
	Texto* texto;
	clima* Clima;
	cuerpos* Cuerpos;
	cabezas* Cabezas;
	cascos* Cascos;
	fxs* Fxs;
	armas* Armas;
	escudos* Escudos;
	objetos* Objetos;
	bool cargarArmas();
	bool cargarCabezas();
	bool cargarCascos();
	bool cargarClima();
	bool cargarCuerpos();
	bool cargarEscudos();
	bool cargarFuentes();
	bool cargarFxs();
	bool cargarParticulas();
	HWND hwnd;
	Shader* shader;
	ID3D11Device* dx11Device;
};



/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "Recursos.h"


Recursos::Recursos(ID3D11Device* dx11DeviceParam, HWND hwndParam)
{
	dx11Device = dx11DeviceParam;
	hwnd = hwndParam;

	mapas = new std::map<int, mapa*>();
	graficosCargados = new std::map<int, Textura*>();
	vertexBuffers = new std::map<tuple<int, int>, VertexBuffer*>();
	Particulas = new particulas();
	indexGraficos = new ini();
	texto = new Texto();
	Clima = new clima();
	Cuerpos = new cuerpos();
	Cabezas = new cabezas();
	Cascos = new cascos();
	Fxs = new fxs();
	Armas = new armas();
	Escudos = new escudos();
	Objetos = new objetos();
}

cascos* Recursos::getCascos()
{
	return Cascos;
}

cuerpos* Recursos::getCuerpos()
{
	return Cuerpos;
}

cabezas* Recursos::getCabezas()
{
	return Cabezas;
}

armas* Recursos::getArmas()
{
	return Armas;
}

escudos* Recursos::getEscudos()
{
	return Escudos;
}

objetos* Recursos::getObjetos()
{
	return Objetos;
}

char* Recursos::getNombreMapa(int nroMapa)
{
	return (*mapas)[nroMapa]->getNombre();
}

int Recursos::getIndexSombraLetra(int ascii)
{
	return texto->getIndexSombreLetra(ascii);
}

int Recursos::getIndexLetra(int ascii)
{
	return texto->getIndexLetra(ascii);
}

int Recursos::getCantidadIndexGraficos()
{
	return indexGraficos->getCantidadIndexaciones();
}

int Recursos::getCantidadParticulas()
{
	return Particulas->getCantidadParticulas();
}

void Recursos::cargarShader()
{
	shader = new Shader(dx11Device, hwnd, L"Shaders/texture.fx");
}

Shader* Recursos::getShader()
{
	return shader;
}


mapa* Recursos::getMapa(int nroMapa)
{
	if (!(mapas->find(nroMapa) != mapas->end()))
		cargarMapa(nroMapa);

	return (*mapas)[nroMapa];
}

void Recursos::setGrafico(Textura* grafico,int nroGrafico)
{
	(*graficosCargados)[nroGrafico] = grafico;
}

Textura* Recursos::getTexturaGrafico(int nroGrafico)
{
	return (*graficosCargados)[nroGrafico];
}

bool Recursos::estaGraficoCargado(int nroGrafico)
{
	return (graficosCargados->find(nroGrafico) != graficosCargados->end());
}

bool Recursos::cargar()
{
	cargarShader();
	Objetos->cargar();
	return (cargarIni()&cargarArmas()&cargarCabezas()&cargarCascos()&cargarClima()&cargarCuerpos()&cargarEscudos()&cargarFuentes()&cargarFxs()&cargarParticulas());
}

bool Recursos::cargarMapa(int nroMapa)
{
	try
	{
		mapa* elMapa = new mapa(nroMapa,Objetos,Particulas);
		(*mapas)[nroMapa] = elMapa;
	}
	catch (std::exception error)
	{
		return false;
	}
	
	return true;
}

bool Recursos::cargarIni()
{
	try
	{
		indexGraficos->cargarIndicesGraficos();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarArmas()
{
	try
	{
		Armas->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}
bool Recursos::cargarCabezas()
{
	try
	{
		Cabezas->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}
bool Recursos::cargarCascos()
{
	try
	{
		Cascos->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarClima()
{
	try
	{
		Clima->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarCuerpos()
{
	try
	{
		Cuerpos->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarEscudos()
{
	try
	{
		Escudos->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarFuentes()
{
	try
	{
		texto->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarFxs()
{
	try
	{
		Fxs->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

bool Recursos::cargarParticulas()
{
	try
	{
		Particulas->cargar();
	}
	catch (std::exception error)
	{
		return false;
	}

	return true;
}

int Recursos::GetGrafico(int index)
{
	return indexGraficos->getNumeroArchivo(index);
}

int Recursos::GetXGrafico(int index)
{
	int x=indexGraficos->getXindex(index);
	return x;
}

int Recursos::GetYGrafico(int index)
{
	int y = indexGraficos->getYindex(index);
	return y;
}

int Recursos::GetWGrafico(int index)
{
	return indexGraficos->getWindex(index);
}

bool Recursos::haveVertexBuffer(int height, int weight)
{
	tuple<int, int> tupla(height, weight);

	if (!(*vertexBuffers)[tupla]) return false;
	else return true;
}

void Recursos::setVertexBuffer(VertexBuffer* vtx, int height, int weight)
{
	tuple<int, int> tupla(height, weight);
	(*vertexBuffers)[tupla] = vtx;
}

VertexBuffer* Recursos::getVertexBuffer(int height, int weight)
{
	tuple<int, int> tupla(height, weight);
	return (*vertexBuffers)[tupla];
}

int Recursos::GetHGrafico(int index)
{
	return indexGraficos->getHindex(index);
}

int Recursos::GetTileWGrafico(int index)
{
	return indexGraficos->getTileW(index);
}


int Recursos::GetTileHGrafico(int index)
{
	return indexGraficos->getTileH(index);
}


Textura* Recursos::cargarGrafico(int numeroGrafico, std::string strNumeroGrafico)
{
	Textura* graficoActual;
	if (!estaGraficoCargado(numeroGrafico))
	{
		graficoActual = new Textura();

		std::string path = "./Recursos/Graficos/" + strNumeroGrafico + ".bmp";
		
		std::wstring widestr = std::wstring(path.begin(), path.end());
		
		const wchar_t* wchar = widestr.c_str();

		graficoActual->cargar(dx11Device, wchar);
		setGrafico(graficoActual, numeroGrafico);
	}
	else
	{
		graficoActual = getTexturaGrafico(numeroGrafico);
	}
	return graficoActual;
}

int Recursos::GetFrameCount(int index)
{
	return indexGraficos->getFrameCount(index);
}

int Recursos::GetSpeedGrh(int index)
{
	return indexGraficos->getGrhSpeed(index);
}

int Recursos::getIndexFrame(int index, int frame)
{
	return indexGraficos->getIndexFrame(index, frame);
}

particula* Recursos::getParticula(int indexParticula)
{
	return Particulas->getParticula(indexParticula);
}

Recursos::~Recursos()
{
}

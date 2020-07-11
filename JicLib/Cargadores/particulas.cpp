/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "particulas.h"


particulas::particulas()
{
	Particulas = new std::map <int, particula*>();
}

void particulas::cargar()
{
	std::ifstream archivo("./Recursos/Init/particulas.ini");


	std::string linea,numeroParticula;

	std::getline(archivo, linea);
	std::getline(archivo, linea);
	std::stringstream stream(linea);
	std::string param;

	std::getline(stream, param, '=');
	std::getline(stream, param, '\n');
	cantidadParticulas = param;

	do
	{
		particula* tempParticula = new particula();

		std::getline(archivo, linea);
		std::stringstream stream(linea);
		std::string param;
		std::getline(stream, param, '[');
		std::getline(stream, param, ']');
		numeroParticula = param;

		std::string name = getValueArchivo(&archivo);
		//Nombre
		tempParticula->setName(name);
		//Num Particles
		tempParticula->setNumParticles(atoi(getValueArchivo(&archivo).c_str()));
		//X1
		tempParticula->setX1(atoi(getValueArchivo(&archivo).c_str()));
		//Y1
		tempParticula->setY1(atoi(getValueArchivo(&archivo).c_str()));
		//X2
		tempParticula->setX2(atoi(getValueArchivo(&archivo).c_str()));
		///Y2
		tempParticula->setY2(atoi(getValueArchivo(&archivo).c_str()));
		//Angle
		tempParticula->setAngle(atoi(getValueArchivo(&archivo).c_str()));
		//VecX1
		tempParticula->setVecX1(atoi(getValueArchivo(&archivo).c_str()));
		//VecX2
		tempParticula->setVectX2(atoi(getValueArchivo(&archivo).c_str()));
		//VecY1
		tempParticula->setVecY1(atoi(getValueArchivo(&archivo).c_str()));
		//VecY2
		tempParticula->setVecY2(atoi(getValueArchivo(&archivo).c_str()));
		//Life1
		tempParticula->setLife1(atoi(getValueArchivo(&archivo).c_str()));
		//Life2
		tempParticula->setLife2(atoi(getValueArchivo(&archivo).c_str()));
		//Friction
		tempParticula->setFriction(atoi(getValueArchivo(&archivo).c_str()));
		//Spin
		tempParticula->setSpin(atoi(getValueArchivo(&archivo).c_str()));
		//Spin SpeedL
		tempParticula->setSpinSpeedL(atoi(getValueArchivo(&archivo).c_str()));
		//Spin SpeedH
		tempParticula->setSpinSpeedH(atoi(getValueArchivo(&archivo).c_str()));
		//Grav Strength
		tempParticula->setGravity(atoi(getValueArchivo(&archivo).c_str()));
		//Bounce Strength
		tempParticula->setBounceStrength(atoi(getValueArchivo(&archivo).c_str()));
		//AlphaBlend
		tempParticula->setAlphaBlend(atoi(getValueArchivo(&archivo).c_str()));
		//Gravity
		tempParticula->setGravity(atoi(getValueArchivo(&archivo).c_str()));
		//Xmove
		tempParticula->setXMove(atoi(getValueArchivo(&archivo).c_str()));
		//Ymove
		tempParticula->setYMove(atoi(getValueArchivo(&archivo).c_str()));
		//move_x1
		tempParticula->setMoveX1(atoi(getValueArchivo(&archivo).c_str()));
		//move_x2
		tempParticula->setMoveX2(atoi(getValueArchivo(&archivo).c_str()));
		//move_y1
		tempParticula->setMoveY1(atoi(getValueArchivo(&archivo).c_str()));
		//move_y2
		tempParticula->setMoveY2(atoi(getValueArchivo(&archivo).c_str()));
		//life_counter
		tempParticula->setLifeCounter(atof(getValueArchivo(&archivo).c_str()));
		//speed
		tempParticula->setSpeed(atof(getValueArchivo(&archivo).c_str()));
		//resize
		tempParticula->setGrhResize(atoi(getValueArchivo(&archivo).c_str()));
		//rx
		tempParticula->setGrhResizeX(atoi(getValueArchivo(&archivo).c_str()));
		//ry
		tempParticula->setGrhResizeY(atoi(getValueArchivo(&archivo).c_str()));
		//NumGrhs
		int numGraficos = atoi(getValueArchivo(&archivo).c_str());
		tempParticula->setNumGrh(numGraficos);
		//Grh_List
		std::string graficos = getValueArchivo(&archivo);
		std::stringstream striming(graficos);
		std::string parama;
		int* grhList = new int[numGraficos];
		for (int i = 0;i<numGraficos;i++)
		{
			std::getline(striming, parama, ',');
			grhList[i] = atoi(parama.c_str());
		}
		tempParticula->setGrhList(grhList);

		unsigned char* color1;
		unsigned char* color2;
		unsigned char* color3;
		unsigned char* color4;
		
		color1 = new unsigned char[3];
		color2 = new unsigned char[3];
		color3 = new unsigned char[3];
		color4 = new unsigned char[3];

		unsigned char** colores = new unsigned char*[4];
		
		std::string color;
		
		//ColorSet1
		color = getValueArchivo(&archivo);
		std::stringstream stream0(color);
		std::getline(stream0, param, ',');
		color1[0] = atoi(param.c_str());
		std::getline(stream0, param, ',');
		color1[1] = atoi(param.c_str());
		std::getline(stream0, param, '\n');
		color1[2] = atoi(param.c_str());
		//ColorSet2
		color = getValueArchivo(&archivo);
		std::stringstream stream2(color);
		std::getline(stream2, param, ',');
		color2[0] = atoi(param.c_str());
		std::getline(stream2, param, ',');
		color2[1] = atoi(param.c_str());
		std::getline(stream2, param, '\n');
		color2[2] = atoi(param.c_str());
		//ColorSet3
		color = getValueArchivo(&archivo);
		std::stringstream stream3(color);
		std::getline(stream3, param, ',');
		color3[0] = atoi(param.c_str());
		std::getline(stream3, param, ',');
		color3[1] = atoi(param.c_str());
		std::getline(stream3, param, '\n');
		color3[2] = atoi(param.c_str());
		//ColorSet4
		color = getValueArchivo(&archivo);
		std::stringstream stream4(color);
		std::getline(stream4, param, ',');
		color4[0] = atoi(param.c_str());
		std::getline(stream4, param, ',');
		color4[1] = atoi(param.c_str());
		std::getline(stream4, param, '\n');
		color4[2] = atoi(param.c_str());

		
		colores[0] = color1;
		colores[1] = color2;
		colores[2] = color3;
		colores[3] = color4;

		tempParticula->setColorInt(colores);
		tempParticula->setParticulasIndividuales();

		(*Particulas)[atoi(numeroParticula.c_str())] = tempParticula;

	} while (cantidadParticulas!=numeroParticula);

	archivo.close();
}

particula* particulas::getParticula(int indexParticula)
{
	return (*Particulas)[indexParticula];
}

int particulas::getCantidadParticulas()
{
	return atoi(cantidadParticulas.c_str());
}

std::string particulas::getValueArchivo(std::ifstream* archivo)
{
	std::string param,linea;
	std::getline(*archivo, linea);
	std::stringstream stream(linea);
	std::getline(stream, param, '=');
	std::getline(stream, param, '\n');
	return param;
}

particulas::~particulas()
{
}

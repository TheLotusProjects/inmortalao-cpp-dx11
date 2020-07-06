/*
 * Mapas.h
 *
 *  Created on: 24/03/2015
 *      Author: lotus
 */

#ifndef MAPAS_H_
#define MAPAS_H_
#include "Mapa.h"

class Mapas {
public:
	Mapas();
	void cargar();
	virtual ~Mapas();
private:
	std::map<int,Mapa*>* mapas;
};

#endif /* MAPAS_H_ */

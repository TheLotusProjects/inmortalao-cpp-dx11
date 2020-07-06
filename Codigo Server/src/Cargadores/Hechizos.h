/*
 * Hechizos.h
 *
 *  Created on: 24/03/2015
 *      Author: lotus
 */

#ifndef HECHIZOS_H_
#define HECHIZOS_H_
#include "Hechizo.h"
#include <map>

class Hechizos {
public:
	Hechizos();
	void cargar();
	virtual ~Hechizos();
private:
	std::map<int,Hechizo*>* hechizos;
};

#endif /* HECHIZOS_H_ */

/*
 * Npcs.h
 *
 *  Created on: 24/03/2015
 *      Author: lotus
 */

#ifndef NPCS_H_
#define NPCS_H_
#include <map>
#include "Npc.h"
#include <sstream>
#include <fstream>
#include <iostream>

class Npcs {
public:
	Npcs();
	void cargar();
	virtual ~Npcs();
private:
	std::map<int,Npc*>* npcs;
};

#endif /* NPCS_H_ */

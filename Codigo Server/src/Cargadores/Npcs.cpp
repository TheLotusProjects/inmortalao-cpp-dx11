/*
 * Npcs.cpp
 *
 *  Created on: 24/03/2015
 *      Author: lotus
 */

#include "Npcs.h"

Npcs::Npcs() {
	// TODO Auto-generated constructor stub
	npcs= new std::map<int,Npc*>();
}

void Npcs::cargar()
{
	std::ifstream archivo("./Dat/Npcs.dat");
}

Npcs::~Npcs() {
	// TODO Auto-generated destructor stub
}


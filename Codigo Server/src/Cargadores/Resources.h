/*
 * Resources.h
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_
#include <map>
#include "Mapas.h"
#include "Objs.h"
#include "Npcs.h"
#include "Hechizos.h"
#include "Cuenta.h"
#include "../DB/DataBase.h"


using namespace std;

class Resources {
public:
	Resources();
	void cargar();
	DataBase* baseDeDatos;
	map<string,Cuenta*>* cuentas;
    map<int,string>* objetos;
	virtual ~Resources();
private:
	Npcs* npcs;
	Objs* objs;
	Hechizos* hechizos;
	Mapas* mapas;
};

#endif /* RESOURCES_H_ */

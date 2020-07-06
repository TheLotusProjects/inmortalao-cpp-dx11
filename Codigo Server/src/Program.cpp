/*
 * Program.cpp
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#include "Program.h"

using namespace std;

#include <pthread.h>

Program::Program() {
	recursos = new Resources();
	udp = new UDP(recursos);
}

void Program::run()
{
	cargarRecursos();
	crearConexiones();
}

void Program::crearConexiones()
{
	udp->crearConexiones();
}

void Program::cargarRecursos()
{
	recursos->cargar();
}

Program::~Program() {
	delete(recursos);
	delete(udp);
}

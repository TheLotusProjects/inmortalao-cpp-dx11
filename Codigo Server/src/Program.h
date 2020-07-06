/*
 * Program.h
 *
 *  Created on: 23/03/2015
 *      Author: lotus
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "./Cargadores/Resources.h"
#include "./Conexion/UDPConnection/UDP.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


class Program {
public:
	Program();
	void run();
	virtual ~Program();
private:
	void cargarRecursos();
	void crearConexiones();
	Resources* recursos;
	UDP* udp;
};

#endif /* PROGRAM_H_ */

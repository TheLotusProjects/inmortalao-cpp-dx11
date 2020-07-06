/*
 * Tcp.h
 *
 *  Created on: 10/4/2015
 *      Author: lotus
 */

#ifndef SRC_CONEXION_TCP_H_
#define SRC_CONEXION_TCP_H_

#include "../../Cargadores/Resources.h"
#include "./DataSocket.h"
#include "./ServerSocket.h"
#include <map>
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <string>

#define MAX_CLIENTES 3
#define PUERTO 4050

class Tcp {
public:
	Tcp(Resources* recursosParam);
	void crearConexiones();
	virtual ~Tcp();
private:
	Resources* recursos;
	ServerSocket* serverSocket;
	std::map<int,DataSocket*>* dataSockets;
	void aceptarCliente(DataSocket* dataSocket);
	int cantidadClientesConectados;
	void enviarMensajeCliente(int dataSocketIndex);
};

#endif /* SRC_CONEXION_TCP_H_ */


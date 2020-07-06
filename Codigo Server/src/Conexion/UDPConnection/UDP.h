/*
 * UDP.h
 *
 *  Created on: 10/4/2015
 *      Author: lotus
 */

#ifndef SRC_CONEXION_UDP_H_
#define SRC_CONEXION_UDP_H_

#include "../../Cargadores/Resources.h"
#include "./DataUDPSocket.h"
#include "./ServerUDPSocket.h"

#include <map>
#include <pthread.h>
#include <string.h>
#include <string>
#include <exception>

#include "../Messagin/LogIn.h"
#include "../Messagin/ConnectUser.h"
#include "../../Common/split.h"

#define PUERTO 4050

class UDP {
public:
	UDP(Resources* recursosParam);
	void crearConexiones();
	virtual ~UDP();
private:
	Resources* recursos;
	ServerUDPSocket* serverUDPSocket;
	std::map<int,DataUDPSocket*>* dataUDPSockets;
	std::map<int,Message*>* messages;
	void aceptarCliente(DataUDPSocket* DataUDPSocket);
	int cantidadClientesConectados;
	void enviarMensajeCliente(int DataUDPSocketIndex);
	void createMessages();
};

#endif /* SRC_CONEXION_UDP_H_ */


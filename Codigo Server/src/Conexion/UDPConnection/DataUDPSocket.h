/*
 * DataUDPSocket.h
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#ifndef SRC_CONEXION_DataUDPSocket_H_
#define SRC_CONEXION_DataUDPSocket_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <iostream>

class DataUDPSocket {
public:
	DataUDPSocket();
	bool crear(int);
	virtual ~DataUDPSocket();
	int descriptor;
	sockaddr_in* info;
	socklen_t tam;
	static void * controladorCliente(void *obj);
	int getDescriptor();
	void enviarMensajeCliente(int DataUDPSocketIndex);
};

#endif /* SRC_CONEXION_DataUDPSocket_H_ */

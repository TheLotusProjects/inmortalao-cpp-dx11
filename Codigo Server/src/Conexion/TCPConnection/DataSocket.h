/*
 * DataSocket.h
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#ifndef SRC_CONEXION_DATASOCKET_H_
#define SRC_CONEXION_DATASOCKET_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <pthread.h>

class DataSocket {
public:
	DataSocket();
	bool crear(int);
	virtual ~DataSocket();
	int descriptor;
	sockaddr_in* info;
	socklen_t tam;
	static void * controladorCliente(void *obj);
	int getDescriptor();
	void enviarMensajeCliente(int dataSocketIndex);
};

#endif /* SRC_CONEXION_DATASOCKET_H_ */

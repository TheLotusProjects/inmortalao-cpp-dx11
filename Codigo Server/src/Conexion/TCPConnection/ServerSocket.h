/*
 * ServerSocket.h
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#ifndef SRC_CONEXION_SERVERSOCKET_H_
#define SRC_CONEXION_SERVERSOCKET_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

class ServerSocket {
public:
	ServerSocket(int maxClientesParam,int puertoParam);
	bool crear();
	int getDescriptor();
	virtual ~ServerSocket();
private:
	void inicializar();
	void bindSocket();
	int descriptor;
	sockaddr_in info;
	int maxClientes;
	int puerto;
};

#endif /* SRC_CONEXION_SERVERSOCKET_H_ */

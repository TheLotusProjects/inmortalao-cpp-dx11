/*
 * ServerUDPSocket.h
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#ifndef SRC_CONEXION_ServerUDPSocket_H_
#define SRC_CONEXION_ServerUDPSocket_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>


class ServerUDPSocket {
public:
	ServerUDPSocket(int puertoParam);
	bool crear();
	int getDescriptor();
	virtual ~ServerUDPSocket();
private:
	void inicializar();
	void bindSocket();
	int descriptor;
	struct sockaddr_in server_addr;
	int puerto;
	int on;
};

#endif /* SRC_CONEXION_ServerUDPSocket_H_ */

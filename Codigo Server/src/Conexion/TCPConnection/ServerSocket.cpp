/*
 * ServerSocket.cpp
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#include "ServerSocket.h"

ServerSocket::ServerSocket(int maxClientesParam,int puertoParam) {
	maxClientes = maxClientesParam;
	puerto = puertoParam;
}

bool ServerSocket::crear()
{
	this->inicializar();
	this->bindSocket();

    return true;
}

void ServerSocket::inicializar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0) return;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(puerto);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
}

void ServerSocket::bindSocket()
{
	if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
	        return;

	listen(descriptor,maxClientes);
}

int ServerSocket::getDescriptor()
{
	return this->descriptor;
}

ServerSocket::~ServerSocket() {

}


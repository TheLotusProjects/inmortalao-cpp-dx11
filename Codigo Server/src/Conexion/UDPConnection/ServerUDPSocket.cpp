/*
 * ServerUDPSocket.cpp
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#include "ServerUDPSocket.h"

ServerUDPSocket::ServerUDPSocket(int puertoParam) {
	puerto = puertoParam;
	descriptor = -1;
	on=1;
}

bool ServerUDPSocket::crear()
{
	this->inicializar();
	this->bindSocket();

    return true;
}

void ServerUDPSocket::inicializar()
{
	if ((descriptor = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
	    perror("Socket");
	    exit(1);
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server_addr.sin_zero),8);

	
	//Non blocking
	//Para crear un socket no bloqueante para cada cliente hay que utilizar select() o epoll()
	//https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_72/rzab6/xnonblock.htm
	int rc= ioctl(descriptor, FIONBIO, (char *)&on);
   if (rc < 0)
   {
      perror("ioctl() failed");
      close(descriptor);
      exit(-1);
   }

}

void ServerUDPSocket::bindSocket()
{
	if (bind(descriptor,(struct sockaddr *)&server_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("Bind");
		exit(1);
	}
}

int ServerUDPSocket::getDescriptor()
{
	return this->descriptor;
}

ServerUDPSocket::~ServerUDPSocket() {
	this->descriptor = -1;
}


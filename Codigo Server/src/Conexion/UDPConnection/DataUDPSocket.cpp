/*
 * DataUDPSocket.cpp
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#include "DataUDPSocket.h"
#include <unistd.h>

DataUDPSocket::DataUDPSocket() {
	info = new sockaddr_in();
	tam = sizeof(info);
}

void * DataUDPSocket::controladorCliente(void *obj)
{
    DataUDPSocket *data = (DataUDPSocket*)obj;

    while (true) {

        while (1) {

            std::string mensaje;
            int bytes;
        	char buffer[10] = {0};
            bytes = recv(data->getDescriptor(),buffer,10,0);
            //mensaje.append(buffer,bytes);
            std::cout << buffer << "\n";
            if(bytes < 10)break;
        }

    }

    close(data->getDescriptor());
    pthread_exit(NULL);
}

bool DataUDPSocket::crear(int serverDescriptor)
{
	descriptor = accept(serverDescriptor,(sockaddr*)info,&tam);

	if(descriptor < 0)
        return false;


    return true;
}

void DataUDPSocket::enviarMensajeCliente(int Descriptor)
{
	send(Descriptor,"asd",strlen("asd"),0);
}


int DataUDPSocket::getDescriptor()
{
	return descriptor;
}

DataUDPSocket::~DataUDPSocket() {

}


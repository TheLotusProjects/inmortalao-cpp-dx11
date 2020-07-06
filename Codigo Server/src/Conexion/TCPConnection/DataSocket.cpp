/*
 * DataSocket.cpp
 *
 *  Created on: 13/4/2015
 *      Author: lotus
 */

#include "DataSocket.h"
#include <unistd.h>

DataSocket::DataSocket() {
	info = new sockaddr_in();
	tam = sizeof(info);
}

void * DataSocket::controladorCliente(void *obj)
{
    DataSocket *data = (DataSocket*)obj;

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

bool DataSocket::crear(int serverDescriptor)
{
	descriptor = accept(serverDescriptor,(sockaddr*)info,&tam);

	if(descriptor < 0)
        return false;


    return true;
}

void DataSocket::enviarMensajeCliente(int Descriptor)
{
	send(Descriptor,"asd",strlen("asd"),0);
}


int DataSocket::getDescriptor()
{
	return descriptor;
}

DataSocket::~DataSocket() {

}


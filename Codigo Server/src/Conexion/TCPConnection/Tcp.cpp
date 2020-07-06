/*
 * Tcp.cpp
 *
 *  Created on: 10/4/2015
 *      Author: lotus
 *
 * 	La funcion de esta clase es la de aceptar y almacenar las conexiones de los clientes y generar threads
 * 	a cada cliente que se vaya aceptando.
 */

#include "Tcp.h"



Tcp::Tcp(Resources* recursosParam) {
	recursos=recursosParam;
	dataSockets= new std::map<int,DataSocket*>();
	serverSocket = new ServerSocket(MAX_CLIENTES,PUERTO);
	cantidadClientesConectados=0;
}

void Tcp::crearConexiones()
{
	serverSocket->crear();

	while (true) {
		DataSocket* dataSocket = new DataSocket();

		std::cout << "Esperando conexiones...\n";

		if (dataSocket->crear(serverSocket->getDescriptor()))
			aceptarCliente(dataSocket);
		else
			delete(dataSocket);

		//dataSocket->enviarMensajeCliente(dataSocket->getDescriptor());

	}


}

void Tcp::aceptarCliente(DataSocket* dataSocket)
{
	(*dataSockets)[cantidadClientesConectados]=dataSocket;

	pthread_t hilo;
	pthread_create(&hilo,0,DataSocket::controladorCliente,(void *)dataSocket);
	pthread_detach(hilo);

	cantidadClientesConectados++;
}


Tcp::~Tcp()
{
	delete(serverSocket);

	int cantDataSockets=dataSockets->size();

	for (int indexDataSocket=0;indexDataSocket<cantDataSockets;indexDataSocket++)
	{
		delete((*dataSockets)[indexDataSocket]);
	}
}


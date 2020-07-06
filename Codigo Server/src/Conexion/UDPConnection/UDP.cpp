/*
 * UDP.cpp
 *
 *  Created on: 10/4/2015
 *      Author: lotus
 *
 * 	La funcion de esta clase es la de aceptar y almacenar las conexiones de los clientes y generar threads
 * 	a cada cliente que se vaya aceptando.
 * 
 * 
 * Update: 28/10/2016
 * 
 * 	La idea de los mensajes va a ser que la estructura sea la siguiente
 * 
 * 		"HeaderMensaje:Datos"
 * 
 * 	En donde 'HeaderMensaje' vendria a ser el encabezado del tipo de mensaje
 * 	el cual se quiere llegar, ejemplo "LogIn"
 * 
 * 	Datos: Los datos respectivos a ese header, obviamente puede tener mas separadores por dentro del tipo
 * 	':'
 * 
 */

#include "UDP.h"



UDP::UDP(Resources* recursosParam) {
	recursos=recursosParam;
	dataUDPSockets= new std::map<int,DataUDPSocket*>();
	
	messages = new std::map<int,Message*>();
	
	serverUDPSocket = new ServerUDPSocket(PUERTO);
	cantidadClientesConectados=0;
}


void UDP::createMessages()
{
	Message* nuevoMensaje;
	Message* connectUser;

	nuevoMensaje = new LogIn();
	nuevoMensaje->setRecursos(recursos);
	(*messages)[nuevoMensaje->getHeader()] = nuevoMensaje;

	connectUser = new ConnectUser();
	connectUser->setRecursos(recursos);
	(*messages)[connectUser->getHeader()] = connectUser;
}


void UDP::crearConexiones()
{
	this->createMessages();
	
	serverUDPSocket->crear();
	int descriptor = serverUDPSocket->getDescriptor();
	struct sockaddr_in  client_addr;

	int bufferSize = 10240;

	char* recv_data = (char*)malloc(sizeof(char) * bufferSize);
	char* send_data = (char*)malloc(sizeof(char) * bufferSize);
	
	socklen_t addr_len;

	int bytes_read;

	addr_len = sizeof(struct sockaddr);
	printf("IinmortalAO abre en puerto 5000\n");
	fflush(stdout);


	send_data[0]='\0';

	while(1){

		bytes_read = recvfrom(descriptor,recv_data,bufferSize,0,(struct sockaddr *)&client_addr, &addr_len);

		int lenght = strlen(recv_data);

		if (lenght>0 || recv_data[1]!=0){

			//printf("\n(%s , %d) said : ",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
			printf("%d,%d,%d\n", recv_data[0],recv_data[1],recv_data[2]);

			int header = recv_data[0];

			string identifier = std::to_string((int)ntohs(client_addr.sin_port));

			std::string respuesta;

			if (messages->count(header)){
				Message* mensaje=(*messages)[header];
				respuesta = mensaje->action(recv_data,identifier);
			}
			else
			{
				respuesta="No existe el mensaje solicitado";
			}

			sendto(descriptor,respuesta.c_str(),respuesta.size(),0,(struct sockaddr *)&client_addr,sizeof(struct sockaddr));
			
			recv_data[0]='\0';
			recv_data[1]='\0';
			send_data[0]='\0';
		}

		fflush(stdout);
	}


}




UDP::~UDP()
{
	delete(serverUDPSocket);

	int cantDataUDPSockets=dataUDPSockets->size();

	for (int indexDataUDPSocket=0;indexDataUDPSocket<cantDataUDPSockets;indexDataUDPSocket++)
	{
		delete((*dataUDPSockets)[indexDataUDPSocket]);
	}
}


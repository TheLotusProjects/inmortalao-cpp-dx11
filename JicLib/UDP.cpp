#include "UDP.h"
#pragma comment( lib, "wsock32.lib" )

#include <winsock2.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

UDP::UDP()
{
	WSACleanup();
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData); //== NO_ERROR;


	typedef int socklen_t;
	socklen_t sin_size;

	int sock, bytes_recv;
	struct sockaddr_in server_addr;
	struct hostent *host;
	
	int bufferSize = 1024;
	char* send_data = (char*)malloc(sizeof(char)* bufferSize);
	char* recv_data = (char*)malloc(sizeof(char)* bufferSize);

	host = (struct hostent *) gethostbyname((char *)"192.168.1.110");


	if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		perror("socket");
		exit(1);
	}


	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5000);
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	
	sin_size = sizeof(struct sockaddr);
	memset(&(server_addr.sin_zero), 8,sin_size);

	u_long on = 1;
	int rc = ioctlsocket(sock, FIONBIO, &on);
	
	if(rc<0)
	{
		perror("asad");
		
		exit(-1);
	}

	send_data[0] = '\0';
	
	//strcpy(send_data, "0:1");

	fflush(stdout);

	
	while (1)
	{
		//gets(send_data);
		
		//strcpy(send_data, "0:1");


		sendto(sock, send_data, strlen(send_data), 0, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
		
		bytes_recv = recvfrom(sock, recv_data, bufferSize, 0, (struct sockaddr *)&server_addr, &sin_size);
		recv_data[bytes_recv] = '\0';
		printf("Recibido: %s \n", recv_data);


		send_data[0] = '\0';
		recv_data[0] = '\0';

		fflush(stdout);
	}

}


UDP::~UDP()
{
	//closesocket(socket);
}

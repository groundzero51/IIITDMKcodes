//written by Gaurav R
//cs20b1021
//client side code for stop and wait protocol

#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int c_socket;

char arr[100];
int arr_size;

int ClientCreate(int port, int anyip)		// Return 1 for error
{
	c_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in client;
	memset(&client, 0, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_port = htons(port);
	client.sin_addr.s_addr = INADDR_ANY;
	if(connect(c_socket, (struct sockaddr *)&client, sizeof(client)) == -1)
	{
		printf("Connection Issue.\n");
		return 1;
	}
	else return 0;
}

int main()
{

	int exit = 0;

	while(exit == 0)
	{
		int port = 9901;		//enter port here

		int error = ClientCreate(port, 0);
		if(error == 1)
		{
			close(c_socket);
			printf("Connection Issue.\n");
			//return 0;
		}
		else 
		{
			char data[100];
			printf("Enter data to send(without space): ");
			scanf("%s", data);

			char ack[2];
			ack[0] = '1';
			ack[1] = '\0';

			char buf[2];
			buf[0] = '1';
			buf[1] = '\0';

			char exit[2];
			exit[0] = '0';
			exit[1] = '\0';

			int index = 0;
			while(index < strlen(data))
			{
				printf("Sending: %c\n", data[index]);
				buf[0] = data[index];
				send(c_socket, exit, sizeof(exit), 0);
				send(c_socket, buf, sizeof(buf), 0);
				recv(c_socket, ack, sizeof(ack), 0);
				printf("ACK: %s\n", ack);
				if(ack[0] == '1') index++;
			}
			exit[0] = '1';
			send(c_socket, exit, sizeof(exit), 0);

			//close(c_socket);
		}

		printf("Do you want to exit (input 0 to send message again): ");
		scanf("%d", &exit);

		if(exit != 0)
		{
			char exit_str[] = "/exit";
			send(c_socket, exit_str, sizeof(exit_str), 0);
			send(c_socket, exit_str, sizeof(exit_str), 0);
		}

		close(c_socket);
	}

	printf("\n\n");	
	return 0;
}
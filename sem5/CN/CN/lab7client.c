//
// Created by Gaurav Ramrakhiyani on 30/08/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char PHn[100];// = "Gaurav's phone number : 9892572776\n";
    printf("Enter Phone number : ");
    fgets(PHn,100,stdin);
    int c_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in client;
    memset(&client, 0, sizeof(client)); // memset is used to set/change memory within a range
    client.sin_family = AF_INET;
    client.sin_port = htons(9009);
    client.sin_addr.s_addr = INADDR_ANY;
    if (connect(c_socket, (struct sockaddr *)&client, sizeof(client)) == -1)
    {
        printf("Connection Issue.\n");
        return 0;
    }
    send(c_socket, PHn, sizeof(PHn), 0);
    recv(c_socket, PHn, sizeof(PHn), 0);

    printf("OTP from Server : %s\n", PHn);
    close(c_socket);
    return 0;
}
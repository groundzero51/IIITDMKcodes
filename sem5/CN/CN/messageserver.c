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
    int s_socket, s_server;
    char OTP[100] = "OTP for Gaurav : 886975\n";
    s_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server, other;
    memset(&server, 0, sizeof(server)); //memset is used to set/change memory within a range
    memset(&other, 0, sizeof(other));

    server.sin_family = AF_INET;
    server.sin_port = htons(9009);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(s_socket, (struct sockaddr *)&server, sizeof(server)) != -1)
    {
        printf("\nNo errors in bind.\n");
        listen(s_socket, 5);
        socklen_t add;
        add = sizeof(other);
        s_server = accept(s_socket, (struct sockaddr *)&other, &add);
        send(s_server, OTP, sizeof(OTP), 0);
        recv(s_server, OTP, sizeof(OTP), 0);
        printf("Phone number from client : %s\n", OTP);
        while (1) //for infinite messaging between terminals
        {
            send(s_server, OTP, sizeof(OTP), 0);
            recv(s_server, OTP, sizeof(OTP), 0);
            printf("Message from client : %s\n", OTP);
            if (OTP[0] == 'Q')
                break;
        }
        close(s_server);
        close(s_socket);
        return 0;
    }
    else
        printf("\nError in Bind.\n");
    close(s_server);
    close(s_socket);

    return 0;
}
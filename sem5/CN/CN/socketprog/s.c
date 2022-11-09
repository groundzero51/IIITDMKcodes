// B MAHIDHAR REDDY
// CS20B1091

// C PROGRAM TO IMPLIMENT SOCKET PROGRAMMING IN C FOR SERVER SIDE for goback n

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{

    char *ip = "127.0.0.1"; // Define the respective IP address and port_no on which you want to run the code.
    int port_no = 1111;

    int socket_server, socket_client; // Socket file descriptor.

    struct sockaddr_in server_addr, client_addr; // Socket addresses.

    socklen_t addr_size; // Used to define socket related parameters.

    int buffer[1024]; // Create a buffer to store the message.

    socket_server = socket(AF_INET, SOCK_STREAM, 0); // Create the server socket.

    if (socket_server < 0)
    {
        printf("[-]--> Socket creation failed.\n"); // Validate the creation of server socket.
        exit(1);
    }
    printf("[+]--> TCP Socket creation successful in server.\n");

    memset(&server_addr, '\0', sizeof(server_addr)); // Clear out the server address and assign the address settings.
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port_no;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    int n = bind(socket_server, (struct sockaddr *)&server_addr, sizeof(server_addr)); // Bind the server socket to its address (IP Address & port_no)

    if (n < 0)
    {
        printf("[-]--> Bind unsuccessful.\n"); // Validate the binding.
        exit(1);
    }
    printf("[-]---> Binded successfully to port_no %d.\n", port_no);

    listen(socket_server, 5);
    printf("Listening to port_no %d...\n", port_no);

    while (1)
    {
        // Receive the messages from client while it keeps sending.

        addr_size = sizeof(client_addr); // Create the Client socket and connect to it.
        socket_client = accept(socket_server, (struct sockaddr *)&client_addr, &addr_size);
        printf("[+]---> Client connected.\n");

        bzero(buffer, 1024);                            // Message from client. initializing the array with zero
        recv(socket_client, buffer, sizeof(buffer), 0); // recieving the array and storing in buffer
        printf("Client : \n");

        printf("total no bits transfered including dup is : %d\n", buffer[0] - 1);
        printf("frames that are send from client are : ");
        // printing all the bits
        for (int i = 1; i < buffer[0]; i++)
        {
            printf(" %d ", buffer[i]);
        }

        // send the frames that are not accepted in the client side
        int buffer1[1024];
        int j = 1;
        for (int i = 2; i < buffer[0]; i++)
        {
            if (buffer[i] <= buffer[i - 1])
            {
                buffer1[j++] = buffer[i];
            }
            buffer1[0] = j;
        }

        send(socket_client, buffer1, sizeof(buffer1), 0);

        close(socket_client); // Close the connection with client.
        printf("\n[+]--->Client disconnected.\n");
    }

    return (0);
}

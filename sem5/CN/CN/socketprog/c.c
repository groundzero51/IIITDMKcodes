// B MAHIDHAR REDDY
// CS20B1091

// C PROGRAM TO IMPLIMENT SOCKET PROGRAMMING IN C FOR CLIENT SIDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{

    int frames, window_length, missing_bit;
    printf("enter the no of frames , window length , nth frame missing : ");
    scanf("%d %d %d", &frames, &window_length, &missing_bit);

    // if (missing_bit <= window_length)
    // {
    //     printf("it loops for infinte\n");
    //     printf("missing bit should be greater than window length \n");
    //     printf("enter the no of frames , window length , nth frame missing : ");
    //     scanf("%d %d %d", &frames, &window_length, &missing_bit);
    // }

    int frames_bit[frames], buffer[1024];
    printf("enter frames : ");
    for (int i = 0; i < frames; i++)
    {
        scanf("%d", &frames_bit[i]);
    }

    int ct = 0, j = 1;

//storing the sequence of goback n
    for (int i = 0; i < frames; i++)
    {

        if (ct > 0 && ct % (missing_bit + window_length - 1) == 0) 
        {
            ct = window_length - 1;
            i = i - window_length;
        }
        buffer[j++] = frames_bit[i];
        ct++;
    }
    if (ct == missing_bit + window_length - 1)
    {
        ct = window_length - 1;
        for (int i = frames - window_length; i < frames; i++)
        {
            ct++;
            buffer[j++] = frames_bit[i];
        }

        if (ct == missing_bit)
            buffer[j++] = frames_bit[frames - 1];
    }

    if (ct == missing_bit)
        buffer[j++] = frames_bit[frames - 1];
    buffer[0] = j; //storing the array size in zero index
    printf("\n");

    char *ip = "127.0.0.1"; // Define the respective IP address and port_no on which you want to run the code.
    int port_no = 1111;

    int sock; // Socket file descriptor.

    struct sockaddr_in addr; // Socket addresses.

    socklen_t addr_len; // Used to define socket related parameters.
    // char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0); // Create the socket.

    if (sock < 0)
    { // Validate socket creation.
        printf("[-]---> Socket creation failed.\n");
        exit(1);
    }
    printf("[+]--->TCP Socket creation successful in client.\n");

    memset(&addr, '\0', sizeof(addr)); // Clear out the socket address and assign the address settings.
    addr.sin_family = AF_INET;
    addr.sin_port = port_no;
    addr.sin_addr.s_addr = inet_addr(ip);

    connect(sock, (struct sockaddr *)&addr, sizeof(addr)); // Connect to Server.
    printf("Connected to Server.\n");

//sending the array to server
    send(sock, buffer, sizeof(buffer), 0);

 // Receive the message from Server.
    int buffer1[1024];
    recv(sock, buffer1, sizeof(buffer1), 0);

    printf("from Server : ");
    for (int i = 1; i < buffer1[0]; i++)
    {
        printf(" %d ", buffer1[i]);
    }

    close(sock); // Close the server connection.
    printf("[+] Disconnected from Server.\n");

    return (0);
}

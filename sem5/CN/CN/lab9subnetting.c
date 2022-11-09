// Created by Gaurav cs20b1021
// program for checking if a network id is valid, getting subnet mask and check if N number of subnets can be created

#include <stdio.h>
#include <stdlib.h>

int main(){
    int w,x,y,z;
    printf("\nEnter IP address Byte by byte in decimal number system : ");
    printf("\nEnter ___.xxx.xxx.xxx : ");
    scanf("%d",&w);
    printf("\nEnter %d.___.xxx.xxx : ",w);
    scanf("%d",&x);
    printf("\nEnter %d.%d.___.xxx : ",w,x);
    scanf("%d",&y);
    printf("\nEnter %d.%d.%d.___ : ",w,x,y);
    scanf("%d",&z);
    printf("\n\nIP address : %d.%d.%d.%d",w,x,y,z);

    if (w<0||w<0||w<0||w<0)             //error handling for negative invalid ip address
    {
        printf("\nInvalid IP address!");
        return 0;
    }
    

    if (w>255||x>255||y>255||z>255)         //error handling for invalid ip address
    {
        printf("\nInvalid IP address!");
        return 0;
    }
    
    if (w >224)             //error handling for class D and E
    {
        printf("\nInvalid class for network id!");
        return 0;
    }
    
    
    

}
//
// Created by Gaurav Ramrakhiyani CS20B1021 on 30/08/22.
//
#include<stdio.h>
#include<string.h>

//Input message update with your roll no
char rollno[10]="CS20B1021";
//Input polynomial donot change
char poly[8]="10111011";

//Generate binary string from input message (2 Mark)
char* genbs(char *ipmsg)
{	char bs[100]="";
    printf("\nASCII values: ");
    for(int i=0;ipmsg[i]!='\0';i++)
    {
        printf("(%d)",ipmsg[i]);
        printf(" ");

    }
    for(int i=0;ipmsg[i]!='\0';i++)
    {
        int n = ipmsg[i];
        int binaryNum[32];
        int i = 0;
        printf("n : %d",n);
        while ( n> 0) {
            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        // printing binary array in reverse order
        for (int j = i - 1; j >= 0; j--)
            bs[i] = binaryNum[j];

    }
}
//CRC code generation (3 Marks)
char* genCRC(char *ipstr)
{	char code[8]="";
    //Write code to generate CRC code from input binary string

    return(code);
}

//LRC code generation (2 Marks)
char* genLRC(char *ipstr)
{	char code[8]="";
    //Write code to generate LRC code from input binary string

    return(code);
}

//VRC code generation (2 Marks)
char* genVRC(char *ipstr)
{	char code[8]="";
    //Write code to generate VRC code from input binary string
    return(code);
}


int main()
{
    printf("\nInput Polynomial: %s", poly);
    printf("\nInput Message: %s", rollno);
    printf("\nBinary String: %s", genbs(rollno));
    printf("\nCRC code: %s", genCRC(rollno));
    printf("\nLRC code: %s", genLRC(rollno));
    printf("\nVRC code: %s", genVRC(rollno));
}


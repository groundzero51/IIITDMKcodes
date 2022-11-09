//
// Written by Gaurav R. ( CS20B1021 ) on 6/9/2022.
//
// Program to implement checksum error detection in C.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

char Rstr[10] = "CS20B1021";//Input message update with your roll no
char binarray[100] = "";
char code[8] = "";

void Receive() {
    char *c = binarray[0];
    char CheckSum[8];
    for (int i = 0; i < 8; i++) {
        CheckSum[i] = '0';
    }
    int carry = 0;
    for (int i = 0; i < 10; i++) {
        int bit = 0;
        for (int j = 7; j > -1; j--) {
            if (CheckSum[j] == '0') {
                bit = 0;
            } else if (CheckSum[j] == '1') {
                bit = 1;
            }
            if (binarray[i * 8 + j] == '0') {
                bit += carry;
            } else if (binarray[i * 8 + j] == '1') {
                bit += (carry + 1);
            }
            if (bit == 0) {
                CheckSum[j] = '0';
                carry = 0;
            } else if (bit == 1) {
                CheckSum[j] = '1';
                carry = 0;
            } else if (bit == 2) {
                CheckSum[j] = '0';
                carry = 1;
            } else if (bit == 3) {
                CheckSum[j] = '1';
                carry = 1;
            }
        }
        while (carry == 1) {
            for (int j = 7; j > -1; j--) {
                if (CheckSum[j] == '0') {
                    CheckSum[j] = '1';
                    carry = 0;
                    break;
                } else {
                    CheckSum[j] = '0';
                }
            }
        }
    }
    printf("\n");
    for (int j = 0; j < 8; j++) {
        if (CheckSum[j] == '0') {
            CheckSum[j] = '1';
        } else {
            CheckSum[j] = '0';
        }
        printf("%c ", CheckSum[j]);
    }
    return (CheckSum);
}

char *genbinarray(char *ipmsg) {//Generate binary string from input message (2 Mark)

    int it = 0;
    for (int i = 0; ipmsg[i] != '\0'; i++) {     // printf("\nASCII values: ");
        int asciiInput = ipmsg[i];        // printf("(%d)",ipmsg[i]);
        int f = 1;
        int rem, res = 0;
        int bin[8];
        //converting ascii to integer binary
        for (int j = 0; j < 8; j++) {        //converting ascii to integer binary
            rem = asciiInput % 2;
            bin[7 - j] = rem;
            res = res + (f * rem);
            asciiInput = asciiInput / 2;
            f = f * 10;
        }
        for (int j = 0; j < 8; j++) { //converting integer binary to char binary
            binarray[it] = bin[j] + '0';// printf("%d",bin[j]);
            it++;
        }
    }

    return (binarray);
}

void Send() {
    char *c = binarray[0];
    char CheckSum[8];
    for (int i = 0; i < 8; i++) {
        CheckSum[i] = '0';
    }
    int carry = 0;
    for (int i = 0; i < 9; i++) {
        int bit = 0;
        for (int j = 7; j > -1; j--) {
            if (CheckSum[j] == '0') {
                bit = 0;
            } else if (CheckSum[j] == '1') {
                bit = 1;
            }
            if (binarray[i * 8 + j] == '0') {
                bit += carry;
            } else if (binarray[i * 8 + j] == '1') {
                bit += (carry + 1);
            }
            if (bit == 0) {
                CheckSum[j] = '0';
                carry = 0;
            } else if (bit == 1) {
                CheckSum[j] = '1';
                carry = 0;
            } else if (bit == 2) {
                CheckSum[j] = '0';
                carry = 1;
            } else if (bit == 3) {
                CheckSum[j] = '1';
                carry = 1;
            }
        }
        while (carry == 1) {
            for (int j = 7; j > -1; j--) {
                if (CheckSum[j] == '0') {
                    CheckSum[j] = '1';
                    carry = 0;
                    break;
                } else {
                    CheckSum[j] = '0';
                }
            }
        }
    }
    printf("\n");
    for (int j = 0; j < 8; j++) {
        if (CheckSum[j] == '0') {
            CheckSum[j] = '1';
        } else {
            CheckSum[j] = '0';
        }
        printf("%c ", CheckSum[j]);
    }
    return (CheckSum);
}



void main() {
    printf("Enter roll no : ");
    scanf("%s", Rstr);
    genbinarray(Rstr);
    Send();
    getchar();
    printf("\nEnter checkSum bits : ");
    for (int i = 0; i < 8; i++) {
        scanf("%c", &binarray[72 + i]);
    }
    binarray[80] = '\0';
    Receive();
}
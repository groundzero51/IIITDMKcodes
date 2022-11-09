#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char arr[100];
int arr_size;

int pgen(){

}
void ReverseArr()
{
    int mid = arr_size / 2 + 1;
    for (int i = 1; i < mid; i++)
    {
        arr[i] = arr[arr_size - i];
    }
}
int main(){
    char bitarr[100];
    int bitarr_size = 0;

    int exit = 0;

    printf("Enter 16 bit array string: ");
    scanf("%s", bitarr);

    bitarr_size = strlen(bitarr);

    printf("\nSizes: bit: %d\n", bitarr_size);
    printf("\nOriginal bit array: %s\n", bitarr);
    char e1,o1,e2,o2,e3;
    if (arr[14]==arr[15])
    {
        e1 = '0';
    }
    else
    {
        e1 = '1';
    }
    if (arr[7]==arr[8])
    {
        e2 = '0';
    }
    else
    {
        e2 = '1';
    }
    if (arr[0]==arr[1])
    {
        e3 = '0';
    }
    else
    {
        e3 = '1';
    }
    int a1,a2;
    a1 = (int)arr[13]+(int)arr[12]+(int)arr[11]+(int)arr[10]+(int)arr[9];
    if ((a1%2)==1)
    {
        o1 = '0';
    }
    a2 = (int)arr[3]+(int)arr[4]+(int)arr[5]+(int)arr[6]+(int)arr[2];
    if ((a2%2)==1)
    {
        o2 = '0';
    }
    printf("\nHamming code : ");
    printf(e3,arr[0],arr[1],o2,arr[2],arr[3],arr[4],arr[5],arr[6],e2,arr[7],arr[8],o1,arr[9],arr[10],arr[11],arr[12],arr[13],e1,arr[14],arr[15]);
    
    
    }
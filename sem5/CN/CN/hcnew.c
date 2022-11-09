// Hamming code generation only
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char arr[100];
int arr_size;
void ReverseArr()
{
    int mid = arr_size / 2 + 1;
    for (int i = 1; i < mid; i++)
    {
        arr[i] = arr[arr_size - i];
    }
}

void HC_printArr()
{
    printf("The HC array(%d): ", arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        printf("%c ", arr[arr_size - i]);
    }
    printf("\n");
}

void HC_InitArr(char bitarr[], int bitarr_size)
{
    arr[0] = 'B';
    arr_size = 0;

    int pow2 = 2;
    arr[1] = 'R';
    int index = 2;
    for (int i = 0; i < bitarr_size; i++)
    {
        if (index == pow2)
        {
            arr[index] = 'R';
            index++;
            pow2 = pow2 * 2;
        }
        arr[index] = bitarr[bitarr_size - i - 1];
        index++;
    }

    arr_size = index - 1;
}

void HC_Generate(char bitarr[], int bitarr_size)
{
    HC_InitArr(bitarr, bitarr_size);

    printf("\nBefore Red,\n");
    HC_printArr();

    int pow2 = 1;
    while (pow2 <= arr_size)
    {
        char parity = '0';
        for (int i = pow2; i <= arr_size; i += pow2 * 2)
        {
            int j = 0;
            while (j < pow2)
            {
                if (parity == arr[i + j] || arr[i + j] == 'R')
                    parity = '0';
                else
                    parity = '1';
                j++;
            }
        }
        arr[pow2] = parity;

        pow2 = pow2 * 2;
    }

    printf("\nAfter Red,\n");
    HC_printArr();
}
int main()
{
    char bitarr[100];
    int bitarr_size = 0;

    int exit = 0;

    printf("Enter bit array: ");
    scanf("%s", bitarr);

    bitarr_size = strlen(bitarr);

    printf("\nSizes: bit: %d\n", bitarr_size);
    printf("\nOriginal bit array: %s\n", bitarr);

    HC_Generate(bitarr, bitarr_size);

    printf("\nHamming code : %s\n", arr);
}
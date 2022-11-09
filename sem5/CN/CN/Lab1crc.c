#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int ch;
    while (ch != 3)
    {
        printf("\n1 - Send data\n2 - Receive data\n3 - Exit\nEnter your choice : "); //menu
        scanf("%d", &ch);
        if (ch == 1)
        {
            int pd = 0;
            printf("\nEnter the degree of the polynomial : "); //taking input for polynomial generator code
            scanf("%d", &pd);
            int polygen[pd + 1];
            for (int i = 0; i < (pd + 1); i++)
            {
                printf("\nEnter the coefficient of x^%d : ", pd - i);
                scanf("%d", &polygen[i]); 
                if (polygen[i] != 0)
                    polygen[i] = 1;
            }
            int ndb;
            printf("\nEnter the number of data bits : ");
            scanf("%d", &ndb); //input num of data bits
            int datab[ndb + pd];
            int dividend[ndb + pd];
            for (int i = 0; i < ndb + pd; ++i)// sets the datab and dividend 0 -> ndb+pd bits as zero
            {
                datab[i] = 0;
                dividend[i] = 0;
            }
            printf("\nEnter the data bits from left to right : "); //input data bits
            for (int i = 0; i < ndb; ++i)
            {
                scanf("%d", &datab[i]);
                dividend[i] = datab[i];
            }
            while (1) 
            {
                int start = 0;
                while (1)  //to ignore the redundant zeros from left
                {
                    if (dividend[start] == 1)
                        break;
                    else
                        start++;
                }
                if (ndb + pd - start <= pd) //if start reaches the CRC code ,CRC code is added to datab array from divident to print later on
                {
                    for (int i = start; i < ndb + pd; ++i)
                    {
                        datab[i] = dividend[i];
                    }
                    break;
                }
                else //else the XOR operation is done on the dividents with polygen as divisor till start reaches CRC code part(start == ndb)
                {
                    for (int i = start; i < start + pd + 1; ++i)
                    {
                        if (dividend[i] != polygen[i - start]) // does XOR operation 
                        {
                            dividend[i] = 1;
                        }
                        else
                            dividend[i] = 0;
                    }
                }
            }
            printf("The required result is\n"); // prints databits + crc code
            for (int i = 0; i < ndb + pd; ++i)
            {
                printf("%d", datab[i]);
            }
            printf("\n");
        }
        else if (ch == 2)
        {
            int pd = 0;
            printf("\n Enter the degree of the polynomial : "); //inputs...
            scanf("%d", &pd);
            int polygen[pd + 1];
            printf("\nEnter the coefficients of the polynomial : ");
            for (int i = 0; i < pd + 1; ++i)
            {
                printf("\nEnter the coefficient for x^%d : ", pd-i);
                scanf("%d", &polygen[i]);
                if (polygen[i] != 0)
                    polygen[i] = 1;
            }
            int ndb;
            printf("\n Enter the number of data bits including the CRC bits : ");
            scanf("%d", &ndb);
            int datab[ndb + pd];
            int dividend[ndb + pd];
            for (int i = 0; i < ndb + pd; ++i)
            {
                datab[i] = 0;
                dividend[i] = 0;
            }
            printf("\nEnter the data bits from left to right including the CRC bits : ");
            for (int i = 0; i < ndb; ++i)
            {
                scanf("%d", &datab[i]);
                dividend[i] = datab[i];
            }
            int start = 0;
            while (1)
            {
                start = 0;
                while (start < ndb + pd)  // loops till start reaches 1 
                {
                    if (dividend[start] == 1)
                        break;
                    else
                        start++;
                }
                if (ndb + pd - start <= pd) // copies the given received data to datab 
                {
                    for (int i = start; i < ndb + pd; ++i)
                    {
                        datab[i] = dividend[i];
                    }
                    break;
                }
                else
                {
                    for (int i = start; i < start + pd + 1; ++i)// does xor operation on dividend with polygen as divisor from start to pd+1
                    {
                        if (dividend[i] != polygen[i - start])
                        {
                            dividend[i] = 1;
                        }
                        else
                            dividend[i] = 0;
                    }
                }
            }
            if (start == ndb + pd){ //checks if end is reached (start doesnt reach the end if the data is corrupted cuz divident isnt zerp)
                printf("\nAccepted");
                printf("\nDatabits : ");
                for (int i = 0; i < ndb - pd; ++i)
                {
                    printf("%d", datab[i]);
                }
            }
            else{
                printf("\nRejected");
            }
            printf("\n");
        }
    }
}

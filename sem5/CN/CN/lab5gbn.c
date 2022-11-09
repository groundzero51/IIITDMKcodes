//
// Created by Gaurav Ramrakhiyani on 30/08/22.
//
// Program for Go Back N protocol
// Input : window size,num of frames,drops after how many frames
// assumptions : the acknowledgement timer is so less that no frame can reach before it ends

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nf, size, dropfreq, result = 0, fcount = 1;
    printf("\nEnter the number of frames to be sent : ");
    scanf("%d", &nf);
    printf("\nEnter the Sender's window size : ");
    scanf("%d", &size);
    printf("\nPlease enter the drop frequency : ");
    scanf("%d", &dropfreq);
    while (fcount <= nf)
    {
        if (nf - fcount <= size - 1)
        {
            if ((result + 1) % dropfreq == 0)
            {
                result += nf - fcount + 1;
            }
            else
            {
                fcount++;
                result++;
            }
        }
        else
        {
            if ((result + 1) % dropfreq == 0)
            {
                result += size;
            }
            else
            {
                fcount++;
                result++;
            }
        }
    }
    printf("\nThe number of frames sent is %d ", result);
    return 0;
}
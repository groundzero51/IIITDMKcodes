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
            int ndb;
            printf("\nEnter number of data bits : ");
            scanf("%d",&ndb);
            printf("\nEnter data bits digit by digit : ");
            int nr = ndb/4;
            if (ndb%4!=0)
            {
                nr++;
            }
            int rm = ndb%4;
            printf("%d",rm);
            int datab[1000];
            for(int i = 0; i < ndb; i++){
                datab[i] = 0;
            }
            for(int i = 0; i < ndb ; i++){
                scanf("%d",&datab[i]);
            }
            
            printf("\nResult with even parity : ");
            // printf("\n nr : %d",nr);
            // printf("\n nr : %d",nr);
            //printf("\n parity bits : ");
            for(int k = 0 ; k < nr;k++){
                for (int j = k*4; j < (k+1)*4; j++)
                {
                    datab[ndb+4-rm+k] +=datab[j];
                }
                
            }
            for(int i = ndb+4-rm; i<ndb+nr+4-rm ; i++){
                //printf("\n %d",datab[i]); // 
                if(datab[i]%2==0)
                datab[i] = 0;
                else 
                datab[i] = 1;
                //printf(" %d",datab[i]);
            }
            printf("\nresult ( data bits with parity bits ): ");
            for (int i = 0; i < ndb; i++)
            {
                printf("%d",datab[i]);
            }
            for (int i = ndb+4-rm; i < ndb+nr+4-rm; i++)
            {
                printf("%d",datab[i]);
            }
            
        }
        if (ch == 2)
        {   
            int ndb,flag,nr,rm;
            printf("Enter the number of data bits in received measage : ");
            scanf("%d",&ndb);
            nr = ndb/4;
            if (ndb%4!=0)
            {
                nr++;
                
            }
            rm = ndb%4;
            int datab[ndb+nr];
            printf("\nEnter the message received bit by bit  : ");
            for(int i = 0; i < ndb+4-rm+nr ; i++){
                scanf("%d",&datab[i]);
            }
            int pb[nr];
            for(int i = ndb+4-rm; i < ndb+4-rm+nr ; i++){
                pb[i-ndb+4-rm] = datab[i];
                datab[i] = 0;
                printf("%d",pb[i-ndb]);
            }

            for (int j = 0; j < ndb+4-rm ; j+=4){
                for(int i = 0; i < j+4 ; i++)
                {
                    datab[ndb+(j/4)+4-rm]+=datab[j+i];
                }
                
            }
            
            for(int i = ndb; i<ndb+4-rm+nr ; i++){
                if(datab[i]%2==0)
                datab[i] = 0;
                else 
                datab[i] = 1;
            }

            for(int i = ndb; i < ndb+4-rm+nr ; i++){
                if(pb[i-ndb] == datab[i])
                flag = 0;
                else{
                flag = 1;
                break;}
            }
            if (flag == 0)
            {
                printf("\nCode is not corrupted");
            }
            else if (flag == 1)
            {
                printf("\nCode is corrupted");
            }
        }
    }

}
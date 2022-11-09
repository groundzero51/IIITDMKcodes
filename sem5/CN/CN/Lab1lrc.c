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
            int datab[ndb+4];
            for(int i = 0; i < ndb+4 ; i++){
                datab[i] = 0;
            }
            for(int i = 0; i < ndb ; i++){
                scanf("%d",&datab[i]);
            }
            
            printf("\nResult with even parity : ");
            printf("\n parity bits : ");
            for (int j = 0; j < ndb ; j+=4){
                for(int i = 0; i < 4 ; i++)
                {
                    datab[ndb+i]+=datab[j+i];
                }
                
            }
            for(int i = ndb; i<ndb+4 ; i++){
                if(datab[i]%2==0)
                datab[i] = 0;
                else 
                datab[i] = 1;
                printf("%d",datab[i]);
            }
            printf("\nresult ( data bits with parity bits ): ");
            for (int i = 0; i < ndb+4; i++)
            {
                printf("%d",datab[i]);
            }
            
        }
        if (ch == 2)
        {   
            int tot,ndb,flag;
            printf("Enter the number of digits in sent measage : ");
            scanf("%d",&tot);
            ndb = tot-4;
            int datab[ndb+4];
            printf("\nEnter the message received bit by bit  : ");
            for(int i = 0; i < ndb+4 ; i++){
                scanf("%d",&datab[i]);
            }
            int pb[4];
            for(int i = ndb; i < ndb+4 ; i++){
                pb[i-ndb] = datab[i];
                datab[i] = 0;
                printf("%d",pb[i-ndb]);
            }

            for (int j = 0; j < ndb ; j+=4){
                for(int i = 0; i < 4 ; i++)
                {
                    datab[ndb+i]+=datab[j+i];
                }
                
            }
            
            for(int i = ndb; i<ndb+4 ; i++){
                if(datab[i]%2==0)
                datab[i] = 0;
                else 
                datab[i] = 1;
            }

            for(int i = ndb; i < ndb+4 ; i++){
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
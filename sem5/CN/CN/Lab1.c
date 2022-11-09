#include <stdio.h>

int main(){
    int menuOption;
    printf("Please enter 1 for sending or 2 for receiving\n");
    scanf("%d",&menuOption);
    if(menuOption==1){
        int pd=0;
        printf("Please enter the degree of the polynomial\n");
        scanf("%d",&pd);
        int cARR[pd+1];
        printf("Please enter the coefficients of the polynomial\n");
        for (int i = 0; i < pd+1; ++i) {
            printf("Please enter the coefficient for x^%d\n",i);
            scanf("%d",&cARR[pd-i]);
            if(cARR[i]!=0)
                cARR[i]=1;
        }
        int ndb;
        printf("Please enter the number of data bits\n");
        scanf("%d",&ndb);
        int data[ndb+pd];
        int dividend[ndb+pd];
        for (int i = 0; i < ndb+pd; ++i) {
            data[i]=0;
            dividend[i]=0;
        }
        printf("Please enter the data bits from left to right\n");
        for (int i = 0; i < ndb; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
            dividend[i]=data[i];
        }

        while(1){      //loop to remove the insignificant zeros from the dividend array
            int start = 0;
            while(1){
                if(dividend[start]==1)
                    break;
                else
                    start++;
            }
            if(ndb+pd-start<=pd){
                for (int i = start; i < ndb+pd; ++i) {
                    data[i]=dividend[i];
                }
                break;
            }
            else{
                for (int i = start; i < start+pd+1 ; ++i) {
                    if(dividend[i]!=cARR[i-start]){
                        dividend[i]=1;
                    }
                    else
                        dividend[i]=0;
                }
            }
        }
        printf("The required result is\n");
        for(int i = 0; i < ndb+pd; ++i) {
            printf("%d",data[i]);
        }
        printf("\n");

    }
    else if (menuOption==2){
        int pd=0;
        printf("Please enter the degree of the polynomial\n");
        scanf("%d",&pd);
        int cARR[pd+1];
        printf("Please enter the coefficients of the polynomial\n");
        for (int i = 0; i < pd+1; ++i) {
            printf("Please enter the coefficient for x^%d\n",i);
            scanf("%d",&cARR[pd-i]);
            if(cARR[i]!=0)
                cARR[i]=1;
        }
        int ndb;
        printf("Please enter the number of data bits including the CRC bits\n");
        scanf("%d",&ndb);
        int data[ndb+pd];
        int dividend[ndb+pd];
        for (int i = 0; i < ndb+pd; ++i) {
            data[i]=0;
            dividend[i]=0;
        }
        printf("Please enter the data bits from left to right including the CRC bits\n");
        for (int i = 0; i < ndb; ++i) {
            printf("Please enter the bit\n");
            scanf("%d",&data[i]);
            dividend[i]=data[i];
        }
        int start = 0;
        while(1){
            start=0;
            while(start<ndb+pd){
                if(dividend[start]==1)
                    break;
                else
                    start++;
            }
            if(ndb+pd-start<=pd){
                for (int i = start; i < ndb+pd; ++i) {
                    data[i]=dividend[i];
                }
                break;
            }
            else{
                for (int i = start; i < start+pd+1 ; ++i) {
                    if(dividend[i]!=cARR[i-start]){
                        dividend[i]=1;
                    }
                    else
                        dividend[i]=0;
                }
            }
        }
        if(start==ndb+pd){
            printf("Accepted\n");
            printf("Databits : \n");
            for(int i = 0; i < ndb-pd; ++i) {
                printf("%d",data[i]);
            }
        }
        else{
            printf("rejected");
        }
        printf("\n");

    }
    else{
        printf("invalid menu option selected\n");
    }
}
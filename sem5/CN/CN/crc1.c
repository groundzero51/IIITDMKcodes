#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int ch;
    while(ch != 3){
        printf("\n1 - Send data\n2 - Receive data\n3 - Exit\nEnter your choice : ");
        scanf("%d", &ch);
        if(ch == 1){
            char c;
            int size, n;
            printf("Please enter the number of bits in the data(Data bits): \n");
            scanf("%d", &size);
            char inputData[size];
            printf("Please enter the sender's data: \n");
            for(int i = 0; i < size;i++){
                scanf(" %c", &inputData[i]);
            }
            printf("Please enter the degree of polynomial generator: \n");
            scanf("%d", &n);
            int divBits = n+1;
            int counter = divBits;
            char polygen[divBits];
            printf("Please enter the binary form of the polynomial generator (in decreasing order of powers): \n");
            for(int i = 0; i <= n;i++){
                scanf(" %c", &polygen[i]);
            }
            int s = size+n;
            char result[s];
            for(int i = 0; i < size;i++){
                result[i] = inputData[i];
            }
            for(int i = size; i < s;i++){
                result[i] = '0';
            }
            char temp[divBits];
            for(int i = 0; i < divBits; i++){
                temp[i] = result[i];
            }
            while(counter < s){
                if(temp[0] == '1'){
                    for(int i = 1; i < divBits;i++){
                        if(temp[i] != polygen[i]) temp[i-1] = '1';
                        else temp[i-1] = '0';
                    }
                    temp[divBits-1] = result[counter];
                }
                else{
                    for(int i = 1; i < divBits;i++){
                        temp[i-1] = temp[i];
                    }
                    temp[divBits-1] = result[counter];
                }
                counter++;
            }
            if(temp[0] == '1'){
                for(int i = 1; i < divBits;i++){
                    if(temp[i] != polygen[i]) temp[i-1] = '1';
                    else temp[i-1] = '0';
                }
            }
            else{
                for(int i = 1; i < divBits;i++){
                    temp[i-1] = temp[i];
                }
            }
            int j = 0;
            for(int i = size; i < s && j < n;i++){
                result[i] = temp[j];
                j++;
            }
            printf("The resultant data is: ");
            for(int i = 0; i < s;i++){
                printf("%c", result[i]);
            }
            printf("\n");
        }
        else if(ch == 2){
            char c;
            int size, n;
            printf("Please enter the number of bits in the data(Data bits + CRC code): \n");
            scanf("%d", &size);
            char inputData[size];
            printf("Please enter the received data: \n");
            for(int i = 0; i < size;i++){
                scanf(" %c", &inputData[i]);
            }
            printf("\nPlease enter the degree of polynomial generator : ");
            scanf("%d", &n);
            int divBits = n;
            int counter = divBits;
            char polygen[divBits];
            printf("\nPlease enter the binary form of the polynomial generator (in decreasing order of powers): ");
            for(int i = 0; i <= n;i++){
                scanf(" %c", &polygen[i]);
            }
            char temp[divBits];
            for(int i = 0; i < divBits; i++){
                temp[i] = inputData[i];
            }
            while(counter < size){
                if(temp[0] == '1'){
                    for(int i = 1; i < divBits;i++){
                        if(temp[i] != polygen[i]) temp[i-1] = '1';
                        else temp[i-1] = '0';
                    }
                    temp[divBits-1] = inputData[counter];
                }
                else{
                    for(int i = 1; i < divBits;i++){
                        temp[i-1] = temp[i];
                    }
                    temp[divBits-1] = inputData[counter];
                }
                counter++;
            }
            if(temp[0] == '1'){
                for(int i = 1; i < divBits;i++){
                    if(temp[i] != polygen[i]) temp[i-1] = '1';
                    else temp[i-1] = '0';
                }
            }
            else{
                for(int i = 1; i < divBits;i++){
                    temp[i-1] = temp[i];
                }
            }
            bool flag = false;
            for(int i = 0; i < n;i++){
                if(temp[i] == '1'){
                    flag = true;
                    break;
                }
            }
            if(!flag) printf("The Given Data is not corrupted (Accepted) \n");
            else printf("The Given Data is corrupted (Rejected) \n");
        }
        else if(ch == 3){
            printf("Exiting the program");
            exit(0);
        }
    }
	return 0;
}

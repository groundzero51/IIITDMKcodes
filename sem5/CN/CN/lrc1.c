#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int choice;
	while(choice !='q'){
		printf("\n1 - Send data\n2 - Receive data\n3 - Exit\nEnter your choice : ");
		scanf(" %d", &choice);
		if(choice == 1){
			int n;
				printf("Please enter the number of bits of the message(databits): \n");
				scanf("%d", &n);
				if(n%4 == 0){
					char dataBits[n];
					printf("Please enter the data bits of the message: \n");	
					for(int i = 0; i < n;i++){
						scanf(" %c", &dataBits[i]);
					}
					char LRC[4];
					for(int i = 0; i < 4;i++){
						int sum = 0;
						for(int j = i; j < n;j += 4){
							if(dataBits[j] == '1') sum++;
						}
						if(sum % 2 == 0) LRC[i] = '0';
						else LRC[i] = '1'; 
					}
					printf("The resultant message is: \n");
					for(int i = 0; i < n;i++){
						printf("%c", dataBits[i]);
					}
					for(int i = 0; i < 4;i++){
						printf("%c", LRC[i]);
					}
					printf("\n");
				}	
				else{
					printf("Please enter a multiple of 4 as number of bits \n");
				}
		}
		else if (choice ==2){
			int n;
			printf("Please enter the number of bits of the message (LRC + databits): \n");
			scanf("%d", &n);
			if(n%4 == 0){
				printf("Please enter the data bits of the message: \n");
				char result[n];
				for(int i = 0; i < n;i++){
					scanf(" %c", &result[i]);
				}
				bool flag = false;
				for(int i = 0; i < 4;i++){
					int sum = 0;
					for(int j = i; j < (n - 4);j += 4){
						if(result[j] == '1') sum++;
					}
					if(sum % 2 == 0){
						if(result[n-4+i] == '0') continue;
						else{
							flag = true;
							break;
						}
					}
					else{
						if(result[n-4+i] == '1') continue;
						else{
							flag = true;
							break;
						}
					}
				}
				if(!flag) printf("The Given Data is not corrupted (Accepted) \n");
				else printf("The Given Data is corrupted (Rejected) \n");
			}	
			else{
				printf("Please enter a multiple of 4 as number of bits \n");
			}
		}
		else if(choice == 3){
			printf("Exiting the program");
			exit(0);
		}
	}
	return 0;
}
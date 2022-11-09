// Created by Gaurav cs20b1021
// program for checking if a network id is valid, getting subnet mask and check if N number of subnets can be created

#include<stdio.h>
#include<ctype.h>
#include<math.h>

void IntToBinary(int n[4],int b[32])
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=i*8+7;j>=i*8;j--)
    {
        if(n[i]%2==0) b[j]=0;
        else b[j]=1;
        n[i]/=2;
    }
}

void BinaryToInt(int b[32])
{
    int n,i,j;
    for(i=0;i<4;i++)
    {
        for(n=0,j=i*8;j<=i*8+7;j++)
        {
            n*=2;
            n+=b[j];
        }
        printf("%i",n);
        if(i!=3) printf(".");
    }
}

void main()
{
    char ip[16];
    int num[4]={0,0,0,0},i,flag=0,hostidspossible,bits[32],sub,j;
    printf("enter network ID: ");
    scanf("%s",ip);         //storing the network id in string
    for(i=0;ip[i]!='\0';i++)
        if(flag==4)         //more than 3 dots error
        {
            printf("invalid IP address");
            return;
        }
        else if(ip[i]=='.')         //counting dots and the byte we are on
        {
            if(ip[i+1]=='.'||ip[i+1]=='\0')     //two consecutive dots or line ends after dot error
            {
                printf("invalid IP address");
                return;
            }
            else flag++;
        }
        else if(isdigit(ip[i]))         //copying the int in string to an array 
        {
            num[flag]*=10;
            num[flag]+=ip[i]-48;
        }
        else
        {
            printf("invalid IP address");
            return;
        }
    if(flag!=3)         //less than three dot error
    {
        printf("invalid IP address");
        return;
    }
    for(i=0;i<4;i++)
        if(num[i]>255)      //integers in ip being greater than 255 error
        {
            printf("invalid IP address");
            return;
        }
    if(num[0]==0||num[0]==127)      //0 and 127 cannot be first byte of ip
    {
        printf("IP address does not belong to any class");
        return;
    }
    else if(num[0]<127) hostidspossible=23;
    else if(num[0]<192) hostidspossible=15;
    else if(num[0]<224) hostidspossible=7;
    else
    {
        printf("class of given network ID cannot have subnets");
        return;
    }
    IntToBinary(num,bits);
    for(i=0;i<=hostidspossible;i++)
        if(bits[31-i]==1)
        {
            printf("given network ID is not valid");
            return;
        }
    printf("enter number of subnets: ");
    scanf("%i",&sub);
    for(i=1;i<=hostidspossible;i++)
        if(pow(2,i)==sub) break;
    if(i>hostidspossible)
    {
        printf("number of subnets is not valid");
        return;
    }
    printf("total number of IP addresses in class is %lf\n",pow(2,hostidspossible+1));
    printf("total number of hosts per subnet is %lf\n",pow(2,hostidspossible+1)/sub);
    sub=log2(sub);
    printf("Interface\tSubnet ID\t\tLimited broadcast address\n");
    printf("1\t\t");
    BinaryToInt(bits);
    for(i=31-hostidspossible+sub;i<32;i++)
        bits[i]=1;
    printf("\t\t");
    BinaryToInt(bits);
    printf("\n");
    for(i=1;i<pow(2,sub);i++)
    {
        for(j=31-hostidspossible+sub;j<32;j++)
            bits[j]=0;
        printf("%i\t\t",i+1);
        for(j=30-hostidspossible+sub;bits[j]==1;j--)
            bits[j]=0;
        bits[j]=1;
        BinaryToInt(bits);
        for(j=31-hostidspossible+sub;j<32;j++)
            bits[j]=1;
        printf("\t\t");
        BinaryToInt(bits);
        printf("\n");
    }
    for(i=31-hostidspossible+sub;i<32;i++)
        bits[i]=0;
    for(i=30-hostidspossible+sub;i>=0;i--)
        bits[i]=1;
    printf("subnet mask is ");
    BinaryToInt(bits);
}
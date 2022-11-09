
//code to identify whether the given string is accepted / rejected by the following CFG given to us


#include <stdio.h>
#include <stdlib.h>
char token;

void fB();
void fA();
void fS();

void ERR()
{
    printf("\nthe given string is rejected ");
    exit(1);
}

void ACC()
{
    printf("\nthe given string is accepted ");
    exit(1);
}

void fB()/* B --> bA | S */
{

    switch (token)
    {
    case 'a':
        fS();
        break;
    case 'b':
        token = getchar();
        fA();
        break;
    case 'c':
        fS();
        break;
    default:
        ERR();
    }
}
void fA()/* A --> ba | SB */
{

    switch (token)
    {
    case 'a':
        fS();
        fB();
        break;

    case 'b':
        token = getchar();

        if (token == 'a')
        {
            token = getchar();
            break;
        }
        else
            ERR();
        break;

    case 'c':
        fS();
        fB();
        break;
    
    default:
        ERR();
    }
}

/* function for nonterminal S */
void fS()/* S --> aAS | c */
{

    switch (token)
    {
    case 'a':
        token = getchar();
        fA();
        fS();
        break;

    case 'c':
        token = getchar();
        break;

    default:
        ERR();
    }
}

/* function for nonterminal S’ */
int main()/* S’ --> S$ */
{
    token = getchar();
    fS();
    if (token == '$')
        ACC();
    else
        ERR();
}


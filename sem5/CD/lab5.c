
//please name the input as input.txt while using 

/*
Given a CFG as an input file in which each line is having exactly one production rule and epsilon as #,
Write a c program to compute the first and follow sets of both T & NT (Terminals & Non-terminals) in the given CFG. 
(NT-Capital letters, T-small letters).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);
int count, n = 0;
char calc_first[10][100];
char calc_follow[10][100];
int m = 0;
char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;
void follow(char c)
{
    int i, j;
    if (production[0][0] == c)
    {
        f[m++] = '$';
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 2; j < 10; j++)
        {
            if (production[i][j] == c)
            {
                if (production[i][j + 1] != '\0')
                {
                    followfirst(production[i][j + 1], i, (j + 2));
                }
                if (production[i][j + 1] == '\0' && c != production[i][0])
                {
                    follow(production[i][0]);
                }
            }
        }
    }
}
void findfirst(char c, int q1, int q2)
{
    int j;
    if (!(isupper(c)))
    {
        first[n++] = c;
    }
    for (j = 0; j < count; j++)
    {
        if (production[j][0] == c)
        {
            if (production[j][2] == '#')
            {
                if (production[q1][q2] == '\0')
                    first[n++] = '#';
                else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                {
                    findfirst(production[q1][q2], q1, (q2 + 1));
                }
                else
                    first[n++] = '#';
            }
            else if (!isupper(production[j][2]))
            {
                first[n++] = production[j][2];
            }
            else
            {
                findfirst(production[j][2], j, 3);
            }
        }
    }
}
void followfirst(char c, int c1, int c2)
{
    int k;
    if (!(isupper(c)))
        f[m++] = c;
    else
    {
        int i = 0, j = 1;
        for (i = 0; i < count; i++)
        {
            if (calc_first[i][0] == c)
                break;
        }
        while (calc_first[i][j] != '!')
        {
            if (calc_first[i][j] != '#')
            {
                f[m++] = calc_first[i][j];
            }
            else
            {
                if (production[c1][c2] == '\0')
                {
                    follow(production[c1][0]);
                }
                else
                {
                    followfirst(production[c1][c2], c1, c2 + 1);
                }
            }
            j++;
        }
    }
}
int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");//please name the input as input.txt while using
    char buf[2000];
    int i = 0;
    int jm = 0;
    int km = 0;
    int choice;
    char c, ch;

    while(fgets(buf,1000,fp)!=NULL)
    {
        count++;
    }
    
    //count = 7;
    //taking the input from the file
    while (fgets(buf, 1000, fp) != NULL && (i < 7))
    {
        strcpy(production[i], buf);
        i++;
    }

    for (i = 0; i < 7; i++)
    {
        printf("%s", production[i]);
    }
    int kay;
    char done[count];
    int ptr = -1;
    for (k = 0; k < count; k++)
    {
        for (kay = 0; kay < 100; kay++)
        {
            calc_first[k][kay] = '!';
        }
    }
    int pt1 = 0, pt2, end;
    for (k = 0; k < count; k++)
    {
        c = production[k][0];
        pt2 = 0;
        end = 0;
        for (kay = 0; kay <= ptr; kay++)
            if (c == done[kay])
                end = 1;
        if (end == 1)
            continue;
        findfirst(c, 0, 0);
        ptr += 1;
        done[ptr] = c;
        printf("\n First(%c) = { ", c);
        calc_first[pt1][pt2++] = c;
        for (i = 0 + jm; i < n; i++)
        {
            int lark = 0, chk = 0;
            for (lark = 0; lark < pt2; lark++)
            {
                if (first[i] == calc_first[pt1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                printf("%c, ", first[i]);
                calc_first[pt1][pt2++] = first[i];
            }
        }
        printf("}\n");
        jm = n;
        pt1++;
    }
    printf("\n\n");
    char donee[count];
    ptr = -1;
    for (k = 0; k < count; k++)
    {
        for (kay = 0; kay < 100; kay++)
        {
            calc_follow[k][kay] = '!';
        }
    }
    pt1 = 0;
    int land = 0;
    for (e = 0; e < count; e++)
    {
        ck = production[e][0];
        pt2 = 0;
        end = 0;
        for (kay = 0; kay <= ptr; kay++)
            if (ck == donee[kay])
                end = 1;
        if (end == 1)
            continue;
        land += 1;
        follow(ck);
        ptr += 1;
        donee[ptr] = ck;
        printf(" Follow(%c) = { ", ck);
        calc_follow[pt1][pt2++] = ck;

        for (i = 0 + km; i < m; i++)
        {
            int lark = 0, chk = 0;
            for (lark = 0; lark < pt2; lark++)
            {
                if (f[i] == calc_follow[pt1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0)
            {
                printf("%c, ", f[i]);
                calc_follow[pt1][pt2++] = f[i];
            }
        }
        printf(" }\n\n");
        km = m;
        pt1++;
    }
    fclose(fp);
    return 0;
}
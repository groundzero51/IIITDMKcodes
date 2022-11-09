#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char fname[20], str;
    int l = 0, cn = 0, wc = 0;
    printf(" Input the filename to be opened : ");
    scanf("%s", fname);
    fp = fopen(fname, "r");
    while ((str = fgetc(fp)) != EOF)
    {
        if (str == '\n')
        {
            l++;
        }
        if (str == '\t' || str == ' ')
        {
            wc++;
        }
        cn++;
        if (feof(fp))
            break;
    }
    //comment lol
//im retarded lol
/*this lab sucks
 so much*/

    printf("Number of lines is : %d \n", l);
    printf("Number of words is : %d \n", wc);
    printf("Number of characters is : %d \n", cn);
}
#include <stdio.h>
#include <stdlib.h>

//fopen opens a file in c and then we can perform operations on it

int main(int argc,char** argv) {
    FILE * reqFilePtr = NULL;
    reqFilePtr = fopen(argv[1],"r");//file ptr set to null and fopen
    FILE * outputFilePtr = NULL;
    outputFilePtr = fopen("textdump.c","w+");//file ptr set to null and fopen
    int prevChar = '\n';// the first line is empty because of this, space can be also so used instead but no zero cuz it prints the ascii char instead
    //current char is set to prev char when reading a new letter
    int currentChar = fgetc(reqFilePtr);//obv shit
    while (currentChar!=EOF){//obv shit
        if(currentChar == '*' && prevChar == '/'){
            while(1){
                if(currentChar == '/' && prevChar == '*'){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else if(currentChar == '/' && prevChar == '/'){
            while(1){
                if(currentChar == '\n'){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else if(currentChar == ' ' && prevChar == ' '){
            while(1){
                if(currentChar != ' '){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else if(currentChar == '\n' && prevChar == '\n'){
            while(1){
                if(currentChar != '\n'){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else if(prevChar == '#'){
            while(1){
                if(currentChar == '\n'){
                    break;
                }
                prevChar =currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        else{
            fputc(prevChar,outputFilePtr);
            prevChar =currentChar;
            currentChar = fgetc(reqFilePtr);
        }

    }
    fputc(prevChar,outputFilePtr);
    fclose(outputFilePtr);
    fclose(reqFilePtr);
}
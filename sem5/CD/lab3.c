
// run the program as ./a.out [requiredfile]
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tokenisation : line 12-94 ,207-280
// removing redundant redundant lines, spaces, comments and preprocessor directives : l98-208

bool ifinteger(char *str) // Checks if the string is an INTEGER.
{
    int i, len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

bool ifrealnum(char *str) // Checks if the string is a REAL NUMBER.
{
    int i, len = strlen(str);
    bool hasDecimal = false;
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

bool ifspecialsymbol(char ch) // Checks if the character is a SPECIAL SYMBOL.
{
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';' || ch == ',')
        return true;
    return false;
}

bool ifdemlimiter(char ch) // Checks if the character is a DELIMITER.
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);

    return (false);
}

bool ifoperator(char ch) // Checks if the character is an OPERATOR.
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '|' || ch == '&' || ch == '^' || ch == '!')
        return (true);

    return (false);
}

bool ifvalididentifier(char *str) // Checks if the string is a VALID IDENTIFIER.
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || ifdemlimiter(str[0]) == true)
        return (false);

    return (true);
}

bool ifkeyword(char *str) // Checks if the string is a KEYWORD.
{
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") ||
        !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") ||
        !strcmp(str, "auto") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") ||
        !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") ||
        !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto") || !strcmp(str, "const") ||
        !strcmp(str, "default") || !strcmp(str, "enum") || !strcmp(str, "extern") || !strcmp(str, "for") ||
        !strcmp(str, "volatile") || !strcmp(str, "register") || !strcmp(str, "union") || !strcmp(str, "signed"))
        return (true);

    return (false);
}

char *substring(char *str, int left, int right) // Extracts the substring given the start, end position and the string
{
    int i;
    char *subStr = (char *)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

void start(char *filename) // Function for removing redundant lines, spaces, comments and preprocessor directives
{
    FILE *reqFilePtr = fopen(filename, "r");
    FILE *outputFilePtr = fopen("textdump.c", "w+");
    int prevChar = '\n';
    int currentChar = fgetc(reqFilePtr);
    while (currentChar != EOF)
    {
        // remove multiline comments
        if (currentChar == '*' && prevChar == '/')
        {
            while (1)
            {
                if (currentChar == '/' && prevChar == '*')
                {
                    break;
                }
                prevChar = currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        // remove single line comments
        else if (currentChar == '/' && prevChar == '/')
        {
            while (1)
            {
                if (currentChar == '\n')
                {
                    break;
                }
                prevChar = currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        // remove redundant spaces
        else if (currentChar == ' ' && prevChar == ' ')
        {
            while (1)
            {
                if (currentChar != ' ')
                {
                    break;
                }
                prevChar = currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        // remove redundant lines
        else if (currentChar == '\n' && prevChar == '\n')
        {
            while (1)
            {
                if (currentChar != '\n')
                {
                    break;
                }
                prevChar = currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        // remove preprocessor directives
        else if (prevChar == '#')
        {
            while (1)
            {
                if (currentChar == '\n')
                {
                    break;
                }
                prevChar = currentChar;
                currentChar = fgetc(reqFilePtr);
            }
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
        }
        // else insert the char into the file
        else
        {
            fputc(prevChar, outputFilePtr);
            prevChar = currentChar;
            currentChar = fgetc(reqFilePtr);
        }
    }
    fputc(prevChar, outputFilePtr);
    fclose(reqFilePtr);
    fclose(outputFilePtr);
    reqFilePtr = fopen(filename, "w");
    outputFilePtr = fopen("temp.c", "r");
    char c = fgetc(outputFilePtr);
    while (c != EOF)
    {
        fputc(c, reqFilePtr);
        c = fgetc(outputFilePtr);
    }
    fclose(reqFilePtr);
    fclose(outputFilePtr);
    remove("temp.c");
}

void parse(char *str, FILE *fp) // Parsing the input STRING.
{
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right)
    {
        if (str[right] == '\n')
            break;
        if (str[right] == '"')
        {
            left = right;
            right++;
            while (str[right] != '"')
            {
                right++;
            }
            char *subStr = substring(str, left, right);
            fputs(subStr, fp);
            fputs(" IS A STRING\n", fp);
            right++;
            left = right;
            continue;
        }
        if (ifdemlimiter(str[right]) == false)
            right++;
        if (ifdemlimiter(str[right]) == true && left == right)//sorts them either into operator / special symbol
        {
            if (ifoperator(str[right]) == true)
            {
                while (ifoperator(str[right]) == true)
                {
                    right++;
                }
                right--;
                char *subStr = substring(str, left, right);
                fputs(subStr, fp);
                fputs(" IS AN OPERATOR\n", fp);
            }
            else if (ifspecialsymbol(str[right]) == true)
            {
                fputc(str[right], fp);
                fputs(" IS A SPECIAL SYMBOL\n", fp);
            }
            right++;
            left = right;
        }
        else if (ifdemlimiter(str[right]) == true && left != right || (right == len && left != right))//sorts them either into keyword,constant,identifier and invalid identifier
        {
            char *subStr = substring(str, left, right - 1);
            if (ifkeyword(subStr) == true)
            {
                fputs(subStr, fp);
                fputs(" IS A KEYWORD\n", fp);
            }
            else if (ifinteger(subStr) == true || ifrealnum(subStr) == true)
            {
                fputs(subStr, fp);
                fputs(" IS A CONSTANT\n", fp);
            }
            else if (ifvalididentifier(subStr) == true && ifdemlimiter(str[right - 1]) == false)
            {
                fputs(subStr, fp);
                fputs(" IS A VALID IDENTIFIER\n", fp);
            }
            else if (ifvalididentifier(subStr) == false && ifdemlimiter(str[right - 1]) == false)
            {
                fputs(subStr, fp);
                fputs(" IS NOT A VALID IDENTIFIER\n", fp);
            }
            left = right;
        }
    }
    return;
}

int main(int args, char *argv[])
{
    FILE *fp1, *fp2;
    start(argv[1]);
    start(argv[1]);
    fp1 = fopen(argv[1], "r");
    fp2 = fopen("textdump.c", "w"); // enter the name of the result file here
    char str[1000] = "";
    while (fgets(str, sizeof(str), fp1))
    {
        parse(str, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return (0);
}
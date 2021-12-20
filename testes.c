/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strdel(char *s, char ch){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++){
        if(s[i] != ch){
            s[j++] = s[i];
        }
        s[j] = '\0';
        return s;
    }
}

char* strseta(char s[], char ch) {
    int i;
    for (i = 0; s[i] != '\0'; i++)

        s[i] = ch;

        return s;
}

void main()
{
    float a = 1234.6;
    char b[9];
    char buffer[40];
    gcvt(a, 30, buffer);
    //(a);
    printf("%s", buffer);
}
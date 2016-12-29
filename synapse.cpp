#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_reverse1(char* string)
{
    int i = 0;
    int j = 0;
    char t;
    //find the length of the string
    for ( ; string[i] != '\0'; i++); 
    // i starts from end, j from begining, swapping i & j positions
    for ( i--; j <= i ; j++, i--)
    {
        t = string[j];
        string[j] = string[i];
        string[i] = t;
    }
}

char* string_reverse2(const char* string)
{
    char *p =(char*)malloc(sizeof(string));
    int i = 0 , j = 0;
    int len  = strlen(string);
    for ( j = 0 , i = len-1; j < len; i--, j++ )
        p[j] = string[i];
    p[len] = '\0';
    return p;
}

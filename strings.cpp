#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void string_reverse_old(char* string)
{
    int i = 0;
    int j = 0;
    char t;
    int len = 0;
    for (;string[i]!='\0';i++)
    {
        len++;
        printf("%d", len);
    }
    for (i= len-1; j<=i ;j++, i--)
    {    printf("%c", string[i]);
        printf("%c",string[j]);
        t = string[j];
        string[j] = string[i];
        string[i] = t;
    }
    string[len+1]='\0';
    printf("\nreversed string :%s", string);
}
   
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
/* throws a error that you cannot change the value of a const char* /
char* string_reverse2_inplace(const char* string)
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
    return string;
}
*/

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

int main()
{
    const char p[14] = "I am a Wizard";
    char *m = string_reverse2(p);
    printf("reversed string called from main :%s", m );
}

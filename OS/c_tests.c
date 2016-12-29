#include <stdio.h>
void show (char* str)
{
    printf("printing str %s", str);
}
int main()
{
    char*str="zyx";
    show (str);
}
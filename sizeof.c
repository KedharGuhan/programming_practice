#include <stdio.h>
int main()
{
    int i = 0;
    long j = 0;
    short int x;
    long int y;
    float z;
    long double u;
    double d;
    char w;
    short s;
    long l;
    printf("\nSize of int : %zu" , sizeof(i));
    printf("\nSize of short int :%zu  " , sizeof(x));
    printf("\nSize of short  %zu: " , sizeof(s));
    printf("\nSize of long int : %zu" , sizeof(j));
    printf("\nSize of long : %zu" , sizeof(l));
    printf("\nSize of float %zu: " , sizeof(z));
    printf("\nSize of double %zu : " , sizeof(d));
    printf("\nSize of long double %zu : " , sizeof(u));
    printf("\nSize of char : %zu" , sizeof(w));
   
/* OUTPUT
Size of int : 4
Size of short int :2
Size of short  2:
Size of long int : 8
Size of long : 8
Size of float 4:
Size of double 8 :
Size of long double 16 :
Size of char : 1
*/
}
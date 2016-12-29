#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  const char *s = "dest://uri1";
  const char *s2 = "dest";
  char *temp;
//strstr (hay, needle)
  temp = strstr(s, s2);
  if ( temp  && temp == s )
    printf("%s", temp);
// strcmp
  char *str = "harshitha, awesome woman";
  if (strcmp (str, "harshitha is ") > 0)
    printf("%s", "it works");

// strtoken
  char *token =" ";
  // will not work
  //char *strk = "I am harshitha\0";
  char strk[] ="I am a woman in tech";
  char * p = strtok (strk, token);
  while(p != NULL )
  {
    printf ("token : %s  ", p);
    p = strtok(NULL, token);
  }

  printf("\n");
}

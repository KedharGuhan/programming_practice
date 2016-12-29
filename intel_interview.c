#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @input = abc  @output prints a,b,c,ab,bc, ac, abc
// this is the algorithm I came up with during the interview.
// I noticed that the solution is not printing all the combinations
void print_str(char*s , int start, int end)
{
  int k = 0;
  for (k = start;  k <= end; k++)
  {
    printf("%c", s[k]);
  }
  printf("\n");
}
void print_super_set(char* str)
{
  int len = strlen(str);
  int i = 0, j = 0, k = 0;
  char *s = str;
  // counter i - to keep track of the start of the string
  // counter j to keep track of end of the string
  for (i = 0; i <len; i++)
  {
    for (j = len-1; j >=i ;j--)
    {
      //  printing character starting at s and of length j
      print_str(s, i ,j);
    }
  }
}

// another method to print combinations


int main()
{
  char str[] = "abc";
  print_super_set(str);
}

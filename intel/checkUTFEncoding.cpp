#include <iostream>
#include <stdio.h>
#include <string>

int get_leading_ones (unsigned char* b, int start)
{
  int n = 0;
  unsigned char shifter = 1;
  // check from start,
  for (int i = 0; i <8 && b[start+i]!='\0' ;i++)
  {

    if (int (b[start+i] & shifter) == 1)
        n++;
    else
      break;
  }
  std :: cout << "\n leading ones are :" << n-1;
  return n-1;
}
bool check_valid_encoding (unsigned char* b)
{
  unsigned char shifter = 1;
  unsigned char current;
  std::cout <<"\nshifter is : " << int(shifter);
  // check starts with 0
  for ( int i = 0; b[i]!='\0';)
  {
    current = b[i];
    std::cout << "\ncurren is :" << b[i];
    std::cout << "\ni is :" << i;
    std::cout <<"\n" << int (current & shifter );
    if (int( current & shifter ) == 0)
    {
      std::cout <<" starts with 0";
      i+=8;
     }
     else{
       int n = get_leading_ones(b, i);
       std::cout << "leading ones's: " << n;
       i = i+8;
     }
  }
    return true;
}
int main ()
{
  unsigned char b[] = "0111111111111110";
  bool result = check_valid_encoding(b);
  std::cout << result;
}

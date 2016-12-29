#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using IntArray = vector<int>;

void swap(IntArray& arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

/*
+1 xxx xxx-xxxx
+91 xxx xxx-xxxx
+1xxx xxx-xxxx
+91xxx xxx-xxxx
*/
int delimeter(string& str, int off, string& res)
{
  while ( str[off] == ' ') {
      off--;
  }
  if ( str[off] != '-' ) {
      res += '-';
  }
  return off;
}
int get_country_code(string& str, int off, string& res)
{
  off = delimeter(str, off, res);
  while ( off >= 0 ) {
    if ( str[off] == '-' ) {
      res += '-';
    } else if ( str[off] == ' ' ) {
      res += '-';
    } else if ( str[off] == '+' ) {
      res += '+';
    } else {
      res += '*';
    }
    off--;
  }
  return off;
}

int get_middle_part(string& str, int off, string& res)
{
  off = delimeter(str, off, res);
  int r = 0, c = 3;
  while ( true ) {
      if ( str[off] == '-' ) {
        res += '-';
      } else if ( str[off] == ' ' ) {
        res += '-';
      } else {
        res += '*';
        r++;
      }
      off--;
      if ( r == c ) {
        break;
      }
  }
  return off;
}

int get_county_code(string& str, int off, string& res)
{
  off = delimeter(str, off, res);
  int r = 0, c = 3;
  while ( true ) {
      if ( str[off] == '-' ) {
        res += '-';
      } else if ( str[off] == '(' || str[off] == ')' ) {
        // make sure we look for ()
        r++;
        c = 5;
      } else if ( str[off] == ' ' ) {
        res += '-';
      } else {
        res += '*';
        r++;
      }
      off--;
      if ( r == c ) {
        break;
      }
  }
  return off;
}

string normalize_phone_number(string& str)
{
    string res("");
    if ( str.size() == 0 ) {
      return res;
    }
    for ( int i = 1; i <= 4; i++ ) {
        res.push_back(str[str.size()-i]);
    }
    int next = str.size() - 5;
    next = get_middle_part(str, next, res);
    next = get_county_code(str, next, res);
    if ( str[0] == '+' ) {
      next = get_country_code(str, next, res);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main(void)
{
    string input = "(333)444-5678";

    auto output = normalize_phone_number(input);
    cout << output << endl;
    return 0;
}

#include<iostream>
#include <vector>
#include <string>
using namespace std;
// substr(start , len)
// <name>harshitha</name>
// pos = 6
// k = 15
// k - pos = 9 = length of the string to be extracted
// remove ws before and after
//when to use length vs size for string
// 0123harsh91011 start = 4, end =8, len =

string process_ws(string  str)
{
  string ret;
  int start = 0;
  cout<<str;
  cout << "length : " <<str.length();
  int end = str.length()-1; // size or length()
  for (int i = 0; i<str.length(); i++){
    if (str[i] == ' ')
      start++;
    else
        break;
  }
  for( int i = end; i>=start;i--)
    if (str[i] == ' ')
      end--;
  cout <<"\nstart: " <<start;
  cout <<"\nend: " <<end;
  int len = (end-start+1);
  ret = str.substr(start, len);
  cout <<"\nprocessed str :" <<ret;
  return ret;
}
// problem with the code is that it has poor error handling
// and is hard coded values

vector<string> parse(vector<string> xmldata)
{
  // for each str, look for a starting '<name>' character and extract </name>
  string find_str ("<name>");
  int pos;
  vector<string> names;
  string str;
  for (int i = 0; i < xmldata.size(); i++ )
  {
    int len = xmldata[i].length();
    pos = xmldata[i].find( find_str );
    if ( pos != string::npos )
    {
      // the line is a name tag
      for (int k = xmldata[i].length()-1; k >=6; k--)
      {
        if (xmldata[i].at(k) == '<')
        {
          string nametag =xmldata[i].substr(6, k-6 );
          names.push_back(nametag);
          break;
        }
      }
    }
  }
  return names;
}
void print_name(vector<string>& names)
{
  vector<string>::iterator it;
  cout <<endl;
  for (it = names.begin();it!=names.end();it++)
  {
    cout<<*it <<" ";
  }
}
int main()
{
    // input is stored as a vector of strings
    vector<string>xmldata;
    string str;
    int N;
    cin >>N;
    int count = 0;
    while( count < N )
    {

      cin >> str;
      xmldata.push_back(str);
      count++;
    }
    vector<string> names = parse(xmldata);
    string sting_to_process="    4thpos2wsafter  ";
    process_ws(sting_to_process);
    print_name (names);
}

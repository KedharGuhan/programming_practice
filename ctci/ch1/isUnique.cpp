#include <iostream>
#include <string>
#include <map>
// implement an algorithm if a string has all unique characters
using namespace std;
bool is_unique(string& str)
{
    map<char, int> chars;
    map<char, int>::iterator it;
    for( int i = 0; i < str.length(); i++)
    {
        it = chars.find(str.at(i));
        if ( it== chars.end())
            chars[str.at(i)]++;
        else
            return false;
    }
    return true;
    
}

bool is_unique_bitmap(string& str)
{
    int bitmap = 0;
    for (int i = 0; i< str.length(); i++)
    {
        //left shift 1 by str.at(i) -'a' times
        // OR with bitmap and store it

        int value = 1;
        int times = str.at(i)-'a';
        value = value << times;
        if ((value & bitmap) == 0)
            bitmap = bitmap || (value <<times);
        else 
            return false;
    }
    return true;
}

bool is_unique2(char ch[], int len)
{
    bool arr[256]= {false};
    for (int i = 0; i<len;i++)
    {
        if ( !arr[ch[i]]) 
            arr[ch[i]] = true;
        else
            return false;   
    }
    return true;
}
int main()
{
    string str = "abcdef";
    bool isU   =    is_unique_bitmap(str);
    cout << "is Unique: "<<std::boolalpha<<isU;
    int i = 1;
    //Example of left shift    
    i = i<<2;
    cout << "left shift i "<<i;    
    
    char st[10] = "abcdefhh";
    isU = is_unique2(st, 8);
    cout << "is Unique: "<<std::boolalpha<<isU;
}

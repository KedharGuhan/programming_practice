#include <iostream>
#include <string>
using namespace std;

void swap ( char& a, char&b ){
    char t = a;
    a = b;
    b = t;
}
void reverse(string& str){
    int len = str.length();
    for (int i  = 0, j = len-1; i < j ; i++ , j-- ){
        swap(str[i] ,str[j]);
    }
    cout << str;
}
int main(){
    string str = "harshitha";
    reverse(str);
    cout << "rev = " << str;
}
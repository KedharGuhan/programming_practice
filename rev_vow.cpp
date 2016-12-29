#include <iostream>
#include <string>
using namespace std;
bool isVowel (char a) {
    if (a == 'a' || a =='e' || a== 'i' || a=='o' || a=='u')
        return true;
    return false;
}

string rev(string s){
    int start = 0;
    int end = s.length()-1;
    char temp;
    while (start <end ){
        if (isVowel(s.at(start)) && isVowel (s.at (end) ) ) {
           temp = s.at(end);
           s[end] = s[start];
           s[start] = temp; 
            start++;
            end--;
        }
        else if (!isVowel (s.at(start)))
                start++;
        else if (! isVowel (s.at(end)))
                end --;
    }
    cout << s;
    return s;
}


int main() {
    string s= " a i kk hello";
    s = rev(s);
    cout <<" output: " << s;    
}

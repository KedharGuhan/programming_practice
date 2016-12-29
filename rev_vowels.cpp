#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string reverseVowels(string s) {
        string vowels ("aeiou");
        string v;
        //map <int, char> pos;
        vector<int> pos (s.length());
        
        for (int i = 0; i< s.length(); i++ ){
            if ( vowels.find (s[i])!= string::npos){
                string d = s.at(i);    
                v.append(d);
                
                pos[i] = s[i];
            }
            else
                pos[i] = -1;
        }
        int count = 0;
        reverse( v. begin(), v.end());
        for ( int i = 0; i < s.length(); i++  ){
            if ( pos[i]!= -1)
                s[i] = v[count++];
        }
        cout <<s;
}
int main(){
    reverseVowels ("helllo");
    return 0;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int count[26];
    std::string s;
    std::getline(std::cin,s);
    for(int i=0;i<26;i++)
        count[i]=0;
    for(char c: s){
       
        if(c!=' '){
            if(c-'a'<0){
                count[c-'A']++;
                
            }
            else{
                count[c-'a']++;
                
            }
        }
        
    }

    bool pangram = true;
    for(int i = 0; i<26;i++){
        if(count[i]==0){
            pangram = false;
            break;
        }
    }
    if(pangram == true)
        cout<<"pangram";
    else cout<<"not pangram";
}


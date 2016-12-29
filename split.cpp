#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
int main(){
    
    string str;
    vector<string> vec;
    /*
    while ( cin>> str){
        vec.push_back(str);
    }
    */

    getline (cin, str, '\n');
    int j;
    for ( int i = 0; i< str.length(); i++){
        cout << str.at(i);   
    }

    // rem is used in stoi where its sets the position of the first char after the number
    string::size_type  rem;
    string::iterator it, itr;
    int i = 0;
    for ( it = str.begin(); it!= str.end(); ){
        // as long as white space , keep moving it
        while(*it == ' ')
                it++;
        // after the first non space, search for whitespce
        // itr denotes the whitespace

        itr = find( it, str.end(), ' ' );
        
        // finds the distance between it and itr whihc gives the lenght of the word
        j = distance(it, itr);
        cout << "length of word is : " <<j;

        // using substr to extract the word to num
        
        string num = str.substr(i,j);
       
        // stoi searches for number

        int n = stoi(str, &rem, 10);
        cout << n;
        
        str = str.substr(rem);
        it = str.begin();
        
        if (it == str.end())
            break;

    }

    cout << "vector pushedd";
}

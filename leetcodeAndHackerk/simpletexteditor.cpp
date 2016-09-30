#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    stack<string> events;
    string editor;
    string str, appendstr;
    int Q, operation, printN, pos;
    cin>>Q;
    events.push(editor);
    while(Q>0){
        cin>>operation;
        
        switch(operation){
            case 1: cin>>appendstr;
                    
                    editor.append(appendstr);
                   // cout<<"\nstring now"<<editor;
                   events.push(editor); 
                    break;
            case 2: cin>>printN;
                   // cout<<"\nlength of the string"<<str.length();
                   // cout<<"\ndeleting last "<<printN<<"characters";
                    
                    pos = editor.length()-printN;
                   // cout<<pos;
                    editor.erase(editor.begin()+pos, editor.end());
                    events.push(editor);
                    break;
            case 3: cin>>printN;
                    cout<<editor.at(printN-1)<<"\n";
                    break;
            case 4 : 
                      events.pop();
                     editor = events.top();           
        }
      //  cout<<"\ncurrent stack: "<<events.top();
        Q--;
    }
    return 0;
}



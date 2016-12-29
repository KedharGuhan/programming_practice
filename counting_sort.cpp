#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int* number;
    string* strings;
    int size;
    cin>>size;
    string str;
    
    number=new int[size];
    strings= new string[size];
    
    for(int i =0;i<size;i++){
        cin>>number[i];
        cin>>str;
        strings[i]=str;
    }
    
    int* counted_;
    counted_ = new int[size];
    
    for(int i =0;i<size;i++){
        counted_[number[i]]++;
    }
    int* shifted_;
    shifted_ = new int[size];
    cout<<"printing shifted";
    for(int i =1;i<size;i++){
        shifted_[i] = shifted_[i-1]+counted_[i-1];
       // cout<<shifted_[i]<<" ";
    }
    shifted_[0] = 0;
    
    string* sorted= new string[size];
    int* sorted_num = new int[size];
    bool* filled = new bool[size];
    for(int i =0;i<size;i++)
        filled[i]=false;
   
    int k, pos;
    for(int i =0;i<size;i++){
        pos = shifted_[number[i]];
       if(filled[pos]){
            for( k = pos+1;k<size;k++){
                if(!filled[k])
                    break;                   
            }
            pos = k;
       }
        filled[pos] = true;
        
        sorted[pos] = strings[i];
        sorted_num[pos] = i;
    }
    int half = size/2;
    for(int i =0;i<size;i++){
        if(sorted_num[i]>=half)
            cout<<sorted[i];
        else 
            cout<<"-";
        cout<<" ";
    }
    
    
}


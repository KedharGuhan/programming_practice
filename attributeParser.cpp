#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

void parseLine(vector<string>& words, string str){
    int i = 0,last = 0;
    while(str[i] != '<' && str[i] != '\0'){
        i++;
    }
    if(str[i] == '<') last = ++i;
    else return;

    while(str[i]!='\0'){
        if(str[i] == ' ' || str[i] == '>'){
            string temp = str.substr(last,i-last);
            if(temp.length()){
				words.push_back(temp);
				//cout<<"Pushed:"<<temp<<endl;
            }
            i++;
            while(str[i] == ' ')
                i++;
            last = i;
            continue;
        }
        if(str[i] == '"'){
        	last = i+1;
        	i++;
        	while(str[i] != '"' && str[i] != '\0')
        		i++;
      		string temp = str.substr(last,i-last);
       		//cout<<"Pushed:"<<temp<<endl;
       		words.push_back(temp);
       		i++;
        	while(str[i] == ' ')
        		i++;
        	last = i;
        	continue;
        }
        i++;
    }
}
void parseWords(map<string, string>& tagmap, vector<string>& words,string curtag){
    for(int i=1;i<(int)words.size();i+=3){
        string temp = curtag + "~" + words[i];
        tagmap[temp] = words[i+2];
        //cout<<"Added "<<words[i+2]<<" to key "<<temp<<endl;
    }
}
void parseHrml(map<string,string>& tagmap, vector<string>& hrml, int N){
    vector<string> words;
    stringstream tagstream;
    vector<string> tags;
    for(int i=0;i<N;i++){
        parseLine(words,hrml[i]);
        if(words.size() == 0)
            continue;
        if(words[0][0] =='/')
        {
        	string tag = words[0].substr(1);
        	if(tags.size() != 0 && tag.compare(tags.back()) == 0)
        	{
        		//cout<<"Popping "<<tags.back()<<" from tag list!"<<endl;
        		tags.pop_back();
        	}
            tagstream.str("");
            words.clear();
            continue;
        }
        else
        {
        	//cout<<"Pushing "<<words[0]<<" as a tag!"<<endl;
        	tags.push_back(words[0]);
        }
        tagstream<<tags[0];
        for(int j=1;j<(int)tags.size();j++)
        	tagstream<<"."<<tags[j];
        parseWords(tagmap, words, tagstream.str());
        words.clear();
        tagstream.str("");
    }
}
void getQueries(vector<string>& hrml, vector<string>& queries, int N, int Q){
    map<string,string> tagmap;
    parseHrml(tagmap, hrml, N);
    for(int i=0;i<Q;i++){
        if(tagmap.find(queries[i]) == tagmap.end())
            cout<<"Not Found!"<<endl;
        else
            cout<<tagmap[queries[i]]<<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,Q;
    cin>>N;
    cin>>Q;
    vector<string> hrml(N);
    vector<string> queries(Q);
    string temp;
    getline(cin,temp);

    for(int i=0;i<N;i++)
    	getline(cin, hrml[i]);

    for(int i=0;i<Q;i++)
        getline(cin, queries[i]);

    getQueries(hrml, queries, N, Q);
    return 0;
}


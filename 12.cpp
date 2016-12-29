#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <fstream>

#include <map>
/* Notes and todos
 * The Employee class contains a list of friends
 */


using namespace std;
class emp{
    public:
    string id; // id
    string name; // name
    string dept; // dept
    vector<emp> adjList; // contains list of friends
    emp(string i, string n, string d){
        id = i;
        name = n;
        dept = d;

    }
    emp(){
    }
    void addFriend(emp b){
        bool present = false;
        vector<emp>::iterator it = adjList.begin();
        while(it!= adjList.end()){
            if ((*it).id == b.id)
                present = true;
            it++;
        }
        if (!present)
            adjList.push_back(b);
    }
    string print_friends(){
        string ret;
        ret.append(id);
        if ( adjList.size() == 0)
            ret.append(": None");
        else ret.append(": ");
        for (vector<emp>::iterator it = adjList.begin(); it!=adjList.end(); it++ )
        {
            emp x = *it;
            if (it == adjList.begin())
                ret.append( x.id);
            else{
                ret.append(",");
                ret.append(x.id);
            }
        }
        return ret;
    }
    void print_emp(){
        cout << id << name << dept <<endl;
    }
};

vector<string> find_adj( map<string, emp> maprep, vector<pair<string,string> > relation){
    vector<pair<string, string> >::iterator vec_it = relation.begin();
    
    vector<string> ret; 
    string id1, id2;
    map<string, emp>::iterator itu, itv;
    emp v, u;
    
    for (; vec_it != relation.begin(); vec_it++){
    	id1 = vec_it->first;
	    id2 = vec_it->second;
        
        itu = maprep.find(id1);
        if(itu!= maprep.end())
             u = itu->second;
        
        itv = maprep.find(id2);
        if (itv!= maprep.end())
            v = itv->second;
        
        if (itv!= maprep.end() && itu!=maprep.end() ){
            u.addFriend(v);
            v.addFriend(u); 
            maprep.erase(itu);
            maprep.erase(itv);
            maprep.insert(make_pair(u.id,u));
            maprep.insert(make_pair(v.id, v));
        }
    }
    map<string, emp>::iterator it;
    for ( it = maprep.begin(); it!=maprep.end(); it++){
         emp u = it->second;
         ret.push_back(u.print_friends());
    }

    return ret;
}

int main(){
    
    string num, name, dept;
    string str, stri;
    string id1, id2;
    ifstream empfile("employee.csv");
    ifstream fr("friendships.csv");
    vector<pair<string, string> >relation;
    int count = 0;
    int kk;
    //reading the header
    getline(empfile, str);
    getline(fr,stri); 
    //reading the file
    
    // mapping of id's with employees
    map<string, emp > maprep;
    
    while(empfile.good()){
        getline(empfile, num, ',');
        getline(empfile, name, ',');
        getline(empfile, dept, '\n');
        if (empfile.eof())
            break;
        emp e (num, name, dept);
        maprep.insert(make_pair(num, e));
        count++;
    }


    map<string, emp>::iterator itu, itv;
    emp v, u;
    while(fr.good() && !fr.eof()){
        fr >> str;
        int strlength = str.length();
        kk = 0;
        while(kk < str.length()){
            if (str.at(kk) == ',')
                break;
            kk++;
        }
        id1 = str.substr(0, kk);
               
        id2 = str.substr(kk+1, str.length()-kk);
        
	relation.push_back(make_pair(id1,id2));
        itu = maprep.find(id1);
        if(itu!= maprep.end())
             u = itu->second;
        
        itv = maprep.find(id2);
        if (itv!= maprep.end())
            v = itv->second;
        
        if (itv!= maprep.end() && itu!=maprep.end() ){
            u.addFriend(v);
            v.addFriend(u); 
            maprep.erase(itu);
            maprep.erase(itv);
            maprep.insert(make_pair(u.id,u));
            maprep.insert(make_pair(v.id, v));
        }
        if (fr.eof())
            break;
    }
    // printitng all the relationships
    //
    map<string, emp>::iterator it; 
    for ( it = maprep.begin(); it!=maprep.end(); it++){
        emp u = it->second;
        u.print_friends();
    }
    return 0;
}

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int min_window(string t, string s){
    
    int min_window = s.size();
    int win_start, win_end;
    map<char, int> mapt;
    bool start_found = false;
    vector<pair<int,int> > windows ;
    map<char, int>::iterator it;
    for (int k = 0; k< t.size(); k++){
        mapt[t.at(k)]++;
    }


    for ( int i = 0; i < s.size()-t.size(); i++ )
    {
        it = mapt.find (s.at(i));
        if (it != mapt.end())
        {
            mapt[s.at(i)]--; 
            if (mapt[s.at(i)] == 0)
                 mapt.erase(it);

            for ( int j = i; j < s.size(); j++) {
                cout << "\ncurrent map size " << mapt.size();
                it = mapt.find ( s.at(j) );
                if ( it!= mapt.end() ){
                   
                    cout << "\nfound " << s.at(j) << "with i = " << i << " and j = " << j;
                    mapt[s.at(j)]--;
                    if (mapt[s.at(j)] == 0 )
                        mapt.erase(it);
                }
                if ( mapt.size() == 0 ){
                    windows.push_back(make_pair(i, j));
                    for (int k = 0; k< t.size(); k++){
                        mapt[t.at(k)]++;
                    }

                    break;
                }
            }    

        }
    }   
    
    for ( vector<pair<int,int> >::iterator it = windows.begin(); it!= windows.end(); it++ ){
        pair<int,int> p = *it;
        cout << "\n" << p.first << "  " << p.second;
    } 
    return min_window;
}
int main(){
 
    min_window("ard", "avadakedavra");   
    
}

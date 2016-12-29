#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <map>
using namespace std;

int withinTime(time_t uts){
    tm *ts;
    ts = gmtime (&uts);
    if ( ts->tm_year+1900 != 2016 )
        return 10;
    if (ts->tm_mon+1 == 6 && ts->tm_mday >15)
        return 20;
    if (ts->tm_mon+1 == 7 && ts->tm_mday <15 )
        return 20;
    if ((ts->tm_mon+1) <6 || (ts->tm_mon+1) >7)
        return 10;
    return 10;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // n : number of passions
    // m : no of reviews
    
    
    int n,m;
    cin>> n >> m;
   
    vector<string> passions(100);
    for (int i = 0;i< n;i++){
        cin >> passions[i];
        transform(passions[i].begin(), passions[i].end(), passions[i].begin(), ::tolower);
        
    }
        
    map<string, int > pointsMap;
    map<string, int>::iterator it;
    string review;
    int id;
    int points;
    time_t uts;
    string findstr;
    for (int i = 0; i<m; i++ ){
        cin >> id; 
        cin >> uts;
        points = withinTime(uts);
        cin.ignore();
        getline (cin , review, '\n');
        if (review.length() >= 100 )
            points+=20;
        else if (review.length()>0 && review.length() <100 )
            points+=10;
        transform(review.begin(), review.end(), review.begin(), ::tolower);
        //finding the passion in the text;
        for (int j = 0; j < n;j++){
            if ( review.find(passions[j])!=string::npos){
                findstr  = to_string(id)+ ","+ to_string(j); //reviewerID+ passion
                it = pointsMap.find (findstr);
                if (it!= pointsMap.end())
                    points+=it->second;
                pointsMap.insert (make_pair(findstr,points));
            }
        }       
    }
    
    it = pointsMap.begin();
  
    int pointsArr[n];
    int revId[n];
    for (int i = 0; i<n; i++){
        revId[i] = -1;
        pointsArr[i] = -1;
    }
    
    map<int, int>::iterator maxIt;
    // finding highest reviewer
    for (it = pointsMap.begin(); it!=pointsMap.end();it++){
        string f = it->first;
        string r = it->first;
        std::string::size_type sz; 
        int pos = f.find(',');
  
        f = f.substr(pos+1, f.length());
        r = r.substr (0, pos);
  
        string topicStr;
        int reviewerId = stoi (r, nullptr, 10);
 
        int topic = stoi(f, nullptr,10);
        if (pointsArr[topic] < it->second){
            pointsArr[topic] =it->second;
            revId[topic] = reviewerId;
        }else if (pointsArr[topic] == it->second){
         // points are equal, check id, take the smallest Id
            if ( revId[topic] > reviewerId )
                revId[topic] = reviewerId;
        }
      
    }
    
    for (int i = 0; i<n; i++){
        cout <<revId[i] << "\n";
    }
    
    return 0;
}


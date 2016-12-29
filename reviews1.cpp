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
    if (ts->tm_mon+1 == 6 && ts->tm_mday >=15)
        return 20;
    if (ts->tm_mon+1 == 7 && ts->tm_mday <15 )
        return 20;
    if (ts->tm_mon+1 == 7 && ts->tm_mday ==15 && ts->tm_hour == 0 && ts->tm_min == 0 && ts->tm_sec == 0)
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
    //	cout << "\n" <<passions[i];
	}

        
    map<string, int > pointsMap;
    map<string, int>::iterator it;
    string review;
    int id;
    int points=0;
    time_t uts;
    int newpoints;
    string findstr;
    for (int i = 0; i<m; i++ ){
	points = 0;
        cin >> id; 
        cin >> uts;
        points = withinTime(uts);
        cin.ignore();
        getline (cin , review, '\n');
        if (review.length() >= 100 )
            points+=20;
        else 
            points+=10;
        transform(review.begin(), review.end(), review.begin(), ::tolower);
        //finding the passion in the text;
        for (int j = 0; j < n;j++){
            newpoints = points;
            if ( review.find(passions[j])!=string::npos ){
                findstr  = "_"+to_string(id)+ ","+ to_string(j)+"_"; //reviewerID+ passion
                it = pointsMap.find (findstr);
                if (it!= pointsMap.end()){
			//cout <<"\nfindstr already exists" <<it->first<<" :"<<it->second;
			//cout <<"\nadding points: " <<points;
			newpoints+= it->second;	
			//points+=it->second;
			pointsMap.erase(it);
		}
		//cout <<"\nadding new to map" <<findstr << " : " <<points;
                pointsMap.insert (make_pair(findstr,newpoints));
		}
        }       
    }
    
    it = pointsMap.begin();
  //   for (;it!=pointsMap.end();it++)
	//cout <<"\n reviewerId_passion: "<<it->first <<" points: "<<it->second;  
    int pointsArr[n];
    int revId[n];
    for (int i = 0; i<n; i++){
        revId[i] = -1;
        pointsArr[i] = -1;
    }
    
    map<int, int>::iterator maxIt;
    // finding highest reviewer
   // reviewId_topicInt	
    for (it = pointsMap.begin(); it!=pointsMap.end();it++){
        string f = it->first;
        string r = it->first;
        std::string::size_type sz; 
        int pos = f.find(',');
        f = f.substr(pos+1, f.length()-1);
        r = r.substr (1, pos);
      //  cout << "\nf: "<< f<<" r: " <<r <<" points " << it->second;
	int reviewerId = stoi (r, nullptr, 10);
        int topic = stoi(f, nullptr,10);
        if (pointsArr[topic] < it->second){
            pointsArr[topic] = it->second;
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


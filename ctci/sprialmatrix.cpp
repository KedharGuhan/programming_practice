#include <iostream>
#include <vector>
#include <map>
using namespace std;
void print_vector(vector<int> v , int len ){
    for (int i = 0; i < len; i++)
        cout << v.at(i) << "\t";
}

void down(int starti, int startj , int m, int n, vector<vector<int> > matrix){
   cout  << "\n down";
   if (  startj <= n )
   {
       for (int i = starti; i <= m; i++ )
        cout << matrix[i].at(n) << " ";
   }
}

void right(int starti, int startj , int m, int n, vector<vector<int> > matrix){
    cout << "right ";
    if (starti <= m )
    {
        for (int j = startj; j <= n; j++ )
            cout << matrix[starti].at(j) << " ";
    }
}

void left(int starti, int startj , int m, int n, vector<vector<int> > matrix){
    cout << "left";
    if (starti<= m ) {
        for (int j = n; j >=startj; j--)
            cout << matrix[m].at(j) << " ";
    }
}

void up(int starti, int startj , int m, int n, vector<vector<int> > matrix){
 //   cout << " i = " << m;
 //   cout << "starti = " <<starti;
    cout << "up";
    if ( startj <= n )
    {
        for (int i = m; i >=starti; i--)
            cout << matrix[i].at(startj) << " ";
    }
}   

void print_sprial( vector<vector<int> >matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0, j = 0;
    int endi, endj;
    m--;
    n--;
    endi = m;
    endj = n;
    cout <<" m:" << m <<" n: " <<n;
    while ( i <= endi || j <= endj ){
        right(i,j, endi,endj, matrix); 
        down(i+1,j,endi,endj,matrix);
        left(endi,j, endi,endj-1, matrix);
        up(i+1,j,endi-1,endj,matrix);
        i++;
        j++;
        endi--;
        endj--;
    }
}
int main(){

    vector<int> row1= {1,2};
    vector<int> row2 = {4,5,6};
    vector<int> row3 = {7,8,9};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    //matrix.push_back(row2);
    //matrix.push_back(row3);
    print_sprial(matrix);
    
}
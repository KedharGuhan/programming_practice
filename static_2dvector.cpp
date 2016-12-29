#include <vector>
#include <iostream>

using namespace std;

class A {
};

int main(void)
{
    vector<int> intv;

    intv.push_back(1);
    cout << intv[0] << endl;

    vector<vector<int>> intvv;

    // goal is to insert item 1 in first vector in intvv
    vector<int> t;
    intvv.push_back(t); 

    intvv[0].push_back(1);
    return 0;
}

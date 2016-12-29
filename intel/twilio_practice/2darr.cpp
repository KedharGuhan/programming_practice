#include <iostream>
using namespace std;
void init_1d_array()
{
    int *a = new int[3];
    cout << sizeof(a);
    delete []a;
}
void init_2d_array(){
    int *a = new int[2];
    int **b = &a;

    cout << " a: " << a;
    cout << " b: " << b;
    cout << "&a: " << &a;
    cout << " a[0]: "<< &a[0];

}
int main(){
    init_1d_array();
    init_2d_array();
}
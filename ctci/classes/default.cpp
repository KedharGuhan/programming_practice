#include <iostream>

void callDefault(int a, int b= 8)
{
    int y = a+b;
    std::cout << y << std::endl;
}
int main()
{
    callDefault(4);
    callDefault(4, 5);
}

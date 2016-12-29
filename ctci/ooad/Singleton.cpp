#include <iostream>
class Singleton{
        static Singleton *s_obj;
    public:
        static Singleton* getInstance()
        {
            if ( s_obj == NULL ) {
                s_obj = new Singleton();
            }
            return s_obj;
        }
};

//type class::variable = value;
Singleton* Singleton::s_obj = NULL;

int main()
{
    Singleton *s = Singleton::getInstance(); 
}

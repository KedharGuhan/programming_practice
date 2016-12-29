#include <iostream>
using namespace std;

#define MAX_SIZE 50

class Person {
    int id;
    char name[30];
 public:
    Person (int a)
    {
        id = a;
    }
    virtual void aboutMe()
    {
        cout << "\nI am a person";
    }
    //pure virtual function makes Person as abstract class
    virtual void addCourse(string s)= 0;
    virtual ~Person()
    {
        cout << "\ncalling destructor of Person" << std::endl;
    }

};

class Student : public Person {
 public :
    Student (int x, int y): Person(y)
    {
    }
    void aboutMe()
    {
        cout <<"\nI am a student ";
    }
    void addCourse(string s)
    {
        cout << "\nadding course ";
    }
    ~Student()
    {
        cout << "\ncalling destructor of Student "<< std::endl;
    }

};

int main()
{   /* static binding */
    /*
    Student * p = new Student(1,2);
    p->aboutMe();
    p->addCourse(string("str"));   
    Student c(1,2) ;
    delete p;
    */
    // dynamic binding 
    // calls destructor of Person when destructor is not virtual  
    // calls person aboutMe function if aboutMe is not declared virtual
    Person * q = new Student(3,4);
    q->aboutMe();
    q->addCourse(string("st"));
    delete q;
    return 0;
}


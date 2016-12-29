#include <iostream>
using namespace std;
class HashEntry{
    private: 
        int key, value;
    public:
        HashEntry(int key, int value){
            this->key = key;
            this->value = value;
        }
        int getKey(){
            return key;
        }
        int getValue(){
            return value;
        }
};
const int SIZE=128;

class HashMap{
    //pointer to an array of key value pairs
    private: 
        HashEntry** table;
    public:
        HashMap(){
            //table is a pointer to an array of HAshEntry* of size SIZE
            table = new HashEntry*[SIZE];
            for (int i = 0 ; i < SIZE; i++ )
                table[i] = NULL;
        }   
        int get(int key){
            int hash = key%SIZE;
            while( table[hash]!= NULL && table[hash]->getKey()!=key)
                hash = (hash+1)%SIZE;
            if (table[hash] ==  NULL )
                return -1;
            else
                return table[hash]->getValue();
            
        }
        int put(int key, int value){
            int hash = key%SIZE;
            while (table[hash]!=NULL && table[hash]->getKey()!=key)
                hash = (hash+1)%(SIZE);
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key,value);

        }
        ~HashMap()
        {
            for (int i = 0; i< SIZE;i++)
                if (table[i]!= NULL)
                    delete table[i];
            delete[] table;
        }
};
int main(){
    HashMap* maps = new HashMap();
    maps->put(1,2);
    maps->put (1,3);
    cout << maps->get(1);
}
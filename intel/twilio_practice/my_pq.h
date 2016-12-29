#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;
class PQ{
    int* entry;
    int size;
    int cur_size;

    public :

        PQ(int size){
           this->size = size;
           int *entry = new int[size];
        }
        PQ(int arr[], int len){
            this->size = len+1;
            int *entry = new int[size];
            for (int i = 0; i < len; i++){
                    entry[i+1] = arr[i];
            }

            for (int i = size/2; i > 0; i--){
                int right = get_right_child(i);
                int left = get_left_child(i);
                int lesser, lesser_value;
                if ( left == -1 || right == -1){
                   lesser = right > left ? right: left;
                   lesser_value = entry[lesser];
                }
                if (left == -1 && right)
                        continue;
                else{
                    lesser_value = entry[right] < entry[left] ? entry[right] : entry[left];
                    lesser = entry[right] < entry[left] ? right:  left;
                }
                if (entry[i]  > lesser ){
                    swap (entry[i], entry[lesser]);
                }
            }
        }
        
        
        void insert(int entry){
            
        }
        void swap(int &a, int&b){
            int t = a;
            a = b;
            b = t;
        }
        
        void print(){
            for (int i = 1; i< size; i++){
                cout << entry[i] << " " ;
            }
            cout << endl;
        }
        int getMin(){
            if (cur_size >=1 )
                return entry[1];
            else return INT_MIN; 
        }
        void deleteMin(){

        }
        void heapify(){

        }
        int get_parent(int i){
            if ( i/2 > 0 )
                return i/2; 
            return -1;
        }
        int get_right_child( int i){
            if ((2*i)+1 < size)
                return 2*i+1;
            return -1;
        }
        int get_left_child( int  i){
            if (2*i < size)
                return 2*i;
            return -1;
        }
  
};

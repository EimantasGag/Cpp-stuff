#include <iostream>

using namespace std;

struct LinkedList{
    LinkedList* next;
    int value;

    LinkedList(int avalue){
        value = avalue;
    }
};

struct SortedList{
    LinkedList* first;

    void addValue(int num){
        if(first == NULL){
            first = &LinkedList(num);
        }
        else{
            if(first->value > num){
                
            }
        }
    }
};

int main(){

}
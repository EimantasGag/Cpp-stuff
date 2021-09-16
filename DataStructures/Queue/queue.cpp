#include <iostream>
#include <vector>

using namespace std;

struct Queue{
    int data;
    int first = 0;
    vector<int> queue;

    bool isEmpty(){
        return queue.size() <= first;
    }

    void enqueue(int num){
        queue.push_back(num);
    }

    int dequeue(){
        if(!isEmpty()){
            return queue[first++];
        }
        throw exception();
    }

    int getFirst(){
        if(!isEmpty()){
            return queue[first];
        }
        throw exception();
    }
};

int main(){
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    cout << queue.getFirst() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(30);
    cout << queue.getFirst() << endl;
}
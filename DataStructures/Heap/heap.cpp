#include <bits/stdc++.h>

using namespace std;

struct MinHeap{
    private:

    vector<int> heap_arr;
    int heap_size = 0;

    int right(int i){
        if((i*2)+2 < heap_size && (i*2)+2 >= 0){
            return heap_arr[(i*2)+2];
        }
        else{
            return INT_MIN;
        }
    }

    int left(int i){
        if((i*2)+1 < heap_size && (i*2)+1 >= 0){
            return heap_arr[(i*2)+1];
        }
        else{
            return INT_MIN;
        }
    }

    int parent(int i){
        if((i-1)/2 < heap_size && (i-1)/2 >= 0){
            return heap_arr[(i-1)/2];
        }
        else{
            return INT_MIN;
        }
    }

    int getParentIndex(int i){
        if((i-1)/2 < heap_size && (i-1)/2 >= 0){
            return (i-1)/2;
        }
        else{
            return INT_MIN;
        }
    }

    int getLeftIndex(int i){
        if((i*2)+1 < heap_size && (i*2)+1 >= 0){
            return (i*2)+1;
        }
        else{
            return INT_MIN;
        }
    }

    int getRightIndex(int i){
        if((i*2)+2 < heap_size && (i*2)+2 >= 0){
            return (i*2)+2;
        }
        else{
            return INT_MIN;
        }
    }

    void swap(int a, int b){
        int save = heap_arr[a];
        heap_arr[a] = heap_arr[b];
        heap_arr[b] = save;
    }

    void heapify(){
        for(int i = heap_size-1;i>=0;i--){
            if(parent(i) > heap_arr[i] && parent(i) != INT_MIN){
                swap(i,getParentIndex(i));
            }
        }
    }

    void heapify(int i){
        if(parent(i) != INT_MIN && parent(i) > heap_arr[i]){
            swap(getParentIndex(i), i);
            return heapify(getParentIndex(i));
        }
        else if(left(i) != INT_MIN && left(i) < heap_arr[i] && right(i) > left(i)){
            swap(getLeftIndex(i),i);
            return heapify(getLeftIndex(i));
        }
        else if(right(i) != INT_MIN && right(i) < heap_arr[i] && left(i) > right(i)){
            swap(getRightIndex(i),i);
            return heapify(getRightIndex(i));
        }
    }

    public:

    bool isEmpty(){
        return heap_size == 0;
    }

    void addKey(int key){
        if(heap_size < heap_arr.size()){
            heap_arr[heap_size] = key;
        }
        else{
            heap_arr.push_back(key);
        }
        

        heap_size++;
        heapify();
    }

    void updateKey(int index, int new_val){
        if(index <= heap_size-1){
            heap_arr[index] = new_val;
        }
        heapify();
    }

    int extractMin(){
        if(heap_size == 0){
            return INT_MIN;
        }
        else if(heap_size == 1){
            heap_size--;
            return heap_arr[0];
        }

        //gauni minimuma ir tada panaikini ji 

        int min = heap_arr[0];
        heap_arr[0] = heap_arr[heap_size-1];
        heap_size--;
        heapify();

        return min;
    }
};

int main(){
    MinHeap heap;
    heap.addKey(10);
    heap.addKey(8);
    heap.addKey(8);
    heap.addKey(6);

    heap.updateKey(0, 12);

    cout << heap.extractMin() << endl;
    cout << heap.extractMin() << endl;
    cout << heap.extractMin() << endl;
    cout << heap.extractMin() << endl;
}
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int knapsack(const vector<int>& profits, const vector<int>& weights, int** lookup, int capacity, int index = 0, int profit = 0){
    if(profits.size() == 0){
        return 0;
    }

    if(index >= profits.size() || capacity == 0){
        return profit;
    }

    if(lookup[index][capacity] != -1){
        return lookup[index][capacity];
    }

    if(weights[index] > capacity){
        lookup[index][capacity] = knapsack(profits, weights, lookup, capacity, index+1, profit);
        return lookup[index][capacity];
    }
    else{
        lookup[index][capacity] = max(
            knapsack(profits, weights, lookup, capacity-weights[index], index+1, profit+profits[index]),
            knapsack(profits, weights, lookup, capacity, index+1, profit)
        );

        return lookup[index][capacity];
    }
}

int** _initialize(int size1, int size2){
    int** lookup;
    lookup = new int*[size1];

    for(int i = 0;i<size1;i++){
        lookup[i] = new int[size2];
    }

    for(int i = 0;i<size1;i++){
        for(int x = 0;x<size2;x++){
            lookup[i][x] = -1;
        }
    }

    return lookup;
}

struct LinkedList{
    int capacity;
    int profit;
    LinkedList* next;
};

int getProfit(LinkedList* l, int cap){
    LinkedList* cur = l;

    while(true){
        if(cur->capacity == cap){
            return cur->profit;
        }

        if(cur->next == NULL){
            return INT_MIN;
        }

        cur = cur->next;
    }
}

LinkedList* getEmptyNode(LinkedList* l){
    LinkedList* cur = l;

    while(true){
        if(cur->next == NULL){
            cur->next = new LinkedList();
            return cur->next;
        }
        else{
            cur = cur->next;
        }
    }
}

vector<LinkedList*> lookup;
int lookup_size = 0;

int knapsack2(const vector<int>& profits, const vector<int>& weights, int profits_size, int weights_size, int capacity, int index = 0, int profit = 0){
    if(profits_size == 0){
        return 0;
    }

    if(index >= profits_size || capacity == 0){
        return profit;
    }

    //if memProfit is equal to INT_MIN, the index with
    //current capacity haven't occured previously

    int memProfit = INT_MIN;

    if(index < lookup_size){
        memProfit = getProfit(lookup[index], capacity);
    }

    if(memProfit != INT_MIN){
        return memProfit;
    }

    LinkedList* cur;

    if(lookup_size <= index){
        lookup_size++;
        lookup.push_back(new LinkedList());
        cur = lookup[index];
    }
    else{
        cur = getEmptyNode(lookup[index]);
    }

    if(weights[index] > capacity){
        cur->capacity = capacity;
        cur->profit = knapsack2(profits, weights, profits_size, weights_size, capacity, index+1, profit);
        cur->next = NULL;

        return cur->profit;
    }
    else{
        cur->capacity = capacity;
        cur->profit = max(
            knapsack2(profits, weights, profits_size, weights_size, capacity-weights[index], index+1, profit+profits[index]),
            knapsack2(profits, weights, profits_size, weights_size, capacity, index+1, profit)
        );
        cur->next = NULL;

        return cur->profit;
    }
}

vector<int> generateRandomArray(int size){
    vector<int> vec;

    for(int i = 0;i<size;i++){
        vec.push_back(rand() % 501);
    }

    return vec;
}

int main(){
    srand (time(NULL));

    vector<int> profits = generateRandomArray(20);
    vector<int> weights = generateRandomArray(20);
    int capacity = rand() % 100000 + 10000;

    auto start = high_resolution_clock::now();
    cout << "Res: " << knapsack2(profits, weights, profits.size(), weights.size(), capacity) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << endl;

    start = high_resolution_clock::now();
    int** lookup = _initialize(profits.size(), capacity+1);
    cout << "Res: " << knapsack(profits, weights, lookup, capacity) << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << endl;
}
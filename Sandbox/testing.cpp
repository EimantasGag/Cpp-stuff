#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

struct LinkedList{
    LinkedList* next;
    int number;

    LinkedList(int n){
        number = n;
    }
};

int countRuntime(LinkedList* head, void (*func)(LinkedList*)){
    auto start = high_resolution_clock::now();

    func(head);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
}

int countRuntime(vector<int>& arr, void (*func)(vector<int>&)){
    auto start = high_resolution_clock::now();

    func(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;
}

void cutArray(vector<int>& arr){
    while(arr.size() > 2){
        arr.erase(arr.begin()+1);
    }
}

void cutLinkedList(LinkedList* head){
    while(true){
        if(head->next != NULL){
            if(head->next->next != NULL){
                head->next = head->next->next;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
}

int main(){
    vector<int> numbers;
    LinkedList* head;
    LinkedList* prev;

    for(int i = 0;i<9000000;i++){
        numbers.push_back(i+1);

        if(i == 0){
            head = new LinkedList(i+1);
            prev = head;
        }
        else{
            prev->next = new LinkedList(i+1);
            prev = prev->next;
        }
    }

    prev->next = NULL;

    countRuntime(head, &cutLinkedList);
    //countRuntime(numbers, &cutArray);
}
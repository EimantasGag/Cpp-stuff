#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

struct Job{
    int a,b,c;
};

bool compare(Job a,Job b){
    return a.c < b.c;
}

struct LinkedList{
    string data;
    LinkedList* next = NULL;

    LinkedList(string d){
        data = d;
    }
};

void change(LinkedList *start){
    start = start->next;
}

int main(){
    vector<string> strings = {"nice","niceone","goodone"};
    LinkedList start = LinkedList(strings[0]);
    LinkedList* cur = &start;
    cout << &cur << " " << &start << endl;
    
    for(int i = 1;i<strings.size();i++){
        cur->next = new LinkedList(strings[i]); 
        cur = cur->next;
    }

    cur = &start;

    while(1){
        if(cur->next == NULL){
            cout << cur->data << endl;
            break;
        }
        else{
            cout << cur->data << endl;
        }
        cur = cur->next;
    }

    change(&start);
    //start = *start.next;

    cout << start.next->data << endl;
}
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

struct LinkedList{
    string data;
    LinkedList* next;

    LinkedList(string d){
        data = d;
    }
};

void printList(LinkedList* cur){
    cout << "Data in the LinkedList: ";
    while(1){
        cout << cur->data << " ";
        
        if(cur->next == NULL){
            break;
        }

        cur = cur->next;
    }
    cout << endl;
}

LinkedList lol(string s){
    return LinkedList(s);
}

int main(){
    vector<string> strings = {"nice","niceone","goodone"};
    LinkedList start = LinkedList(strings[0]);
    LinkedList* cur = &start;
    
    for(int i = 1;i<strings.size();i++){
        cur->next = new LinkedList(strings[i]); 
        cur = cur->next;
    }

    cur->next = NULL;

    printList(&start);
}
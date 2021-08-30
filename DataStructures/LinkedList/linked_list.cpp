#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

struct LinkedList{
    string data;
    LinkedList* next = NULL;

    LinkedList(string d){
        data = d;
    }
};

int main(){
    vector<string> strings = {"nice","niceone","goodone"};
    LinkedList start = LinkedList(strings[0]);
    LinkedList* cur = &start;
    
    for(int i = 1;i<strings.size();i++){
        cur->next = new LinkedList(strings[i]); 
        cur = cur->next;
    }

    cur = &start;

    while(1){
        cout << cur->data << endl;
        
        if(cur->next == NULL){
            break;
        }

        cur = cur->next;
    }
}
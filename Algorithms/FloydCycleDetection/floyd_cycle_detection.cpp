#include <bits/stdc++.h>

using namespace std;

struct LinkedList{
    int data;
    LinkedList* next;
};

bool floyd(LinkedList* head){
    LinkedList* slow = head;
    LinkedList* fast = head;

    while(true){
        if(fast->next == NULL || fast->next->next == NULL){
            return false;
        }

        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }
}

int main(){
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();
    LinkedList* l3 = new LinkedList();
    LinkedList* l4 = new LinkedList();

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = NULL;

    cout << floyd(l1);
}
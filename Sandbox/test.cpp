#include <bits/stdc++.h>

using namespace std;

struct Node{
    int num;
    int val;

    Node(int a, int n){
        num = a;
        val = n;
    }
};

int main(){
    priority_queue<Node*> pq;
    pq.push(new Node(10,20));
    pq.push(new Node(20,10));
    cout << pq.top()->num << endl;
}
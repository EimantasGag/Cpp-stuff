//https://www.hackerrank.com/challenges/is-binary-search-tree/problem?isFullScreen=true
//#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkBST(Node* root) {
    if(root->left->data >= 0 && root->left->data <= 10000){
        if(root->left->data >= root->data){
            return false;
        }
        
        if(checkBST(root->left) == false){
            return false;
        }
    }
    if(root->right->data >= 0 && root->right->data <= 10000){
        if(root->right->data >= root->data){
            return false;
        }
        
        if(checkBST(root->right) == false){
            return false;
        }
    }
    
    return true;
}
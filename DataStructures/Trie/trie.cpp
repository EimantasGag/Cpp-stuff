#include <bits/stdc++.h>

using namespace std;

//PAGAL ANGLISKA ABECELE - 26 RAIDES
const int ALPHABET_LETTERS = 26;

struct TrieNode{
    TrieNode* children_arr[ALPHABET_LETTERS];
    bool isWordEnd = false;

    void initialize(){
        for(int i = 0;i<ALPHABET_LETTERS;i++){
            children_arr[i] = NULL;
        }
    }

    int getLetterIndex(const char a){
        int index = int(a);

        if(index >= 97){
            index -= 97;
        }
        else if(index >= 65){
            index -= 65;
        }

        return index;
    }

    void insert(const string word){
        TrieNode* cur_node = this;

        for(int i = 0;i<word.length();i++){
            int let_index = getLetterIndex(word[i]);

            if(cur_node->children_arr[let_index] != NULL){
                cur_node = cur_node->children_arr[let_index];
            }
            else{
                TrieNode* new_node = new TrieNode();
                new_node->initialize();

                cur_node->children_arr[let_index] = new_node;
                cur_node = new_node;
            }

            if(i == word.length()-1){
                cur_node->isWordEnd = true;
            }
        }
    }

    bool search(const string word){
        TrieNode* cur_node = this;

        for(int i = 0;i<word.length();i++){
            cout << cur_node << endl;
            int let_index = getLetterIndex(word[i]);

            if(cur_node->children_arr[let_index] != NULL){
                cur_node = cur_node->children_arr[let_index];
            }
            else{
                return false;
            }

            if(i == word.length()-1){
                if(cur_node->isWordEnd){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
};


int main(){
    TrieNode* root = new TrieNode();
    root->initialize();

    root->insert("karlas");
    root->insert("karlos");
    cout << root->search("karloss") << endl; 
}
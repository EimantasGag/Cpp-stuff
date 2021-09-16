#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s){
    stringstream ss(s);
    vector<string> words;

    while(ss.good()){
        string w;
        ss >> w;
        words.push_back(w);
    }

    return words;
}

int main(){
    string sentence = "hello my name is jeff and I am sixteen years old";
    vector<string> words = split(sentence);

    for(string word: words){
        cout << word << endl;
    }
}   
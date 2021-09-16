#include <bits/stdc++.h>

using namespace std;

map<string, int> countWords(string sen){
    stringstream ss(sen);
    map<string, int> mymap;

    while(ss.good()){
        string w;
        ss >> w;
        mymap[w]++;
    }

    return mymap;
}

int main(){
    string sen = "labas ka tu labas as esu Tomas manes Tomas lol lol labas";
    map<string, int> res = countWords(sen);

    map<string, int>::iterator m;

    for(m = res.begin();m != res.end();m++){
        cout << m->first << " -> " << m->second << endl;
    } 
}
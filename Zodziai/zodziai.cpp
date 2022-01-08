#include <bits/stdc++.h>

using namespace std;

string getFirstWord(int index, const map<string, string>& all_words){
    int ind = 0;
    for(auto i = all_words.begin();i!=all_words.end();i++){
        if(ind == index){
            return i->first;
        }
        ind++;
    }
}

string getSecondWord(int index, const map<string, string>& all_words){
    int ind = 0;
    for(auto i = all_words.begin();i!=all_words.end();i++){
        if(ind == index){
            return i->second;
        }
        ind++;
    }
}

int main(){
    ifstream read_file("zodziai2.txt");

    string word, prev_word;
    map<string, string> all_words;

    bool definition = false;

    while(getline(read_file,  word)){
        //cout << word << endl;

        if(definition){
            all_words[prev_word] = word;
        }
        else{
            prev_word = word;
        }

        definition = !definition;
    }

    srand (time(NULL));
    string s;

    map<string, string> copy_words = all_words;

    while(true){

        if(copy_words.size() == 0){ 
            copy_words = all_words;
        }

        int random_index = rand() % copy_words.size();

        string w = getFirstWord(random_index, copy_words);

        cout << "Word: " << getSecondWord(random_index, copy_words) << endl;
        cin >> s;
        cout << "Meaning: " << getFirstWord(random_index, copy_words) << endl;

        copy_words.erase(copy_words.find(w));
    }
}
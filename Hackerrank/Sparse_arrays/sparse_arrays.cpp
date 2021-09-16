#include <bits/stdc++.h>

using namespace std;

struct LinkedList{
    string data;
    LinkedList* next;
    
    LinkedList(string d){
        data = d;
    }
};

int searchList(LinkedList* start, string s){
    int t = 0;
    LinkedList node = *start;
    LinkedList* prev = start;
    LinkedList* node_ptr = start;

    bool changeStart = true;
    bool cut = false;
    
    while(1){
        if(node.data == s){
            t++;    
            cut = true;
        }
        else{
            if(cut){
                if(changeStart){
                    *prev = node;
                }
                else{
                    (*prev).next = node_ptr;
                }
            }
            
            cut = false;
            prev = node_ptr;
            changeStart = false;
        }

        if(node.next == NULL){
            if(cut){
                if(changeStart){
                    LinkedList emptyList = LinkedList("");
                    emptyList.next = NULL;
                    *prev = emptyList;
                }
                else{
                    (*prev).next = NULL;
                }
            }
            break;
        }
        
        node = *node.next;
        node_ptr = node_ptr->next;
    }
    
    return t;
}

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    LinkedList start = LinkedList(strings[0]);
    LinkedList* cur = &start;
    
    for(int i = 1;i<strings.size();i++){
        cur->next = new LinkedList(strings[i]); 
        cur = cur->next;
    }
    
    cur->next = NULL;

    vector<int> res = {};
    bool already_seen = false;
    int ind = 0;
    
    for(int i = 0;i<queries.size();i++){
        for(int x = 0;x<i;x++){
            if(queries[x] == queries[i]){
                already_seen = true;
                ind = x;
                break;
            }
        }
        
        if(!already_seen){
            res.push_back(searchList(&start, queries[i]));
        }
        else{
            res.push_back(res[ind]);
        }

        already_seen = false;
    }
    
    return res;
}

string generateRandomString(int string_size){
    string s = "";

    for(int i = 0;i<string_size;i++){
        s += char(65 + rand() % 26);
    }

    return s;
}

bool randomBoolean(){
    return rand() % 2;
}

string chooseRandom(const vector<string>& strings){
    return strings[rand() % strings.size()];
}

vector<vector<string>> generateArgs(int arg_number){
    const int string_size = 3;
    vector<vector<string>> res = {{},{}};

    //generate strings vector
    for(int i = 0;i<arg_number;i++){
        bool new_string;

        if(i == 0){
            new_string = true;
        }
        else{
            new_string = randomBoolean();
        }
        

        if(new_string){
            res[0].push_back(generateRandomString(string_size));
        }
        else{
            res[0].push_back(chooseRandom(res[0]));
        }
    }

    //generate queries
    for(int i = 0;i<arg_number;i++){
        bool existing_querie = randomBoolean();

        if(existing_querie){
            res[1].push_back(chooseRandom(res[0]));
        }
        else{
            res[1].push_back(generateRandomString(string_size));
        }
    }

    return res;
}

void const printVector(const vector<string>& vec){
    for(int i = 0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    cout << endl;
}

void const printVector(const vector<int>& vec){
    for(int i = 0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    
    cout << endl;
}

vector<int> realRes(const vector<string>& strings, const vector<string>& queries){
    vector<int> res = {};
    int num = 0;

    for(int i = 0;i<queries.size();i++){
        num = 0;

        for(int x = 0;x<strings.size();x++){
            if(queries[i] == strings[x]){
                num++;
            }
        }

        res.push_back(num);
    }

    return res;
}

bool matchVectors(const vector<int>& v1, const vector<int>& v2){
    for(int i = 0;i<v1.size();i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }

    return true;
}

int main(){
    srand (time(NULL));

    vector<string> strings;
    vector<string> queries;
    vector<vector<string>> r;

    while(1){
        r = generateArgs(12);
        strings = r[0];
        queries = r[1];

        vector<int> res = matchingStrings(strings,queries);
        vector<int> real_res = realRes(strings,queries);

        if(matchVectors(res,real_res)){
            cout << "Results Match!" << endl;
        }
        else{
            cout << "Results do not match!" << endl;
            printVector(strings);
            printVector(queries);
            printVector(res);
            printVector(real_res);
            break;
        }
    }
}
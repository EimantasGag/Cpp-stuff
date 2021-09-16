#include <bits/stdc++.h>

using namespace std;

struct Person{
    ~Person(){
        cout << "Guten tag!" << endl; throw 20;
    }
};

int main(){
    try{
        Person* person = new Person();
        delete person;
    }catch(int n){
        cout << "Caught the exception!" << endl;
    }
}
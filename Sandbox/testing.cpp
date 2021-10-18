#include <bits/stdc++.h>

using namespace std;

int func(int i){
    cout << i << endl;
    if(i == 90000){
        return -1;
    }
    return func(i+1);
}


int main(){
    func(0);
}
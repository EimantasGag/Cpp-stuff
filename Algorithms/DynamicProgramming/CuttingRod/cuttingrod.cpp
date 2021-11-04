#include <bits/stdc++.h>

using namespace std;

int** lookup;

void _initialize(int l, int l2){
    lookup = new int*[l];

    for(int i = 0;i<l;i++){
        lookup[i] = new int[l2];
    }

    for(int i = 0;i<l;i++){
        for(int x = 0;x<l2;x++){
            lookup[i][x] = -1;
        }
    }
}

int count(const vector<int>& prices, int prices_size, int length, int cur_value = 0, int cur_index = 0){
    if(length == 0){
        return cur_value;
    }

    if(length < 0 || cur_index >= prices_size){
        return -1;
    }

    if(lookup[length][cur_index] != -1){
        return lookup[length][cur_index]+cur_value;
    }

    //3 RETURNAI:
    //1 - PRASKIPINAM SITO ILGIO ROD KIRPIMA
    //2 - NUKERPAME, BET TOLIAU KERPAME TOKIU PACIU ILGIU 

    int res =  max(
        count(prices, prices_size, length, cur_value, cur_index+1),
        count(prices, prices_size, length-(cur_index+1), cur_value+prices[cur_index], cur_index)
    );

    lookup[length][cur_index] = res-cur_value;

    return lookup[length][cur_index]+cur_value;
}

int main(){
    vector<int> prices = {1,5,8,9,10,17,17,20};
    int length = 8;
    _initialize(length+1,prices.size());

    cout << count(prices, prices.size(), length) << endl;
}
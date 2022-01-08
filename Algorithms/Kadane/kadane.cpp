#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> arr){
    int cur_sum = 0;
    int best_sum = 0;
    int max_num = arr[0];

    for(int i = 0;i<arr.size();i++){
        cur_sum += arr[i];

        if(arr[i] > max_num){
            max_num = arr[i];
        }

        if(cur_sum < 0){
            cur_sum = 0;
        }

        if(best_sum < cur_sum){
            best_sum = cur_sum;
        }
    }

    //MAX_NUM REIKALINGAS ATVEJUI JEIGU VISI SKAICIAI ARR YRA NEIGIAMI

    if(max_num <= 0){
        return max_num;
    }
    else{
        return best_sum;
    }
}

int main(){
    cout << kadane({ -8, -3, -6, -2, -5, -4 }) << endl;
}
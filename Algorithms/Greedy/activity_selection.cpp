#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

vector<vector<int>> sortedArr(vector<int> s, vector<int> e){
    vector<vector<int>> arr;
    for(int i = 0;i<e.size();i++){
        arr.push_back({s[i],e[i]});
    }
    sort(arr.begin(),arr.end(),compare);
    return arr;
}

int maxActivities(vector<int> s, vector<int> e){
    int num_activ = 0;
    int prev_end = 0;

    vector<vector<int>> arr = sortedArr(s, e);

    for(int i = 0;i<arr.size();i++){
        if(i == 0){
            num_activ++;
            prev_end = arr[i][1];
        }
        else if(arr[i][0] <= prev_end){
            prev_end = arr[i][1];
            num_activ++;
        }
    }

    return num_activ;
}

int main(){
    //Uzduotis: reikia rasti kiek zmogus daugiausia veiklu gali uzsiimti kai zinomi ju pradzios ir pabaigos laikai
    //Algoritmas: sortini end_times ir taip renkiesi is eiles

    vector<int> start_times = {1, 3, 0, 5, 8, 5};
    vector<int> end_times = {2, 4, 6, 7, 9, 9};

    cout << maxActivities(start_times,end_times);
}


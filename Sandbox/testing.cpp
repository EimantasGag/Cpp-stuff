#include <bits/stdc++.h>

using namespace std;

void func(int arr[5][2]){
    arr[0][0] = 0;
}

int main(){
    int arr[5][2] = {{1,2},{3,4},{5,6},{7,8},{9,10}};
    int** l = arr;
    func(arr);

    for(int i = 0;i<5;i++){
        for(int x = 0;x<2;x++){
            cout << arr[i][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
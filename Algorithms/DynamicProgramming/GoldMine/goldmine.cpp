#include <bits/stdc++.h>

using namespace std;

int** lookup;

int max(int a, int b, int c){
    if(a >= b && a >= c){
        return a;
    }
    else if(b >= a && b >= c){
        return b;
    }
    else{
        return c;
    }
}

int count(const vector<vector<int>>& matrix, int matrix_size, int cur_gold, int row, int col){
    if(col >= matrix[row].size() || row < 0 || row >= matrix_size){
        return cur_gold;
    }

    if(lookup[row][col] != -1){
        cout << "Used value from lookup!" << endl;
        return cur_gold + lookup[row][col];
    }

    int res = max(
        count(matrix, matrix_size, cur_gold+matrix[row][col], row, col+1),
        count(matrix, matrix_size, cur_gold+matrix[row][col], row+1, col+1),
        count(matrix, matrix_size, cur_gold+matrix[row][col], row-1, col+1)
    );

    lookup[row][col] = res - cur_gold;

    return res;
}

int gold_mine(const vector<vector<int>>& matrix, int matrix_size){
    int best = -1;

    for(int row = 0;row<matrix.size();row++){
        int res = count(matrix,matrix_size,0,row,0);

        if(res > best){
            best = res;
        }
    }

    return best;
}

void _initialize(int size1, int size2){
    lookup = new int*[size1];

    for(int i = 0;i<size1;i++){
        lookup[i] = new int[size2];
    }

    for(int i = 0;i<size1;i++){
        for(int x = 0;x<size2;x++){
            lookup[i][x] = -1;
        }
    }
}

int main(){
    vector<vector<int>> matrix = 
    {
        {1,3,3},
        {2,1,4},
        {0,6,4}
    };

    vector<vector<int>> matrix2 = 
    {
        {10,33,13,15},
        {22,21,4,1},
        {5,0,2,3},
        {0,6,14,2}
    };

    _initialize(matrix2.size(), matrix2[0].size());

    cout << gold_mine(matrix2, matrix2.size());
}
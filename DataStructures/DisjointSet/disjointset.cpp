#include <bits/stdc++.h>

using namespace std;

struct DisjointSet{
    map<int, int> parents;

    void makeSet(const vector<int>& arr){
        for(int i = 0;i<arr.size();i++){
            parents[arr[i]] = arr[i];
        }
    }

    int find(int val){
        if(parents[val] == val){
            return val;
        }

        return find(parents[val]);
    }

    void Union(int a, int b){
        int root1 = find(a);
        int root2 = find(b);
        parents[root1] = root2;
    }
};

int main(){
    
}
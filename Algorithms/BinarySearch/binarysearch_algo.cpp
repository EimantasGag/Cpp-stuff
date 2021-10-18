#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int findNum, vector<int>& arr, int s = -1, int e = -1){
    if(e == -1){
        sort(arr.begin(), arr.end(), [](int a, int b){ return a < b; });
        return binarySearch(findNum, arr, 0, arr.size()-1);
    }
    else{
        if(e - s <= 1){
            return false;
        }
        else if(arr[e] == findNum || arr[s] == findNum){
            return true;
        }
        else{
            int mid = (e-s)/2 + s;

            if(arr[mid] == findNum){
                return true;
            }
            else if(arr[mid] > findNum){
                return binarySearch(findNum, arr, s, mid);
            }
            else{
                return binarySearch(findNum, arr, mid, e);
            }
        }
    }
}

bool findIt(int num, const vector<int> nums){
    for(int n: nums){
        if(n == num){
            return true;
        }
    }

    return false;
}

void TestLoop(int test_number = 1){
    vector<int> nums;

    for(int i = 0;i<100;i++){
        int num = rand() % 100;
        nums.push_back(num);
    }

    int sear = rand() % 100;

    cout << "Test " << test_number << " runinng..." << endl;

    if(binarySearch(sear, nums) == findIt(sear, nums)){
        cout << "Test " << test_number << " passed!" << endl;
        return TestLoop(++test_number);
    }
    else{
        cout << "Test " << test_number << " FAILED!" << endl;
        return;
    }
    
}

int main(){
    TestLoop();
}
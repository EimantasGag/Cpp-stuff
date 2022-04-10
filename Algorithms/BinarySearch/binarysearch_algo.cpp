#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int findNum, vector<int>& arr, int s = -1, int e = -1){
    if(e == -1){
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

bool BS(const vector<int>& nums, const int& num, int left = 0){
    //int left = customLeft;
    int right = nums.size()-1;
    int mid;

    if(nums[left] == num){
        return true;
    }
    if(nums[right] == num){
        return true;
    }

    while(left < right-1){
        //cout << left << " " << right << endl;
        mid = left + (right-left) / 2;

        if(nums[mid] > num){ 
            right = mid;
        }
        else{
            left = mid;
        }

        if(nums[mid] == num){
            return true;
        }
    }

    return false;
}

bool findIt(int num, const vector<int> nums){
    for(int n: nums){
        if(n == num){
            return true;
        }
    }

    return false;
}

vector<int> printList(const vector<int>& arr){
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
}

void TestLoop(int test_number = 1){
    vector<int> nums;

    for(int i = 0;i<100;i++){
        int num = rand() % 1000;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int findNum = rand() % 1000;

    //printList(nums);
    // cout << "Searching for: " << findNum << endl;
    // cout << BS(nums, findNum) << endl;
    // cout << findIt(findNum, nums) << endl;

    cout << "Test " << test_number << " runinng..." << endl;

    if(BS(nums, findNum) == findIt(findNum, nums)){
        cout << "Test " << test_number << " passed!" << endl;
        if(test_number > 10000){
            return;
        }
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
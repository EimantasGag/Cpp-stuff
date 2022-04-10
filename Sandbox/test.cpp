#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool BS(const vector<int>& nums, const int& num, int left){
        //int left = customLeft;
        int right = nums.size()-1;
        int mid;

        if(left > right){
            return false;
        }

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
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        if(nums.size() <= 2){
            return res;
        }

        sort(nums.begin(), nums.end());
        
        int sum = 0;
        int n1,n2 = 0;
        int prev1, prev2 = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(i != 0 && prev1 == nums[i]){
                continue;
            }

            n1 = nums[i];
            sum += n1;

            for(int y = i+1;y<nums.size();y++){
                if(y != i+1 && prev2 == nums[y]){
                    continue;
                }

                n2 = nums[y];
                sum += n2;

                if(BS(nums, 0-sum, y+1)){
                    res.push_back({n1,n2,0-sum});
                };
                
                prev2 = n2;
                sum -= n2;
            }
            
            prev1 = n1;
            sum = 0;
        }
        
        return res;
    }
};

int printVec(const vector<vector<int>>& vec){
    for(int i = 0;i<vec.size();i++){
        for(int x = 0;x<vec[i].size();x++){
            cout << vec[i][x] << " ";
        }
        cout << endl;
    }
}

int main(){
    Solution solution;
    vector<int> n = {};
    vector<vector<int>> res = solution.threeSum(n);
    //cout << solution.BS()

    printVec(res);
    //cout << printVec(res) << endl;
}
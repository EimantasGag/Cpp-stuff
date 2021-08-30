#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

bool compare(Job a,Job b){
        return a.profit > b.profit;
}
    
int JobScheduling(Job arr[], int n){ 
    int deadline = 0;
    int sum = 0;

    sort(arr,arr+n,compare);
    for(int i = 0;i<n;i++){
        if(deadline < arr[i].dead){
            deadline++;
            sum += arr[i].profit;
        }
    }
    return sum;
} 

int main(){
    Job arr[] = {{0,1,612},{5,2,64},{9,1,4}};
    cout << "max payout possible: " << JobScheduling(arr,sizeof(arr)/sizeof(arr[0]));
}
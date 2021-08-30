#include <iostream>
#include <vector>

using namespace std;

int qs(int l, int r, int arr[5]){
    int pivot = arr[r];

    int pivot_ind = 0;

    int i = l-1;
    int prev = 0;

    for(int n = 0;i<=r;n++){
        if(arr[n] < pivot){
            i++;
            prev = arr[i];
            arr[i] = arr[n];
            arr[n] = prev;
        }
        else{
            

        }
    }
}

int main()
{
   int arr[5] = {5,9,4,7,11};
}
#include <iostream>

using namespace std;

int * qs(int arr[], int l, int r)
{
    int old_arr[r+1];
    memcpy(old_arr,arr,sizeof(old_arr));

    int p = r;
    int p_num = arr[p];

    int arr_size = r+1;

    if(l >= r){
        return 0;
    }

    for(int i = l;i<arr_size;i++){
        if(old_arr[i] > p_num){
            arr[r] = old_arr[i];
            r--;
        }
        else if(i == p){
            arr[l] = p_num;
            p = l;
            l++;
        }
        else{
            arr[l] = old_arr[i];
            l++;
        }
    }

    qs(arr,0,p-1);
    qs(arr,p+1,arr_size-1);

    return arr;
}

int main()
{
    int arr[] = {6,4,2,2,9,5,0,-1,45,12,31,1561,5,651,4,510,41,81,781,5,418,1,1851,14,8415,1,81,87,1,85,117,18,18,65,98,65,18,15,841,8,1845,198,1,51,8,1,81,65,1,8971,5,18,1,8,5,87};

    int r = sizeof(arr)/sizeof(arr[0])-1;
    int l = 0;

    qs(arr,l,r);

    int b = 10;
    int *a = &b;

    cout << "Isrusiuotas array: " << endl;

    for(int i = 0;i<r+1;i++){
        cout << arr[i] << " ";
    }

    return 0;
}



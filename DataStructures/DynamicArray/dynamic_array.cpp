#include <iostream>

using namespace std;

struct DynamicArray{
    
    int arr_size = 2;
    int num_of_elem = 0;

    int arr[2] = {};

    int size(){
        return num_of_elem;
    }

    int add(int a){
        if(num_of_elem+1 > arr_size){
            int *n_arr = new int[arr_size*2];

            for(int i = 0;i<arr_size;i++){
                n_arr[i] = arr[i];
            }

            arr_size *= 2;

            num_of_elem += 1;
        }
        else{
            arr[num_of_elem] = a;
        }
    }

};

// int* DynamicArray(){
//     static int num_of_elem = 0;
//     static int size_of_arr = 2;

//     num_of_elem += 1;

//     if(num_of_elem > size_of_arr){

//         size_of_arr = size_of_arr*2;

//         int n_arr[size_of_arr] = {};

//         for(int i = 0;i<num_of_elem;i++){
//             n_arr[i] = 
//         }
//     }

//     int arr[2] = {};

//     return arr;
// }

int main()
{
    int *arr = new int[2];

    int *n_arr = new int[4];

    arr = n_arr;

    

}
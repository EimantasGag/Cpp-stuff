#include <iostream>

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};


    for(int i = 0;i<10;i++){
        std::cout << &arr[i] << std::endl;
    }

    std::cout << "hello?" << std::endl;

    std::cout << *(int*)0x61ff00 << std::endl;


    return 0;
}
#include <iostream>

using namespace std;

void func(){
    throw 404;
}

int main(){
    func();
}
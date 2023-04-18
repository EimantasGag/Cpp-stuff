#include <bits/stdc++.h>
#include <fstream>

int main(){
    std::ifstream read("text.txt");
    int n;
    read >> n;
    std::cout << n << std::endl;;
    char name[21];
    read.ignore();  
    read.get(name, 21);
    std::cout << name << std::endl;
}
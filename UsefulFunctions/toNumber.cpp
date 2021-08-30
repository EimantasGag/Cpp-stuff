#include <string>

using namespace std;

int toNum(string s){
    int dup = 1;
    int sum = 0;
    for(int i = s.length()-1;i>=0;i--){
        sum += ((int)s[i] - '0') * dup;
        dup *= 10;
    }
    return sum;
}

int toNum(char s){
    return s - '0';
}

int main(){

}
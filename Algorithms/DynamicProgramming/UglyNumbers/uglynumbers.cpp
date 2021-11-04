#include <bits/stdc++.h>

using namespace std;

int ugly_number(int n){
    int cur = 1;

    int a = 2;
    int b = 3;
    int c = 5;

    for(int i = 1;i<n;i++){
        if(a <= b && a <= c){
            cur = a;
            
            if(a == c){
                c += 5;
            }
            if(a == b){
                b += 3;
            }

            a += 2;
        }
        else if(b <= a && b <= c){
            cur = b;

            if(b == a){
                a += 2;
            }
            if(b == c){
                c += 5;
            }

            b += 3;

        }   
        else if(c <= a && c <= b){
            cur = c;

            if(c == a){
                a += 2;
            }
            if(c == b){
                b += 3;
            }

            c += 5;
        }
    }

    return cur;
}

int main(){

    //NETEISINGAI SUPRASTA UZDUOTIS :(

    int num;
    cin >> num;
    cout << ugly_number(num) << endl;
}
#include <iostream>

using namespace std;

long long fib1(int ind)
{
    long long prev_num1 = 1;
    long long prev_num2 = 1;

    long long res = 0;

    for(int i = 0;i<ind;i++){
        if(i <= 1){
            res = 1;
        }
        else{
            res = prev_num1 + prev_num2;
            if(i % 2 == 0){
                prev_num1 = res;
            }
            else{
                prev_num2 = res;
            }
        }
    }

    return res;

}

long long fib2(int ind)
{
    long long fib_seq[ind] = {1,1};

    for(int i = 0;i<ind;i++){
        if(i <= 1){
            fib_seq[i] = 1;
        }
        else{
            fib_seq[i] = fib_seq[i-1] + fib_seq[i-2];
        }

        if(i == ind-1){
            return fib_seq[i];
        }
    }
}

int main()
{
    int ind;

    cout << "Enter a number you want to find: "; cin >> ind;

    cout << fib2(ind) << endl;

    return 0;
}




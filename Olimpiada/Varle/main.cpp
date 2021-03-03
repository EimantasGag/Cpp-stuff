#include <iostream>

using namespace std;

long long memo_size;
long long memo[][2] = {{}};

long long apsk1(int atstumas)
{
    long long res = 0;
    if(atstumas == 0){
        return 1;
    }
    else if(atstumas < 0){
        return 0;
    }

    for(int i = 0;i<memo_size;i++){
        if(memo[i][0] == atstumas){
            cout << "Used from memo POG: " << memo[i][1] << endl;
            return memo[i][1];
        }
    }

    for(int i = 0;i<2;i++){
        res += apsk1(atstumas - (i+1));
    }

    memo[memo_size][0] = atstumas;
    memo[memo_size][1] = res;
    memo_size++;

    return res;
}

int apsk2(int atstumas)
{
    int res = 0;

    if(atstumas == 0){
        return 1;
    }
    else if(atstumas < 0){
        return 0;
    }

    for(int i = 0;i<2;i++){
        res += apsk2(atstumas - (i+1));
    }

    return res;
}

int main()
{
    int atstumas;
    int memo[][2] = {};
    int memo_size = 0;

    cout << "Iveskite atstuma kuri tures iveikti varle: "; cin >> atstumas;

    cout << apsk1(atstumas) << endl;
    //cout << apsk2(atstumas) << endl;

    return 0;
}


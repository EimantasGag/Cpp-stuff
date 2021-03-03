#include <iostream>

using namespace std;

int main()
{
    int n = 652323;

    long long pp_num = 1;
    long long p_num = 1;

    long long res = 1;

    for(int x = 0;x<n;x++){
        if(x >= 2){
            res = pp_num + p_num;
            pp_num = p_num;
            p_num = res;
        }

    }

    cout << res;

    return 0;
}

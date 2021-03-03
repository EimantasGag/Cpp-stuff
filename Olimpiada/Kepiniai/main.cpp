#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    ifstream fr("kepiniai.in");
    ofstream fd("kepiniai.out");

    int turimi_pin;

    int a_kaina,a_pelnas;
    int b_kaina,b_pelnas;

    bool baigti = false;

    fr >> turimi_pin;
    fr >> a_kaina >> a_pelnas;
    fr >> b_kaina >> b_pelnas;


    int a_res = (turimi_pin/a_kaina)*a_pelnas+(turimi_pin%a_kaina/b_kaina)*b_pelnas;
    int a_l = turimi_pin%a_kaina;
    int a_res1 = 0;

    if(a_l<b_kaina){
        a_res1 = ((turimi_pin/a_kaina*a_kaina - a_kaina)/b_kaina*b_pelnas)+(turimi_pin-((turimi_pin/a_kaina*a_kaina - a_kaina)/b_kaina*b_kaina))/a_kaina*a_pelnas;
    }


    int b_res = (turimi_pin/b_kaina)*b_pelnas+(turimi_pin%b_kaina/a_kaina)*a_pelnas;
    int b_l = turimi_pin%b_kaina;
    int b_res1 = 0;

    if(b_l<a_kaina){
        b_res1 = ((turimi_pin/b_kaina*b_kaina - b_kaina)/a_kaina*a_pelnas)+(turimi_pin-((turimi_pin/b_kaina*b_kaina - b_kaina)/a_kaina*a_kaina))/b_kaina*b_pelnas;
    }

    int all_res[4] = {a_res,a_res1,b_res,b_res1};

    int big = 0;
    int big_i = 0;

    for(int i = 0;i<4;i++){
        if(all_res[i] > big){
            big = all_res[i];
            big_i = i;
        }
    }

    fd << big;

    return 0;
}

int writefile()
{
    ofstream fd("nice.txt");

    int num;
    int num2;
    int sum;

    srand (time(NULL));

    int times = 0;

    num = rand() % 1000 + 1;

    sum = num;

    fd << num << endl;
    cout << num << endl;

    while(times != 2){
        num = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        if(num<sum && num2<sum){
            fd << num << " " << num2 << endl;
            cout << num << " " << num2 << endl;
            times++;
        }
    }

    return 0;
}



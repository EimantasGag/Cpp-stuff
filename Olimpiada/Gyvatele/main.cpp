#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    ifstream fr("gyvatele-vyr.in");
    ofstream fd("gyvatele-vyr.out");

    int taskai;

    fr >> taskai;

    int prad[2] = {};
    int pab[2] = {};

    int did_y = 0;
    int maz_y = 0;

    int x,y;

    for(int i = 0;i<taskai;i++){
        if(i == 0){
            fr >> prad[0] >> prad[1];
            maz_y = prad[1];
            did_y = prad[1];
        }
        else if(i == taskai-1){
            fr >> pab[0] >> pab[1];
            if(pab[1] < maz_y){
                maz_y = y;
            }
            else if(pab[1] > did_y){
                did_y = y;
            }
        }
        else{
            fr >> x >> y;
            if(y < maz_y){
                maz_y = y;
            }
            else if(y > did_y){
                did_y = y;
            }
        }
    }

    int a = abs(did_y - prad[1])+1;
    int y3 = prad[1]+a;
    int res1 = a + abs(prad[0] - pab[0]) + abs(pab[1] - y3);

    int b = abs(maz_y - prad[1])+1;
    int y4 = prad[1]-b;
    int res2 = b + abs(prad[0] - pab[0]) + abs(pab[1] - y4);

    //cout << a << " " << abs((prad[0] - pab[0])) << " " << abs((abs(pab[1])-(abs(prad[1])+a))) << endl;
    //cout << b << " " << abs((prad[0] - pab[0])) << " " << abs((abs(pab[1])-(abs(prad[1])-b))) << endl;

    if(res1 < res2){
        fd << res1;
    }
    else{
        fd << res2;
    }

    return 0;
}

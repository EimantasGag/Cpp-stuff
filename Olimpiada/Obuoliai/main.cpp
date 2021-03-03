#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    ifstream fr("obuoliai-vyr.in");
    ofstream fd("obuoliai-vyr.out");

    int obelu_sk,obuoliu_sk;

    fr >> obelu_sk;

    int kor_obelu[obelu_sk][2] = {{}};

    for(int i = 0;i<obelu_sk;i++){
        fr >> kor_obelu[i][0] >> kor_obelu[i][1];
    }

    fr >> obuoliu_sk;

    int obuolio_x,obuolio_y;
    double atstum = 0;

    int artimi_obuol = 0;

    for(int i = 0;i<obuoliu_sk;i++){
        fr >> obuolio_x >> obuolio_y;
        for(int x = 0;x<obelu_sk;x++){
            atstum = sqrt(pow(abs(kor_obelu[x][0] - obuolio_x),2) + pow(abs(kor_obelu[x][1] - obuolio_y),2));
            if (atstum < 3){
                artimi_obuol++;
                break;
            }
        }
    }

    fd << artimi_obuol;

    return 0;
}

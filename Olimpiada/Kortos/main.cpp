#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fr("kortos-vyr.in");
    ofstream fd("kortos-vyr.out");

    char raides[4] = {'S','B','V','K'};

    int kort_skaiciai[52] = {};
    char kort_raides[52] = {};

    int prog_sk[51] = {};
    char prog_raides[51] = {};

    int times = 0;

    for(int i = 1;i<5;i++){
        for(int x = 1;x<14;x++){
            kort_raides[times] = raides[i-1];
            kort_skaiciai[times] = x;
            times++;

        }
    }

    char raid;
    int sk;

    for(int x = 0;x<51;x++){
        fr >> raid >> sk;
        for(int i = 0;i<52;i++){
            if(raid == kort_raides[i] && sk == kort_skaiciai[i]){
                kort_raides[i] = '-';
                kort_skaiciai[i] = 0;
                break;
            }
        }
    }

    for(int i = 0;i<52;i++){
        if (kort_raides[i] != '-'){
            fd << kort_raides[i] << " " << kort_skaiciai[i];
            break;
        }
    }

    return 0;
}

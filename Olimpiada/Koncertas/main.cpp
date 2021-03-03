#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fr("koncertas.in");
    ofstream fd("koncertas.out");

    int vietos_sk;

    fr >> vietos_sk;

    int vietos[vietos_sk] = {};

    for(int i = 0;i<vietos_sk;i++){
        fr >> vietos[i];
    }

    int reik_vieta = 0;
    int persedimai = 0;

    for(int i = 0;i<vietos_sk;i++){
        if(vietos[reik_vieta] != 0){
            persedimai++;
            reik_vieta = vietos[reik_vieta]-1;
        }
        else{
            break;
        }
    }

    fd << persedimai;

    return 0;
}

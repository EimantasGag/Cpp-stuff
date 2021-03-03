#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    ifstream fr("petras.in");
    ofstream fd("petras.out");

    int gyv_sk,nariu_sk,kand_sk;

    fr >> gyv_sk >> nariu_sk >> kand_sk;

    int visi_nariai[nariu_sk] = {};

    for(int i = 0;i<nariu_sk;i++){
        fr >> visi_nariai[i];
    }

    int rek = 0;
    int a,b,c;
    int narys = 0;
    int priimti = 0;

    for(int i = 0;i<kand_sk;i++){
        fr >> a >> b >> c;
        for(int x = 0;x<nariu_sk;x++){
            narys = visi_nariai[x];
            if(b == narys){
                rek++;
            }
            else if(c == narys){
                rek++;
            }

            if(rek == 2){
                priimti++;
                break;
            }
        }
        rek = 0;
    }

    fd << priimti;

    return 0;
}

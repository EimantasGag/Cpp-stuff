#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    ifstream fr("internetas-vyr.in");
    ofstream fd("internetas-vyr.out");

    int vien;

    fr >> vien;

    int rez[vien][2] = {{}};
    int big_dif = 0;

    for(int i = 0;i<vien;i++){
        fr >> rez[i][0] >> rez[i][1];

        //if iesko didziausio laiko tarp 1 ir 1 (nes jeigu bus visi 1 pabaigoje big_dif > dif)

        if(i != 0 && rez[i][0] - rez[i-1][0] > big_dif && rez[i-1][1] == 1 && rez[i][1] == 1){
            big_dif = rez[i][0] - rez[i-1][0];
        }
    }

    int dif = 0;
    int val;

    int start = 0;
    int endi = 0;

    bool fone = false;

    for(int i = 0;i<vien;i++){
        val = rez[i][1];

        //for loope fone = reiskia ieskoti vieneto, salygoje parasyta kad negali prasideti 0 arba pasibaigti, tad fone = false,
        //tada kai randa 0, paima skaiciu po jo (nes jis privalo but 1) ir nustato kaip pirma skaiciu, tada ieskomas vienetas, kai
        //surandamas is jo sio skaiciaus atimamas pradinis ir nustatomas ar jis didziausias.

        if(!fone){
            if(val == 0){
                start = rez[i-1][0];
                fone = true;
            }
        }

        else{
            if(val == 1){
                endi = rez[i][0];
                if(endi - start > dif){
                    dif = endi - start;
                    fone = false;
                }
            }
        }

    }

    if(dif > big_dif){
       fd << dif;
    }
    else{
        fd << big_dif;
    }
}

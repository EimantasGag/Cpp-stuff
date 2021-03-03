#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    ifstream fr("sampunas-vyr.in");
    ofstream fd("sampunas-vyr.out");

    int dienos,sv_dienos;

    fr >> dienos >> sv_dienos;

    int visos_sv[sv_dienos] = {};

    for(int i = 0;i<sv_dienos;i++){
        fr >> visos_sv[i];
    }

    bool plove = true;
    int diena = 1;
    int plovimai = 0;
    bool breaking = false;

    while(!breaking){
        if(diena == 1){
            plove = true;
            plovimai++;
        }
        else{
            if(plove){
                plove = false;
                for(int i = 0;i<sv_dienos;i++){
                    if(diena == visos_sv[i] && i == sv_dienos-1){
                        plove = true;
                        plovimai++;
                        breaking = true;
                        break;
                    }
                    if(diena == visos_sv[i]){
                        plove = true;
                        plovimai++;
                        break;
                    }
                }
            }
            else{
                plove = true;
                plovimai++;
            }

        }

        diena++;
    }

    fd << plovimai;

    return 0;
}

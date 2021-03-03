
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    //ifstream fr("sampunas-vyr.in");
    //ofstream fd("sampunas-vyr.out");

    int dienos,sv_dienos;

    cin >> dienos >> sv_dienos;

    int visos_sv[sv_dienos] = {};

    for(int i = 0;i<sv_dienos;i++){
        cin >> visos_sv[i];
    }

    bool plove = true;
    int diena = 1;
    int plovimai = 0;

    while(true){
        if(diena == 1){
            plove = true;
            plovimai++;
        }
        else{
            if(plove){
                plove = false;
                for(int i = 0;i<sv_dienos;i++){
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

        if(diena == dienos){
            break;
        }

        diena++;
    }

    cout << plovimai;

    return 0;
}

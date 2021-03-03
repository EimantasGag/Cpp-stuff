
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int dienos,sv_dienos;

    cin >> dienos >> sv_dienos;

    int visos_sv[sv_dienos] = {};

    for(int i = 0;i<sv_dienos;i++){
        cin >> visos_sv[i];
    }

    bool plove = true;
    int diena = 2;
    int plovimai = 1;
    int start = 0;

    while(diena != dienos+1){
        if(plove){
            plove = false;
            for(int i = start;i<sv_dienos;i++){
                if(diena == visos_sv[i]){
                    plove = true;
                    start = i+1;
                    plovimai++;
                    break;
                }
            }
        }
        else{
            plove = true;
            plovimai++;
        }

        diena++;
    }

    cout << plovimai;

    return 0;
}

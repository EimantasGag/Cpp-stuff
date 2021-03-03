#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fr("20.in");
    ofstream fd("output.txt");

    int eil,stulp;
    char ejimas;

    fr >> eil >> stulp;
    fr >> ejimas;

    string zenklas;

    char lenta[eil][stulp] = {{}};
    int numetimo_vt[stulp][2] = {{}};

    int vietos = 0;

    for(int y = 0;y<eil;y++){
        fr >> zenklas;
        for(int x = 0;x<stulp;x++){
            lenta[y][x] = zenklas[x];

            if(y != 0 && lenta[y-1][x] == '.' && zenklas[x] != '.'){
                numetimo_vt[vietos][0] = x;
                numetimo_vt[vietos][1] = y-1;
                vietos++;
            }
            else if(y == eil-1 && zenklas[x] == '.'){
                numetimo_vt[vietos][0] = x;
                numetimo_vt[vietos][1] = y;
                vietos++;
            }
        }
    }

    int x,y = 0;

    int eil_kartai,stulp_kartai,kryzm_kartai,kryzm_kartai2 = 0;
    int res = stulp+100;

    bool breaking = false;

    for(int i = 0;i<vietos;i++){
        x = numetimo_vt[i][0];
        y = numetimo_vt[i][1];

        eil_kartai = 0;
        kryzm_kartai2 = 0;
        kryzm_kartai = 0;
        stulp_kartai = 0;

        for(int n = -3;n<4;n++){
            if(n != 0){
                if(lenta[y][x+n] == ejimas && x+n < stulp && x+n > -1){
                    eil_kartai++;
                }
                else{
                    eil_kartai = 0;
                }

                if(lenta[y+n][x] == ejimas && y+n < eil && y+n > -1){
                    stulp_kartai++;
                }
                else{
                    stulp_kartai = 0;
                }

                if(lenta[y-n][x+n] == ejimas && y-n < eil && x+n < stulp && y+n > -1 && x+n > -1){
                    kryzm_kartai++;
                }
                else{
                    kryzm_kartai = 0;
                }

                if(lenta[y-n][x-n] == ejimas && y-n < eil && x-n < stulp && y-n > -1 && x-n > -1){
                    kryzm_kartai2++;
                }
                else{
                    kryzm_kartai2 = 0;
                }

                if(eil_kartai == 3 || stulp_kartai == 3 || kryzm_kartai == 3 || kryzm_kartai2 == 3){
                    if(res > x+1){
                        res = (x+1);
                    }

                    break;
                }
            }
        }

    }

    if(res == stulp+100){
        cout << "Negalima" << endl;
    }
    else{
        cout << res << endl;
    }

    return 0;
}

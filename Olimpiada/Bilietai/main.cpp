#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fr("10.in");
    ofstream fd("");

    int vag_sk,sed_sk,kl_sk;

    fr >> vag_sk >> sed_sk >> kl_sk;

    int vietos[900][200] = {{}};

    char a,b;

    bool breaking = false;
    int arr_dydis = 0;
    int times = 0;

    for(int i = 0;i<kl_sk;i++){
        fr >> a >> b;
        for(int x = 0;x<vag_sk*sed_sk;x++){
            if(vietos[x][0] == 0){
                vietos[x][1] = int(a);
                vietos[x][2] = int(b);
                vietos[x][0] += 2;
                cout << x/sed_sk+1 << " " << x%sed_sk+1 << endl;
                times++;
                break;
            }
            else{
                arr_dydis = vietos[x][0]+1;

                for(int n = 1;n<arr_dydis;n+=2){
                    if(int(a)>vietos[x][n] && int(a)<vietos[x][n+1]){
                        breaking = true;
                        break;
                    }
                    else if(int(b)>vietos[x][n] && int(b)<vietos[x][n+1]){
                        breaking = true;
                        break;
                    }
                    else if(int(a)<=vietos[x][n] && int(b)>=vietos[x][n+1]){
                        breaking = true;
                        break;
                    }
                }

                if(!breaking){
                    vietos[x][arr_dydis] = int(a);
                    vietos[x][arr_dydis+1] = int(b);
                    vietos[x][0] += 2;
                    cout << x/sed_sk+1 << " " << x%sed_sk+1 << endl;
                    times++;
                    breaking = false;
                    break;
                }
                else if(x == vag_sk*sed_sk-1){
                    break;
                }

                breaking = false;
            }
        }

        if(breaking){
            cout << "PILNA" << endl;
            breaking = false;
        }
    }

    return 0;
}

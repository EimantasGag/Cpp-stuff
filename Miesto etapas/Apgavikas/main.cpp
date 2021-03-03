#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("");

    int vaik_sk,kamb_sk;

    cin >> vaik_sk >> kamb_sk;

    int salinami_z[vaik_sk] = {};

    for(int i = 0;i<vaik_sk;i++){
        cin >> salinami_z[i];
    }

    int kambariai[vaik_sk][vaik_sk];

    for(int x = 0;x<vaik_sk;x++){
        for(int i = 0;i<vaik_sk;i++){
            cin >> kambariai[x][i];
        }
    }

    int zinantys_v[vaik_sk] = {}; // nuo 1 prasideda
    int zin_vaik_sk = 0;

    int sal_vaikas = 0;

    int sal_vaik_kamb = 0;
    int like_gyvi = vaik_sk;

    bool mires = false;

    bool jau_zino = false;

    bool breaking = false;

    for(int i = 0;i<vaik_sk;i++){ //roundai == i
        sal_vaikas = salinami_z[i];
        sal_vaik_kamb = kambariai[sal_vaikas-1][i];

        for(int n = 0;n<zin_vaik_sk;n++){
            if(zinantys_v[n] == sal_vaikas){
                zinantys_v[n] = 0;
                zin_vaik_sk--;
            }
        }

        for(int x = i;x<vaik_sk;x++){
            if(kambariai[x][i] == sal_vaik_kamb && x != sal_vaikas-1){
                for(int n = 0;n<zin_vaik_sk;n++){
                    if(x+1 == zinantys_v[n]){
                        jau_zino = true;
                        break;
                    }
                }
                if(jau_zino){
                    jau_zino = false;
                }
                else if(jau_zino == false || zin_vaik_sk == 0){
                    for(int n = 0;n<i;n++){
                        if(salinami_z[n] == x+1){
                            mires = true;
                        }
                    }

                    if(!mires){
                        zinantys_v[zin_vaik_sk] = x+1;
                        zin_vaik_sk++;
                    }
                    mires = false;

                }
            }
        }

        like_gyvi--;

        if(zin_vaik_sk > like_gyvi-zin_vaik_sk+1){
            cout << i+1 << endl;
            breaking = true;
            break;
        }

    }

    if(!breaking){
        cout << vaik_sk << endl;
    }




    return 0;
}

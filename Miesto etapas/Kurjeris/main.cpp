#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("");

    int miest_sk, siunt_sk;

    int atstumai[miest_sk] = {};

    cin >> miest_sk;

    for(int i = 0;i<miest_sk;i++){
        cin >> atstumai[i];
    }

    cin >> siunt_sk;

    int siuntiniai[siunt_sk][2] = {{}}; // pridejau {}

    for(int i = 0;i<siunt_sk;i++){
        cin >> siuntiniai[i][0] >> siuntiniai[i][1];
    }

    int esamas_m = 0;
    int s_laikas = 9999999;
    int s_x = 0;
    int s_miest = 0;

    int gal_atstumas = 0;
    int dal_atstumas = 0;

    bool breaking = false;

    for(int i = 0;i<siunt_sk;i++){
        for(int x = 0;x<siunt_sk;x++){
            if(siuntiniai[x][1] < s_laikas && siuntiniai[x][1] != -1){
                s_laikas = siuntiniai[x][1];
                s_miest = siuntiniai[x][0];
                s_x = x;
            }
        }

        //esam_m nevisada didesnis uz s_miest
        if(esamas_m < s_miest){
            if(esamas_m == 0){
                for(int n = esamas_m;n<s_miest;n++){
                    dal_atstumas += atstumai[n];
                }
            }
            else{
                for(int n = esamas_m;n<s_miest;n++){
                    dal_atstumas += atstumai[n];
                }
            }

        }
        else if(esamas_m > s_miest){
            for(int n = s_miest;n<esamas_m;n++){
                dal_atstumas += atstumai[n];
            }
        }
        else{
            dal_atstumas += 0;
        }

        gal_atstumas += dal_atstumas;

        if(gal_atstumas <= s_laikas){
            dal_atstumas = 0;
        }
        else{
            cout << "-1" << endl;
            breaking = true;
            break;
        }

        esamas_m = s_miest;

        siuntiniai[s_x][1] = -1;

        dal_atstumas = 0;

        s_laikas = 9999999;
        s_miest = 0;
    }

    if(!breaking){
        for(int i = 0;i<esamas_m;i++){
            gal_atstumas += atstumai[i];
        }
        cout << gal_atstumas << endl;
    }


    //cout << gal_atstumas << endl;

    return 0;
}

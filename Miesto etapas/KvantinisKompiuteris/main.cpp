#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("");

    int ilgis,plotis;

    cin >> ilgis >> plotis;

    char schema[ilgis][plotis];

    bool stop = false;

    int jut_x = 0;
    int jut_y = 0;

    for(int i = 0;i<ilgis;i++){
        for(int x = 0;x<plotis;x++){
            cin >> schema[i][x];
            if(schema[i][x] == 'J'){
                jut_x = x;
                jut_y = i;
            }
        }
    }

    int imanomi_var[4][2];
    int iman_sk = 0;

    bool virsun = false;
    bool apac = false;
    bool kair = false;
    bool desin = false;

    int pasuk = 0;

    int x = 0;
    int y = 0;

    int gal_x = 0;
    int gal_y = 0;

    int veid_x = 0;
    int veid_y = 0;

    bool pavyko = false;

    if(!stop){
        if(schema[jut_y][jut_x-1] == '.'){
            imanomi_var[iman_sk][0] = jut_x-1;
            imanomi_var[iman_sk][1] = jut_y;
            iman_sk++;
        }
        if(schema[jut_y][jut_x+1] == '.'){
            imanomi_var[iman_sk][0] = jut_x+1;
            imanomi_var[iman_sk][1] = jut_y;
            iman_sk++;
        }
        if(schema[jut_y-1][jut_x] == '.'){
            imanomi_var[iman_sk][0] = jut_x;
            imanomi_var[iman_sk][1] = jut_y-1;
            iman_sk++;
        }
        if(schema[jut_y+1][jut_x] == '.'){
            imanomi_var[iman_sk][0] = jut_x;
            imanomi_var[iman_sk][1] = jut_y+1;
            iman_sk++;
        }

        if(iman_sk != 0){
            for(int i = 0;i<iman_sk;i++){

                 veid_x = 0;
                veid_y = 0;

                if(pavyko){
                    break;
                }

                if(imanomi_var[i][0] - jut_x == 0){
                    if(imanomi_var[i][1] - jut_y == -1){
                        virsun = true;
                        x = jut_x;
                        y = jut_y-1;
                    }
                    else{
                        apac = true;
                        x = jut_x;
                        y = jut_y+1;
                    }
                }
                else{
                    if(imanomi_var[i][0] - jut_x == -1){
                        desin = true;
                        x = jut_x+1;
                        y = jut_y;
                    }
                    else{
                        kair = true;
                        x = jut_x-1;
                        y = jut_y;
                    }
                }

                while(true){
                    if(y == 0 || y == ilgis-1 || x == 0 || x == plotis-1){
                        gal_x = x;
                        gal_y = y;

                        if(gal_y != 0 || gal_x != 0){
                            if(gal_y != ilgis-1 || gal_x != plotis-1){
                                if(gal_y != 0 || gal_x != plotis-1){
                                    if(gal_x != 0 || gal_y != ilgis-1){
                                        pavyko = true;
                                        break;
                                    }
                                }
                            }
                        }

                        break;
                    }

                    if(apac){
                        if(schema[y+1][x] == '.'){
                            y++;
                        }
                        if(schema[y][x+1] == '.'){
                            desin = true;
                            apac = false;
                            veid_x = x;
                            veid_y = y;
                            x++;
                            pasuk++;
                        }
                        else if(schema[y][x-1] == '.'){
                            kair = true;
                            apac = false;
                            veid_x = x;
                            veid_y = y;
                            x--;
                            pasuk++;
                        }
                    }

                    else if(virsun){
                        if(schema[y-1][x] == '.'){
                            y--;
                        }
                        else if(schema[y][x+1] == '.'){
                            desin = true;
                            apac = false;
                            veid_x = x;
                            veid_y = y;
                            pasuk++;
                        }
                        else if(schema[y][x-1] == '.'){
                            kair = true;
                            virsun = false;
                            veid_x = x;
                            veid_y = y;
                            pasuk++;
                        }
                    }

                    else if(desin){
                        if(schema[y][x+1] == '.'){
                            x++;
                        }
                        else if(schema[y+1][x] == '.'){
                            apac = true;
                            desin = false;
                            veid_x = x;
                            veid_y = y;
                            pasuk++;
                        }
                        else if(schema[y-1][x] == '.'){
                            virsun = true;
                            apac = false;
                            veid_x = x;
                            veid_y = y;
                            pasuk++;
                        }
                    }

                    else if(kair){
                        if(schema[y][x-1] == '.'){
                            x--;
                        }
                        else if(schema[y+1][x] == '.'){
                            apac = true;
                            kair = false;
                            veid_x = x;
                            veid_y = y;
                            pasuk++;
                        }
                        else if(schema[y-1][x] == '.'){
                            virsun = true;
                            kair = false;
                            veid_x = x;
                            veid_y = y;
                            pasuk++;
                        }
                    }

                    if(pasuk > 1){
                        break;
                    }
                }
            }
        }

        else{
            cout << "NEPASIEKIAMA";
        }
    }

    if(pavyko){
        for(int i = 0;i<ilgis;i++){
            for(int x = 0;x<plotis;x++){
                if(i == veid_y && x == veid_x && i != 0 && x != 0){
                    cout << "V";
                }
                else if(i == gal_y && x == gal_x){
                    cout << "L";
                }
                else{
                    cout << schema[i][x];
                }
            }
            cout << endl;
        }
    }
    else{
        cout << "NEPASIEKIAMA";
    }



    return 0;

}

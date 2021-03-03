#include <iostream>
#include <fstream>

using namespace std;

int susk_draug(int i, int draug, int pazist_sk, int *art_drg_sk, int *atvir_sk, int art_drg[], int pazist[][2])
{
    bool naujas = true;

    for(int n = 0;n<i;n++){
        if(pazist[n][0] == draug){
            for(int x = 0;x<*art_drg_sk;x++){
                if(art_drg[x] == pazist[n][1]){
                    naujas = false;
                }
            }
            if(naujas){
                art_drg[*art_drg_sk] = pazist[n][1];
                *art_drg_sk += 1;
                *atvir_sk += 1;
                susk_draug(i,pazist[n][1],pazist_sk,art_drg_sk,atvir_sk,art_drg,pazist);
            }
            naujas = true;
        }
        else if(pazist[n][1] == draug){
            for(int x = 0;x<*art_drg_sk;x++){
                if(art_drg[x] == pazist[n][0]){
                    naujas = false;
                }
            }
            if(naujas){
                art_drg[*art_drg_sk] = pazist[n][0];
                *art_drg_sk += 1;
                *atvir_sk += 1;
                susk_draug(i,pazist[n][0],pazist_sk,art_drg_sk,atvir_sk,art_drg,pazist);
            }
            naujas = true;
        }
    }

    return 0;
}

int main()
{
    ifstream fr("atvirutes.in");
    ofstream fd("atvirutes.out");

    int visi_drg_sk, art_drg_sk, pazist_sk;

    fr >> visi_drg_sk >> art_drg_sk >> pazist_sk;

    int art_drg[visi_drg_sk];

    for(int i = 0;i<art_drg_sk;i++){
        fr >> art_drg[i];
    }

    int pazist[pazist_sk][2];

    for(int i = 0;i<pazist_sk;i++){
        fr >> pazist[i][0] >> pazist[i][1];
    }

    int atvir_sk = art_drg_sk;
    bool gavo = false;

    int a,b;

    for(int i = 0;i<pazist_sk;i++){

        a = pazist[i][0];
        b = pazist[i][1];

        for(int x = 0;x<art_drg_sk;x++){
            //b neartimas sicia, tai ir ieskai b draugu
            if(a == art_drg[x]){
                for(int n = 0;n<art_drg_sk;n++){
                    if(b == art_drg[n]){
                        gavo = true;
                        break;
                    }
                }
                if(!gavo){
                    //nes pats jis negavo
                    atvir_sk++;

                    art_drg[art_drg_sk] = b;
                    art_drg_sk++;

                    //o dabar jo draugai

                    susk_draug(i,b,pazist_sk,&art_drg_sk,&atvir_sk,art_drg,pazist);
                }
                gavo = false;
                break;
            }
            else if(b == art_drg[x]){
                for(int n = 0;n<art_drg_sk;n++){
                    if(a == art_drg[n]){
                        gavo = true;
                        break;
                    }
                }
                if(!gavo){
                    //nes pats jis negavo
                    atvir_sk++;

                    art_drg[art_drg_sk] = a;
                    art_drg_sk++;

                    //o dabar jo draugai

                    susk_draug(i,a,pazist_sk,&art_drg_sk,&atvir_sk,art_drg,pazist);
                }
                gavo = false;
                break;
            }
        }
    }

    fd << atvir_sk;

    return 0;
}

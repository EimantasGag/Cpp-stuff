#include <iostream>
#include <vector>

using namespace std;

vector<int> visi_miestai;
vector<vector<int>> visi_keliai;

int ger_kart = 0;

int kel(int dab_kel, vector<int> buve_i, int kartas, int pab_kel){

    cout << "dab_kel: " << dab_kel << endl;

    if(dab_kel == pab_kel){
        if(ger_kart == 0 || kartas < ger_kart){
            ger_kart = kartas;
        }
    }

    bool first_time = true;

    bool buvo = false;

    int kitas_kel = 0;

    for(int i = 0;i<visi_keliai.size();i++){

        buvo = false;

        for(int n = 0;n<buve_i.size();n++){
            if(buve_i[n] == i){
                buvo = true;
            }
        }

        if(buvo){
            continue;
        }

        if(visi_keliai[i][0] == dab_kel || visi_keliai[i][1] == dab_kel){

            if(visi_keliai[i][0] == dab_kel){
                kitas_kel = visi_keliai[i][1];
            }
            else{
                kitas_kel = visi_keliai[i][0];
            }

            if(first_time){
                buve_i.push_back(i);
                first_time = false;
            }
            else{
                buve_i.pop_back();
                buve_i.push_back(i);
            }

            kel(kitas_kel, buve_i, kartas+1, pab_kel);
        }
    }

    return kartas;
}

int main(){
    int miestu_sk,keliu_sk,talpa,sunaud;

    cin >> miestu_sk >> keliu_sk >> talpa >> sunaud;

    int m;

    for(int i = 0;i<miestu_sk;i++){
        cin >> m;

        visi_miestai.push_back(m);
    }

    int k1,k2;

    for(int i = 0;i<keliu_sk;i++){
        cin >> k1 >> k2;
        visi_keliai.push_back({k1,k2});
    }

    visi_keliai = {{1,2},{1,3},{2,4},{3,5},{4,5}};

    kel(1,{},0,miestu_sk);

    int dab_bakas = 0;

    int valandos = 0;

    int pakrovimas = visi_miestai[0];

    for(int i = 0;i<ger_kart;i++){
        if(dab_bakas-sunaud >= 0){
            dab_bakas -= sunaud;
        }
        while(true){
            dab_bakas += pakrovimas;

            valandos++;

            if(dab_bakas >= talpa){
                break;
            }
        }
    }

    valandos += ger_kart;

    cout << valandos << endl;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> visi_nor;

int rec(int esam_eil, int noru_sk, vector<int> buve_i, int prad_laikas);

int main()
{
    ifstream fr("nice.txt");
    ofstream fd();

    int noru_sk;

    fr >> noru_sk;

    int a,b;

    for(int i = 0;i<noru_sk;i++){
        fr >> a >> b;

        visi_nor.push_back({a,b});
    }

    rec(1,noru_sk,{},0);

    return 0;
}

int rec(int esam_eil, int noru_sk, vector<int> buve_i, int dab_laikas)
{
    cout << "Esama eile: " << esam_eil << endl;

    int best_laikas = -1;

    bool jau_buvo = false;

    int laikas = dab_laikas;

    int res;

    for(int i = 0;i<noru_sk;i++){

        jau_buvo = false;

        for(int x = 0;x<buve_i.size();x++){
            if(x == i){
                jau_buvo = true;
            }
        }

        if(jau_buvo){
            continue;
        }
        else{
            buve_i.push_back(i);

            if(visi_nor[i][1] >= dab_laikas){
                return -1;
            }

            laikas += abs(visi_nor[i][1] - esam_eil);

            res = rec(visi_nor[i][0], noru_sk, buve_i, laikas);

            if(best_laikas == -1 || laikas < best_laikas){
                best_laikas = laikas;
            }

            buve_i.pop_back();

            laikas = dab_laikas;
        }

    }

    if(best_laikas != -1){
        return best_laikas;
    }
    else{
        return dab_laikas;
    }
    

}
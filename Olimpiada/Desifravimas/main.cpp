#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fr("desifravimas-vyr.in");
    ofstream fd("desifravimas-vyr.out");

    int raid_sk;
    string nep_uzs;
    string pil_uzs;

    fr >> raid_sk;
    fr >> nep_uzs;
    fr >> pil_uzs;

    int raktas = 0;

    bool pradeti = false;

    int x = 0;

    string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string s_abc = "abcdefghijklmnopqrstuvwxyz";
    string l_abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0;i<raid_sk;i++){
        if(nep_uzs[i] != pil_uzs[i]){
            if(int(nep_uzs[i]) < int(pil_uzs[i])){
                raktas = pil_uzs[i] - nep_uzs[i];
            }
            else{
                raktas = s_abc.length() - (nep_uzs[i] - pil_uzs[i]);
            }
        }
    }

    string txt = "";

    int pos = 0;

    //cout << "raktas: " << raktas << endl;

    for(int i = 0;i<raid_sk;i++){
        //cout << "RAIDE: " << pil_uzs[i] << " ASCII: " << int(pil_uzs[i]) <<endl;
        if(int(pil_uzs[i])>=97 && int(pil_uzs[i]) <= 122){
            pos = int(pil_uzs[i])-97;
            if(pos-raktas>=0){
                txt += s_abc[pos-raktas];
            }
            else{
                txt += s_abc[(s_abc.length())-abs(pos-raktas)];
            }
        }
        else if(int(pil_uzs[i]) >= 65 && int(pil_uzs[i]) <= 90){
            pos = int(pil_uzs[i])-65;
            if(pos-raktas>=0){
                txt += l_abc[pos-raktas];
            }
            else{
                txt += l_abc[(l_abc.length())-abs(pos-raktas)];
            }
        }
        else{
            txt += pil_uzs[i];
        }
    }

    fd << txt;

    return 0;
}

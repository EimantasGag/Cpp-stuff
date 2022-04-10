#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double visu_vid(int* mok_ugiai, int mok_sk){
    double suma = 0;
    int kiekis = 0;

    for(int i = 0;i<mok_sk;i++){
        suma += abs(mok_ugiai[i]);
        kiekis++;        
    }

    return suma/kiekis;
}

double bern_vid(int* mok_ugiai, int mok_sk){
    double suma = 0;
    int kiekis = 0;

    for(int i = 0;i<mok_sk;i++){
        if(mok_ugiai[i] < 0){
            suma += abs(mok_ugiai[i]);
            kiekis++;        
        }
    }

    return suma/kiekis;
}

double merg_vid(int* mok_ugiai, int mok_sk){
    double suma = 0;
    int kiekis = 0;

    for(int i = 0;i<mok_sk;i++){
        if(mok_ugiai[i] > 0){
            suma += mok_ugiai[i];
            kiekis++;        
        }
    }

    return suma/kiekis;
}

bool merg_komanda(int* mok_ugiai, int mok_sk){
    int kiekis = 0;
    for(int i = 0;i<mok_sk;i++){
        if(mok_ugiai[i] > 0 && mok_ugiai[i] > 175){
            kiekis++;
            if(kiekis >= 7){
                return true;
            }
        }
    }
    return false;
}

bool bern_komanda(int* mok_ugiai, int mok_sk){
    int kiekis = 0;
    for(int i = 0;i<mok_sk;i++){
        if(mok_ugiai[i] < 0 && abs(mok_ugiai[i]) > 175){
            kiekis++;
            if(kiekis >= 7){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ifstream read_file("uzd.txt");
    ofstream write_file("rez.txt");

    int mok_sk;
    read_file >> mok_sk;

    int mok_ugiai[mok_sk];

    for(int i = 0;i<mok_sk;i++){
        int ugis;
        read_file >> ugis;


        mok_ugiai[i] = ugis;
    }

    write_file << fixed << setprecision(1) << visu_vid(mok_ugiai, mok_sk) << endl;
    write_file << fixed << setprecision(2) << merg_vid(mok_ugiai, mok_sk) << endl;
    write_file << fixed << setprecision(2) << bern_vid(mok_ugiai, mok_sk) << endl;

    if(merg_komanda(mok_ugiai, mok_sk)){
        write_file << "Merginu komanda galima" << endl;
    }
    else{
        write_file << "Merginu komandos negalima" << endl;
    }

    if(bern_komanda(mok_ugiai, mok_sk)){
        write_file << "Bernu komanda galima" << endl;
    }
    else{
        write_file << "Bernu komandos negalima" << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int count(int K, int M, long long int H, int g, int T, int res_kuras = -1){
    long long int dab_h = 0;
    long long int dab_g = 0;
    int pan_kuras = T;

    //cout << "pan_kuras: " << pan_kuras << endl;

    if(T <= 0){
        return res_kuras;
    }

    while(T > 0){
        //KILIMAS

        T--;
        dab_g += int(K/(M+T)) - g;

        dab_h += dab_g;

        if(dab_h >= H){
            return count(K,M,H,g,pan_kuras-1,pan_kuras);
        }
    }

    while(dab_g-g > 0){
        dab_g -= g;
        dab_h += dab_g;

        if(dab_h >= H){
            return count(K,M,H,g,pan_kuras-1,pan_kuras);
        }
    }

    return res_kuras;
}

int count_maxT(int M, int K, int g){
    //T > M - K/g
    //greitis = 1, kai daugiausiai lygus T = (M + Mg - K)/(-1 - g)

    int maxT = double(M + M*g - K)/double(-1 - g);

    return maxT+1;
}

int main(){
    ifstream read_file("test9.in");
    ofstream write_file("ats.txt");

    int raketu_sk, g;
    int K,M;
    long long int H;

    read_file >> raketu_sk >> g;

    for(int i = 0;i<raketu_sk;i++){
        read_file >> K >> M >> H;
        //cout << "max: " << count_maxT(M,K,g) << endl;
        write_file << count(K,M,H,g,count_maxT(M,K,g)) << endl;
    }
}
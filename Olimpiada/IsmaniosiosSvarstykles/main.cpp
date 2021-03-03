#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fr("svarstykles-vyr.in");
    ofstream fd("svarstykles-vyr.out");

    int eil,skir;

    fr >> eil >> skir;

    int klie_svor[eil] = {};

    int svoris;
    int klientai = 1;

    fr >> klie_svor[0];

    int pan_svr = 300000;
    int pan_svr_ind = 0;
    int pan_svr_skr = 300000;

    bool naujas_kl = true;

    for(int i = 0;i<eil-1;i++){
        fr >> svoris;

        //cout << svoris << endl;

        pan_svr = 300000;

        for(int x=0;x<klientai;x++){
            //cout << klie_svor[x] << endl;
            if(abs(svoris-klie_svor[x]) <= skir){
                //cout << "svoris: " << svoris << " " << abs(svoris-klie_svor[x])  << endl;
                if(naujas_kl){
                    pan_svr_ind = x;
                    pan_svr = klie_svor[x];
                    pan_svr_skr = abs(svoris-klie_svor[x]);
                    naujas_kl = false;
                }

                else if(abs(svoris-klie_svor[x])<=pan_svr_skr){
                    if(abs(svoris-klie_svor[x]) != pan_svr_skr){
                        pan_svr_ind = x;
                        pan_svr = klie_svor[x];
                        pan_svr_skr = abs(svoris-klie_svor[x]);
                        naujas_kl = false;
                    }
                    else if(pan_svr > klie_svor[x]){
                        pan_svr_ind = x;
                        pan_svr = klie_svor[x];
                        pan_svr_skr = abs(svoris-klie_svor[x]);
                        naujas_kl = false;
                    }

                }

            }
        }

        if(naujas_kl){
            klie_svor[klientai] = svoris;
            klientai++;
        }
        else{
            klie_svor[pan_svr_ind] = svoris;
        }

        naujas_kl = true;
    }

    fd << klientai;

    return 0;
}

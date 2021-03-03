#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    int mokiniu_sk, pakviestas_mok;

    cin >> mokiniu_sk >> pakviestas_mok;

    int visi_mok[mokiniu_sk] = {};
    int good_arr[mokiniu_sk] = {};

    for(int i = 0;i<mokiniu_sk;i++){
        cin >> visi_mok[i];
        good_arr[i] = visi_mok[i];
    }

    int r = 0;
    int pirmas_mok = pakviestas_mok;

    while(true){
        if (visi_mok[pakviestas_mok-1] == - 1 || visi_mok[pakviestas_mok-1] == pirmas_mok){
            cout << r;
            break;
        }
        else{
            r = visi_mok[pakviestas_mok-1];
        }

        visi_mok[pakviestas_mok-1] = -1;
        pakviestas_mok = r;
    }

    return 0;
}

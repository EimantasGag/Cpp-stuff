#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fr("limonadas.in");
    ofstream fd("limonadas.out");

    int dienu_sk;

    fr >> dienu_sk;

    int limo;
    int kaina = 0;

    for(int i = 0;i<dienu_sk;i++){
        fr >> limo;
        if(limo*4>20){
            if(limo/6>=1){
                kaina += limo*4-(20*(limo/6)+(limo%6)*4);
            }
            else{
                kaina += limo*4-20;
            }
        }
    }

    fd << kaina;

    return 0;
}

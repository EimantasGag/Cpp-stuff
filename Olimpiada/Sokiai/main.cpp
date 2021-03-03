#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    ifstream fr("sokiai-vyr.in");
    ofstream fd("sokiai-vyr.out");

    int vaiku_sk;

    fr >> vaiku_sk;

    int vaikinu_a[vaiku_sk] = {};

    for(int i = 0;i<vaiku_sk;i++){
        fr >> vaikinu_a[i];
    }

    int panos_a;
    int smallest = 100;
    int vaikino_a = 0;

    int panu_a[vaiku_sk] = {};

    for(int i = 0;i<vaiku_sk;i++){
        fr >> panu_a[i];
    }

    int poru_sk = 0;

    bool pora = false;
    int vaikino_num = 0;

    for(int i = 0;i<vaiku_sk;i++){
        panos_a = panu_a[i];

        for(int x = 0;x<vaiku_sk;x++){
            vaikino_a = vaikinu_a[x];
            if(vaikino_a > panos_a && (vaikino_a - panos_a) < smallest && vaikino_a != 0){
                cout << vaikino_a << " " << panos_a << endl;
                vaikino_num = x;
                smallest = vaikino_a - panos_a;
                pora = true;
            }
        }

        if(pora){
            vaikinu_a[vaikino_num] = 0;
            poru_sk++;
        }

        pora = false;
        smallest = 100;
    }

    fd << poru_sk;

    return 0;
}

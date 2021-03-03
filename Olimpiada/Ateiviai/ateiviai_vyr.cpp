#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int kojos,spalvos;

    //ifstream fr("nice.txt");
    //ofstream fd("output.txt");

    cin >> kojos >> spalvos;

    int spalvos_sk;
    int res = 0;
    bool enough = false;

    for(int i = 0;i<spalvos;i++){
        cin >> spalvos_sk;
        if(kojos <= spalvos_sk){
            enough = true;
            res += (kojos-1);
        }
        else{
            res += spalvos_sk;
        }
    }

    if(enough){
        cout << (res+1);
    }
    else{
        cout << -1;
    }

    return 0;

}

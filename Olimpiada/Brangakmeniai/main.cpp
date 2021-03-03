#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream fr("brangakmeniai-vyr.in");
    ofstream fd("brangakmeniai-vyr.out");

    int r,m,r_a,m_a;

    fr >> r >> m;
    fr >> r_a >> m_a;

    int r_vertes[r] = {};
    int m_vertes[m] = {};

    for(int i = 0;i<r;i++){
        fr >> r_vertes[i];
    }
    for(int i = 0;i<m;i++){
        fr >> m_vertes[i];
    }

    int big = 0;
    int big_x = 0;

    int pavogta = 0;

    for(int i =0;i<r_a;i++){
        for(int x = 0;x<r;x++){
            if(r_vertes[x] > big){
                big = r_vertes[x];
                big_x = x;
            }
        }

        r_vertes[big_x] = -1;
        pavogta += big;
        big = 0;
    }

    big = 0;
    big_x = 0;

    for(int i =0;i<m_a;i++){
        for(int x = 0;x<m;x++){
            if(m_vertes[x] > big){
                big = m_vertes[x];
                big_x = x;
            }
        }

        m_vertes[big_x] = -1;
        pavogta += big;
        big = 0;
    }

    fd << pavogta;

    return 0;
}

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fr("nice.txt");
    ofstream fd("dovana.out");

    int bul_sk,vaik_sk;

    fr >> bul_sk >> vaik_sk;

    int bulv_dyd[bul_sk] = {};

    for(int i = 0;i<bul_sk;i++){
        fr >> bulv_dyd[i];
    }

    int best_res = 99999999;
    int best_res1 = 0;
    int best_res2 = 0;

    int res[vaik_sk] = {};
    int items = 1;

    int big = 0;
    int big_ind = 1;

    for(int i = 0;i<bul_sk;i++){
        res[0] = bulv_dyd[i];
        for(int x = 0;x<bul_sk;x++){
            if(bulv_dyd[x] >= res[0] && items != vaik_sk && x != i){
                res[items] = bulv_dyd[x];

                items++;

                if(bulv_dyd[x] > big){
                    big = bulv_dyd[x];
                    big_ind = items-1;
                }

            }
            else if(bulv_dyd[x] >= res[0] && big > bulv_dyd[x] && items == vaik_sk && x != i){
                res[big_ind] = bulv_dyd[x];
                big = 0;
                for(int n = 0;n<vaik_sk;n++){
                    if(res[n]>big){
                        big = res[n];
                        big_ind = n;
                    }
                }
            }
        }

        if(big-res[0] < best_res && items == vaik_sk){
            best_res = big-res[0];
            best_res1 = res[0];
            best_res2 = big;
        }

        items = 1;
        big = 0;
        big_ind = 1;

    }

    int times = 0;

    for(int i = 0;i<bul_sk;i++){
        if(bulv_dyd[i] == best_res1 || bulv_dyd[i] == best_res2){
            cout << bulv_dyd[i] << " ";
            times++;
        }
        else if(bulv_dyd[i] > best_res1 && bulv_dyd[i] < best_res2){
            cout << bulv_dyd[i] << " ";
            times++;
        }
        if(times == vaik_sk){
            break;
        }
    }

    return 0;
}

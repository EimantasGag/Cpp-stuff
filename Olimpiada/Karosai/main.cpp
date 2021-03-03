#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int find_path(int perejimai[][3], vector<int> buve, int esamas_t, int perejimu_sk, int van_lygis, int tvenk_sk)
{
    bool perejo = false;

    bool nebuvo = true;

    bool zinomas_res = false;

    int res = 0;

    int best_res = -1;

    int memo_p = 0;

    if(esamas_t == tvenk_sk){
        return van_lygis;
    }

    for(int i = 0;i<perejimu_sk;i++){

        nebuvo = true;
        zinomas_res = false;


        for(int x = 0;x<buve.size();x++){
            if(buve[x] == i){
                nebuvo = false;
            }
        }

        if(!nebuvo){
            continue;
        }


        if(perejimai[i][0] == esamas_t || perejimai[i][1] == esamas_t){

            cout << perejimai[i][0] << " " << perejimai[i][1] << endl;
            cout << "van_lygis, pries: " << van_lygis << endl;

            perejo = true;

            buve.push_back(i);

            for(int x = 0;x<memo.size();x++){
                //cout << "memo.size(): " << memo.size() << endl;
                //cout << "memo: " << memo[x][0] << " " << memo[x][1] << " " << memo[x][2] << endl;

                if(memo[x][0] == perejimai[i][0] && memo[x][1] == perejimai[i][1]){
                    res = memo[x][2];
                    zinomas_res = true;
                    break;
                }
                else if(memo[x][0] == perejimai[i][1] && memo[x][1] == perejimai[i][0]){
                    res = memo[x][2];
                    zinomas_res = true;
                    break;
                }
            }

            if(van_lygis < perejimai[i][2]){
                van_lygis = perejimai[i][2];
            }

            if(!zinomas_res){
                if(perejimai[i][0] == esamas_t){
                    res = find_path(perejimai,buve,perejimai[i][1],perejimu_sk,van_lygis,tvenk_sk);
                }
                else{
                    res = find_path(perejimai,buve,perejimai[i][0],perejimu_sk,van_lygis,tvenk_sk);
                }
            }

            //cout << perejimai[i][0] << " " << perejimai[i][1] << endl;
            //cout << "van_lygis, po: " << van_lygis << endl;

            if(res != -2){
                if(best_res == -1 || res < best_res){
                    best_res = res;
                }

                memo.push_back({perejimai[i][0],perejimai[i][1],res});
            }

        }
    }

    if(perejo){
        return best_res;
    }
    else{
        return -2;
    }

}

int main()
{
    ifstream fr("karosai-vyr.04.in");
    ofstream fd("karosai-vyr.out");

    int perej_sk, tvenk_sk;

    fr >> tvenk_sk >> perej_sk;

    int perejimai[perej_sk][3] = {{}};

    int prev_i[perej_sk] = {};
    int prev_i_ind = 0;

    vector<int> pirmu_ind;

    for(int i = 0;i<perej_sk;i++){
        fr >> perejimai[i][0] >> perejimai[i][1] >> perejimai[i][2];
        if(perejimai[i][0] == 1 || perejimai[i][1] == 1){
            pirmu_ind.push_back(i);
        }
    }

    int ind = 0;

    int best_res = 0;
    int res = 0;

    vector<int> buve;

    for(int i = 0;i<pirmu_ind.size();i++){
        ind = pirmu_ind[i];
        buve.clear();

        buve.push_back(ind);

        cout << "mes ir vel" << endl;

        if(perejimai[ind][0] == 1){
            res = find_path(perejimai,buve,perejimai[ind][1],perej_sk,perejimai[ind][2],tvenk_sk);
        }
        else{
            res = find_path(perejimai,buve,perejimai[ind][0],perej_sk,perejimai[ind][2],tvenk_sk);
        }

        if(best_res == 0 || res < best_res){
            if(res != -2 && res != -1){
                best_res = res;
            }
        }

    }

    cout << "best_res: " << best_res << endl;

    return 0;
}

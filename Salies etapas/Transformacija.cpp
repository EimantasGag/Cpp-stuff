#include <iostream>
#include <vector>

using namespace std;

vector<int> dal_sk = {9,8,7,6,5,4,3,2};

int dal(int dab_sk, int kaina){

    if(dab_sk == 0 || dab_sk == 1){
        return kaina;
    }

    bool dalus = false;

    int daug = 10;

    int b_res = 0;

    vector<int> all_res;

    while(true){

        int buv_sk = dab_sk;

        int res1 = -1;
        int res2 = -1;

        int res3 = -1;

        dalus = false;

        for(int i = 0;i<dal_sk.size();i++){
            if(dab_sk%dal_sk[i] == 0){
                //cout << dab_sk << "/" << dal_sk[i] << endl;
                //cout << "Kaina += 2" << endl;

                res3 = dal((dab_sk/dal_sk[i]),2);

                dalus = true;
                break;
            }
        }

        
        daug = 10;

        while(true){
            if(dab_sk%(daug*10) != dab_sk){
                daug *= 10;
            }
            else{
                break;
            }
        }

        //cout << "Daug: " << daug << endl;

        if(double((dab_sk - daug)/daug) != 0){
            res1 = dal(dab_sk-daug,1);
        }
    
        res2 = dal(dab_sk-1,1); //100 -1
        

        all_res = {res1,res2,res3};

        for(int i = 0;i<3;i++){
            if(b_res == 0 && all_res[i] != -1){
                b_res = all_res[i];
            }
            else if(all_res[i] != -1 && all_res[i] < b_res){
                b_res = all_res[i];
            }
        }

        return kaina+b_res;
        
        
    }

}

int main()
{
    int kiekis;

    cin >> kiekis;

    vector<int> visi_sk;

    int a;

    for(int i = 0;i<kiekis;i++){
        cin >> a;

        visi_sk.push_back(a);
    }

    for(int i = 0;i<visi_sk.size();i++){
        cout << dal(visi_sk[i],0) << endl;
    }
}
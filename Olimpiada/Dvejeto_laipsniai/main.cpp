#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> buve(16);

vector<char> kart_sk;

long long int dal = -1;

long long int max_dal = 0;
long long int max_sk = 0;

long long int op,sk,dd;

int gen(string num, string res, int ind);

int main()
{
    ifstream fr("nice.txt");
    ofstream fd("");

    int skaitm_sk;

    string prad_sk = "";

    char v;

    fr >> skaitm_sk;

    for(int i = 0;i<skaitm_sk;i++){
        fr >> v;
        prad_sk += v;
    }

    //surandu kartotinius skaicius jeigu tokiu yra

    for(int i = 0;i<prad_sk.length();i++){
        for(int x = 0;x<prad_sk.length();x++){
            if(prad_sk[i] == prad_sk[x] && x != i){
                kart_sk.push_back(prad_sk[i]);
            }
        }
    }

    gen(prad_sk,"",0);

    cout << "max_sk: " << max_sk << endl;
    cout << "max_dal: " << max_dal << endl;

    return 0;
}

int gen(string num, string res, int ind){

    bool tikrinti = false;

    //nebuvo_i atsirenka i, kurios reikalingos for loope, jos atsirenkamos is vector - buve, jame suzymeta 0 ir 1

    vector<int> nebuvo_i;

    //jeigu aplanke kartotini skaicius prides ji cia, kad zinotu kad dabar jau reikia ji praleisti

    vector<char> skip_sk;

    int i = 0;

    bool buvo = false;

    //patikrina kokie skaiciai jau buvo skaiciuje tarkim skacius: 1246, tai cia bus i siu skaiciu

    for(int i = 0;i<num.length();i++){
        if(buve[i] == 0){
            nebuvo_i.push_back(i);

        }
    }

    //tikriti = true, jeigu tai paskutinis skaicius

    if(res.length() == num.length()-1){
        tikrinti = true;
    }

    if(res.length() == num.length()){

        op = 1;
        sk = 0;

        for(int n = res.length()-1;n>=0;n--){
            sk += (int(res[n] - '0')) * op;
            op = op*10;
        }

        if(dal == -1){
            dal = 2;

            while(true){
                if(dal*2 > sk*10){
                    break;
                }
                dal = dal*2;
            }
        }

        dd = dal;

        while(dd > max_dal){
            if(sk%dd == 0){
                break;
            }

            dd /= 2;
        }

        if(dd>max_dal){
            max_dal = dd;
            max_sk = sk;
        }

        return 0;
    }

    for(int n = 0;n<nebuvo_i.size();n++){

        i = nebuvo_i[n];

        buvo = false;

        //o cia tikrina ar skaicius nesikartoja for loope nes jeigu yra koks 456 ir as pridedu 7, nenoriu antra karta pridet 7

        for(int x = 0;x<skip_sk.size();x++){
            if(num[i] == skip_sk[x]){
                buvo = true;
                break;
            }
        }

        if(buvo){
            continue;
        }

        //jeigu aptinka skaicius kuris veliau kartosis, ji prideda prie praleidziamu skaicius grupes

        for(int x = 0;x<kart_sk.size();x++){
            if(kart_sk[x] == num[i]){
                skip_sk.push_back(num[i]);
                break;
            }
        }


        //tikrina ar neprasideda nuliu

        if(ind == 0){
            if(num[i] == '0'){
                continue;
            }
        }

        //tikrina jeigu paskutinis skaicius, ir ar dalus is 2

        if(tikrinti){
            if(num[i]%2 != 0){
                continue;
            }
        }

        if(res.length() == ind){
            res += num[i];
        }
        else{
            res[ind] = num[i];
        }

        buve[i] = 1;

        gen(num,res,ind+1);

        buve[i] = 0;
    }

    return 0;
}


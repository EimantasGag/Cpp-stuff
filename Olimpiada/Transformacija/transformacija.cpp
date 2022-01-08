#include <bits/stdc++.h>

using namespace std;

int best_kaina = -1;

int getFirstNum(long long A, long long des){
    return A/des;
}

int getLastNum(long long A){
    return A%10;
}

int getTwoLastNums(const long long A){
    return A%100;
}

int getTwoFirstNums(const long long A, const long long des){
    return A/(des/10);
}

long long divideLastNum(const long long A, const int i){
    int lastnum = getLastNum(A);

    if(lastnum % i != 0){
        return -1;
    }

    lastnum /= i;

    return ((A/10)*10)+lastnum;
}

long long divideFirstNum(const long long A, const long long des, const int i){
    int firstnum = getFirstNum(A, des);

    if(firstnum % i != 0){
        return -1;
    }

    return (firstnum/i)*des + A%des; 
}

long long divideTwoLastNums(const long long A, const int i){
    int lastnums = getTwoLastNums(A);

    if(lastnums % i != 0 || lastnums / i >= 10){
        return -1;
    }

    lastnums /= i;

    return ((A/100)*10)+lastnums;
}

long long divideTwoFirstNums(const long long A, const long long des, const int i){
    int firstnums = getTwoFirstNums(A, des);

    if(firstnums % i != 0 || firstnums / i >= 10){
        return -1;
    }

    return (firstnums/i)*(des/10) + A%(des/10); 
}

long long decreaseLastNum(const long long A){
    int lastnum = getLastNum(A);

    if(lastnum != 0){
        return A - 1;
    }
    else{
        int lastnums = getTwoLastNums(A);

        if(lastnums != 10){
            return -1;
        }
        else{
            return ((A/100)*10)+9;
        }
    }
}

long long decreaseFirstNum(const long long A, const long long des){
    int firstnum = getFirstNum(A, des);

    if(firstnum == 1){
        int firstnums = getTwoFirstNums(A, des);

        if(firstnums != 10){
            return -1;
        }
        else{
            return 9*(des/10) + A%(des/10);
        }
    }
    else{
        return (firstnum-1)*des + A%des;
    }

    return (firstnum-1)*des + A%des;
}

vector<vector<int>> lookup;

void _initialize(int size){
    for(int i = 0;i<size;i++){
        lookup.push_back({});
    }
}

int count(long long A, long long des, int des_sk, int dab_kaina = 0){
    if(dab_kaina >= best_kaina && best_kaina != -1){
        return -1;
    }

    //CIA APSKAICIUOJAME MIN KAINA (des_sk*2)

    if(des_sk*2 + dab_kaina > best_kaina && best_kaina != -1){

        //VIENINTELIS ISSKIRTINIS ATVEJIS DVEJETUI

        if(A != 2){
            return -1;
        }
    }

    if(A < 1){
        return -1;
    }

    if(A == 1){
        best_kaina = dab_kaina;
        return dab_kaina;
    }

    long long naujas_sk;

    if(A >= 10){

        //DALINAME 2 PIRMUS SKAICIUS

        for(int i = 9;i>=2;i--){
            naujas_sk = divideTwoFirstNums(A,des,i);

            if(naujas_sk != -1){
                if(naujas_sk < des){
                    count(naujas_sk, des/10, des_sk-1, dab_kaina+2);
                }
                else{
                    count(naujas_sk, des, des_sk, dab_kaina+2);
                }
            }
        }

        //DALINAME 2 PASKUTINIUS SKAICIUS

        int lastnums = getTwoLastNums(A);

        if(lastnums != 0 || lastnums >= 10){
            for(int i = 9;i>=2;i--){
                naujas_sk = divideTwoLastNums(A,i);

                if(naujas_sk != -1){
                    if(naujas_sk < des){
                        count(naujas_sk, des/10, des_sk-1, dab_kaina+2);
                    }
                    else{
                        count(naujas_sk, des, des_sk, dab_kaina+2);
                    }
                }
            }
        }
    }

    //DALINAME PIRMA SKAICIU

    int firstnum = getFirstNum(A, des);

    for(int i = firstnum;i>=2;i--){
        naujas_sk = divideFirstNum(A, des, i);

        if(naujas_sk != -1){
            count(naujas_sk, des, des_sk, dab_kaina+2);
        }
    }

    //DALINAME PASKUTINI SKAICIU

    int lastnum = getLastNum(A);

    if(lastnum != 0){
        for(int i = lastnum;i>=2;i--){
            naujas_sk = divideLastNum(A, i);

            if(naujas_sk != -1){
                count(naujas_sk, des, des_sk, dab_kaina+2);
            }
        }
    }

    //MAZINAME PIRMA SKAICIU VIENETU

    naujas_sk = decreaseFirstNum(A, des);

    if(naujas_sk != -1){
        if(naujas_sk < des){
            count(naujas_sk, des/10, des_sk-1, dab_kaina+1);
        }
        else{
            count(naujas_sk, des, des_sk, dab_kaina+1);
        }
    }

    //MAZINAME PASKUTINI SKAICIU VIENETU

    naujas_sk = decreaseLastNum(A);

    if(naujas_sk != -1){
        if(naujas_sk < des){
            count(naujas_sk, des/10, des_sk-1, dab_kaina+1);
        }
        else{
            count(naujas_sk, des, des_sk, dab_kaina+1);
        }
    }

    return best_kaina;
    
}

long long getDes(long long A){
    long long des = 1;

    while(A/des >= 10){
        des *= 10;
    }

    return des;
}

int getDesSk(long long A){
    long long des = 1;
    int des_sk = 1;

    while(A/des >= 10){
        des *= 10;
        des_sk++;
    }

    return des_sk;
}

int main(){
    // int M;
    // long long A;

    // ifstream read_file("test1.in");
    // ofstream write_file("nice.txt");

    // read_file >> M;

    // for(int i = 0;i<M;i++){
    //     read_file >> A;
    //     write_file << count(A);
    // }

    _initialize(100);

    long long A = 2021983;

    //cout << getDesSk(A) << endl;

    cout << count(A, getDes(A), getDesSk(A)) << endl;
}
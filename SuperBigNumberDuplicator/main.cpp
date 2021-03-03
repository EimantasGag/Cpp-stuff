#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

string dup_sum_big_int(string arr[], int arr_size)
{
    string res = "";

    int kartas = 0;

    int add_num = 0;
    int add_num_pos = 0;

    int for_kartai = 0;

    int remem = 0;

    for(int i = arr_size-1;i>=0;i--){
        if(kartas == 0){
           res += arr[i];
        }
        else{
            for(int x = arr[i].length()-1;x>=0;x--){
                add_num_pos = res.length()-kartas-1-for_kartai;
                add_num = int(res[add_num_pos] - '0');

                //cout << "add_num_pos: " << add_num_pos << endl;
                //cout << "res: " << res << endl;
                if(add_num_pos >= 0){
                    if(int(arr[i][x] - '0') + add_num < 10){
                        res[add_num_pos] = char(int(arr[i][x] - '0') + add_num + '0');
                    }
                    else{
                        res[add_num_pos] = char((int(arr[i][x] - '0')+ add_num) % 10 + '0');
                        remem = (int(arr[i][x] - '0') + add_num) / 10;

                        if(add_num_pos-1 >= 0){
                            res[add_num_pos-1] = char(int(res[add_num_pos-1] - '0') + remem + '0');
                        }
                        else{
                            res = char(remem + '0') + res;
                        }
                    }
                }
                else{
                    res = arr[i][x] + res;
                    //cout << "add_num_pos < 0, res: " << res << endl;
                }

                for_kartai++;
            }

            for_kartai = 0;
        }

        kartas++;

    }

    //cout << "gal res: " << res << endl;

    return res;
}

string dup_big_int(string num1, string num2)
{
    string onum2 = num2;

    if(num2.length()<num1.length()){
        num2 = num1;
        num1 = onum2;
    }

    int dup = 0;
    int remem = 0;

    int arr_size = 0;

    int ind = 0;

    int set_size = num1.length();

    if(set_size>1000){
        set_size = 1005;
    }

    string all_res[set_size];

    string res = "";
    string dal_res = "";

    int dup_sum_size = 0;

    for(int i = 0;i<num1.length();i++){
        for(int x = 0;x<num2.length();x++){
            dup = int(num1[i] - '0')*int(num2[x] - '0');

            remem = dup/10;

            if(dup < 10){
                res += char(dup + '0');
                ind++;
            }
            else{
                if(x == 0){
                    res += char(dup/10 + '0');
                    res += char(dup%10 + '0');

                    ind += 2;
                }
                else{
                    res += char(dup%10 + '0');

                    if(int(res[ind-1] - '0') + remem < 10){
                        res[ind-1] = char(int(res[ind-1] - '0')+remem + '0');
                    }
                    else{
                        //cout << "Keiciami skaiciai " << res << endl;
                        for(int n = ind-1;n>=0;n--){
                            if(n == ind-1){
                                if(int(res[n] - '0') + remem == 10){
                                    res[n] = char(0 + '0');
                                    //cout << "== 10, res[" << n << "] = " << res[n] << endl;
                                }
                                else{
                                    res[n] = char((int(res[n] - '0') + remem)%10 + '0');
                                }

                                if(n == 0){
                                    ind++;
                                    res = char(1 + '0') + res;
                                }
                            }
                            else if(int(res[n] - '0') != 9){
                                res[n] = char(int(res[n] + 1 - '0') + '0');
                                //cout << "!= 9, res[" << n << "] = " << res[n] << endl;
                                break;
                            }
                            else{
                                if(n == 0){
                                    ind++;
                                    res = char(1 + '0') + res;
                                }
                                res[n+1] = char(0 + '0'); //jei kas neteisingai patikrink cia
                            }
                        }

                        //cout << "Baigta keisti, pakeitimai: " << res << endl;
                    }

                    ind++;
                }

            }

        }

        ind = 0;

        all_res[arr_size] = res;
        res = "";
        arr_size++;

        if(arr_size > 1000){
            if(dup_sum_size != 0){
                all_res[arr_size] = dal_res;
                dal_res = dup_sum_big_int(all_res,dup_sum_size+1
                                          );
            }
            else{
                dal_res = dup_sum_big_int(all_res,arr_size);
            }

            //std::fill_n(all_res, arr_size, 0); //reikia pabandyti pakeisti su delete[], nes labai daug laiko uzima
            arr_size = 0;
            dup_sum_size += arr_size;
        }

    }

    cout << "dal_res: " << dal_res << endl;
    cout << "arr_size: " << arr_size << endl;

    if(arr_size > 1 && dal_res == ""){
        res = dup_sum_big_int(all_res,arr_size);
    }
    else if(dal_res != ""){
        if(arr_size == 0){
            return dal_res;
        }
        else{
            all_res[arr_size] = dal_res; //jei kas neteisingai patikrink cia
            return dup_sum_big_int(all_res,dup_sum_size+arr_size+1);
        }
    }
    else{
        res = all_res[0];
    }

    return res;
}

string random_number(int number_of_char)
{
    srand (time(NULL));

    string res = "";

    int rand_num;

    while(number_of_char > 0){
        rand_num = rand() % 10;
        res += char(rand_num + '0');
        number_of_char--;
    }

    return res;
}

int main()
{
    int t = 1254618785;

    //"84","45","74","12","99", res = 892619
    //74,12,99 = 7619
    string l[] = {"84","45","7619"};

    string res;

    string num1;
    string num2;

    char ats;

    cout << "Ar norite, kad kompiuteris sugeneruotu automatiskai skaicius? (T/N): "; cin >> ats;

    if(ats == 'T'){
        int dydis;
        cout << "Iveskite dydi skaiciu, kurie bus sugeneruoti: "; cin >> dydis;
        num1 = random_number(dydis);
        num2 = random_number(dydis);
        cout << "Pirmas skaicius: " << num1 << endl;
        cout << "Antras skaicius: " << num2 << endl;
        cout << endl;
    }
    else{
        cout << "Iveskite pirma skaiciu, kuri norite padauginti: "; cin >> num1;
        cout << "Iveskite antra skaiciu kuri norite padauginti: "; cin >> num2;
    }

    res = dup_big_int(num1,num2);

    cout << "Rezultatas: " << res << endl;


    return 0;
}

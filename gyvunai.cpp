#include <bits/stdc++.h>

using namespace std;

int main(){
    int gyv_sk;

    cin >> gyv_sk;

    vector<vector<int>> intervalai;

    for(int i = 0;i<gyv_sk;i++){
        int h1,min1,h2,min2;

        cin >> h1 >> min1 >> h2 >> min2;

        intervalai.push_back({h1,min1,h2,min2});
    }

    int dab_h1,dab_min1,dab_h2,dab_min2;

    dab_h1 = intervalai[0][0];
    dab_min1 = intervalai[0][1];
    dab_h2 = intervalai[0][2];
    dab_min2 = intervalai[0][3];

    int h1,min1,h2,min2;

    bool breakinam = false;
    bool good = false;

    for(int i = 1;i<gyv_sk;i++){
        h1 = intervalai[i][0];
        min1 = intervalai[i][1];
        h2 = intervalai[i][2];
        min2 = intervalai[i][3];

        if(dab_h1 > dab_h2){
            if(h1 > h2){
                h2 += 24;
            }
            else{
                h1 += 24;
                h2 += 24;
            }

            dab_h2 += 24;
        }
        // else if(h1 > h2){
        //     if(dab_h1 > dab_h2){
        //         dab_h2 += 24;
        //     }
        //     else{
        //         dab_h1 += 24;
        //         dab_h2 += 24;
        //     }

        //     h2 += 24;
        // }

        // cout << "Inter: " << dab_h1 << " " << dab_min1 << " " << dab_h2 << " " << dab_min2 << endl;
        // cout << "Inter: " << h1 << " " << min1 << " " << h2 << " " << min2 << endl;

        if(h1 >= dab_h1 && h1 <= dab_h2){
            if(h1 > dab_h1 && h1 < dab_h2){
                good = true;
            }
            else if(h1 == dab_h1 && h1 == dab_h2){
                if(min1 < dab_min2 && min1 > dab_min1){
                    good = true;
                }
            }
            else if(h1 == dab_h1 || h1 == dab_h2){
                if(h1 == dab_h1 && min1 > dab_min1){
                    good = true;
                }
                if(h1 == dab_h2 && min1 < dab_min2){
                    good = true;
                }
            }

            if(good){
                dab_h1 = h1;
                dab_min1 = min1;

                if(h2 >= dab_h1 && h2 <= dab_h2){
                    good = false;

                    if(h2 > dab_h1 && h2 < dab_h2){
                        good = true;
                    }
                    else if(h2 == dab_h1 && h2 == dab_h2){
                        if(min2 < dab_min2 && min2 > dab_min1){
                            good = true;
                        }
                    }
                    else if(h2 == dab_h1 || h2 == dab_h2){
                        if(h2 == dab_h1 && min2 > dab_min1){
                            good = true;
                        }
                        if(h2 == dab_h2 && min2 < dab_min2){
                            good = true;
                        }
                    }

                    if(good){
                        dab_h2 = h2;
                        dab_min2 = min2;
                    }

                    good = true;
                }
            }
        }
        else if(h2 >= dab_h1 && h2 <= dab_h2){
            if(h2 > dab_h1 && h2 < dab_h2){
                good = true;
            }
            else if(h2 == dab_h1 && h2 == dab_h2){
                if(min2 < dab_min2 && min2 > dab_min1){
                    good = true;
                }
            }
            else if(h2 == dab_h1 || h2 == dab_h2){
                if(h2 == dab_h1 && min2 > dab_min1){
                    good = true;
                }
                if(h2 == dab_h2 && min2 < dab_min2){
                    good = true;
                }
            }

            if(good){
                dab_h2 = h2;
                dab_min2 = min2;
            }
        }
        else if(h1 < dab_h1 && h2 > dab_h2){
            good = true;
        }

        if(!good){
            cout << "NE" << endl; 
            breakinam = true;
            break;
        }

        if(dab_h1 >= 24){
            dab_h1 -= 24;
        }
        if(dab_h2 >= 24){
            dab_h2 -= 24;
        }

        good = false;
    }

    if(!breakinam){
        cout << "TAIP" << endl;
        cout << dab_h1 << " " << dab_min1 << " " << dab_h2 << " " << dab_min2 << endl;
    }
}
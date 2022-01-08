#include <bits/stdc++.h>

using namespace std;

bool hor(const vector<vector<int>>& lenta){
    int sk = 0;

    for(int i = 0;i<6;i++){
        for(int x = 0;x<6;x++){
            int num = lenta[i][x];

            if(num == 1){
                sk++;
            }
            else{
                sk = 0;
            }

            if(sk >= 5){
                return true;
            }
        }
    }

    return false;
}

bool ver(const vector<vector<int>>& lenta){
    int sk = 0;

    for(int i = 0;i<6;i++){
        for(int x = 0;x<6;x++){
            int num = lenta[x][i];

            if(num == 1){
                sk++;
            }
            else{
                sk = 0;
            }

            if(sk >= 5){
                return true;
            }
        }
    }

    return false;
}

bool istrz(const vector<vector<int>>& lenta){
    int sk = 0;

    vector<vector<vector<int>>> indeksai = {
        {{0,0},{1,1},{2,2},{3,3},{4,4}},
        {{1,1},{2,2},{3,3},{4,4},{5,5}},
        {{0,1},{1,2},{2,3},{3,4},{4,5}},
        {{0,4},{1,3},{2,2},{3,1},{4,0}},
        {{0,5},{1,4},{2,3},{3,2},{4,1}},
        {{1,4},{2,3},{3,2},{4,1},{5,0}},
        {{1,0},{2,1},{3,2},{4,3},{5,4}},
        {{1,5},{2,4},{3,3},{4,2},{5,1}},
        };

    for(int i = 0;i<indeksai.size();i++){
        int sk = 0;
        for(int x = 0;x<indeksai[i].size();x++){
            int a,b;
            a = indeksai[i][x][0];
            b = indeksai[i][x][1];

            if(lenta[a][b] == 1){
                sk++;
            }

            if(sk == 5){
                return true;
            }
        }
    }

    return false;
}

bool laimi(const vector<vector<int>>& lenta){
    //HORIZONTALIAI
    if(hor(lenta)){
        return true;
    }
    else if(ver(lenta)){
        return true;
    }
    else if(istrz(lenta)){
        return true;
    }

    return false;
}

void kairen(vector<vector<int>>& lenta, int dalis){
    vector<int> res; 

    int s_r;
    int s_c;
    int max;
    int r;

    if(dalis == 1){
        s_r = 0;
        s_c = 2;
        max = 2;
        r = 0;
    }
    else if(dalis == 2){
        s_r = 0;
        s_c = 5;
        max = 2;
        r = 0;
    }
    else if(dalis == 3){
        s_r = 3;
        s_c = 2;
        max = 5;
        r = 3;
    }
    else{
        s_r = 3;
        s_c = 5;
        max = 5;
        r = 3;
    }

    for(int i = 0;i<9;i++){
        res.push_back(lenta[s_r][s_c]);

        if(s_r == max){
            s_r = r;
            s_c--;
        }
        else{
            s_r++;
        }
    }

    if(dalis == 1){
        max = 2;
        s_r = 0;
        s_c = 0;
        r = 0;
    }
    else if(dalis == 2){
        max = 5;
        s_r = 0;
        s_c = 3;
        r = 3;
    }
    else if(dalis == 3){
        max = 2;
        s_r = 3;
        s_c = 0;
        r = 0;
    }
    else{
        max = 5;
        s_r = 3;
        s_c = 3;
        r = 3;
    }

    for(int i = 0;i<9;i++){
        lenta[s_r][s_c] = res[i];

        if(s_c == max){
            s_c = r;
            s_r++;
        }
        else{
            s_c++;
        }
    }
    
}

void desinen(vector<vector<int>>& lenta, int dalis){
    vector<int> res;

    int s_r;
    int s_c;
    int max;
    int r;

    if(dalis == 1){
        s_r = 2;
        s_c = 0;
        max = 0;
        r = 2;
    }
    else if(dalis == 2){
        s_r = 2;
        s_c = 3;
        max = 0;
        r = 2;
    }
    else if(dalis == 3){
        s_r = 5;
        s_c = 0;
        max = 3;
        r = 5;
    }
    else{
        s_r = 5;
        s_c = 3;
        max = 3;
        r = 5;
    }

    for(int i = 0;i<9;i++){
        res.push_back(lenta[s_r][s_c]);

        if(s_r == max){
            s_r = r;
            s_c++;
        }
        else{
            s_r--;
        }
    }

    if(dalis == 1){
        max = 2;
        s_r = 0;
        s_c = 0;
        r = 0;
    }
    else if(dalis == 2){
        max = 5;
        s_r = 0;
        s_c = 3;
        r = 3;
    }
    else if(dalis == 3){
        max = 2;
        s_r = 3;
        s_c = 0;
        r = 0;
    }
    else{
        max = 5;
        s_r = 3;
        s_c = 3;
        r = 3;
    }

    for(int i = 0;i<9;i++){
        lenta[s_r][s_c] = res[i];

        if(s_c == max){
            s_c = r;
            s_r++;
        }
        else{
            s_c++;
        }
    }
}

void printinti(const vector<vector<int>>& lenta){
    for(int i = 0;i<6;i++){
        for(int x = 0;x<6;x++){
            cout << lenta[i][x] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void kopijuoti(vector<vector<int>>& lenta, vector<vector<int>>& kopija){
    kopija.clear();

    for(int i = 0;i<lenta.size();i++){
        kopija.push_back({});
        for(int x = 0;x<lenta[i].size();x++){
            kopija[i].push_back(lenta[i][x]);
        }
    }
}

bool sukti(vector<vector<int>>& lenta){
    vector<vector<int>> kopija;
    kopijuoti(lenta,kopija);

    for(int i = 0;i<4;i++){
        desinen(lenta,i+1);

        if(laimi(lenta)){
            cout << "LAIMI" << endl;
            cout << i+1 << " 270" << endl;
            return true;
        }

        kopijuoti(kopija, lenta);
    }

    for(int i = 0;i<4;i++){
        kairen(lenta,i+1);

        if(laimi(lenta)){
            cout << "LAIMI" << endl;
            cout << i+1 << " 90" << endl;
            return true;
        }

        kopijuoti(kopija, lenta);
    }

    return false;
}

int main(){
    vector<vector<int>> lenta;

    for(int i = 0;i<6;i++){
        lenta.push_back({});
    }

    for(int i = 0;i<6;i++){
        for(int x = 0;x<6;x++){
            int a;
            cin >> a;

            lenta[i].push_back(a);
        }
    }

    // cout << endl;
    // printinti(lenta);
    // desinen(lenta,3);
    // printinti(lenta);
    // cout << "Istrz: " << istrz(lenta) << endl;
    // cout << "Hor: " << hor(lenta) << endl;
    // cout << "Ver: " << ver(lenta) << endl;

    if(!sukti(lenta)){
        cout << "NELAIMI" << endl;
    }

}
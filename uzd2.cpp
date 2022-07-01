#include <iostream>
#include <fstream>

using namespace std;

int iMinutes(int val, int min){
    return val*60+min;
}

int sugaisoLaiko(int val, int min, int bval, int bmin){
    int min1,min2;

    if(val > bval){ //kai 23:00 ir 00:00
        min1 = iMinutes(val,min);
        min2 = iMinutes(bval,bmin) + 24*60;
    }
    else{
        min1 = iMinutes(val,min);
        min2 = iMinutes(bval,bmin);
    }

    return min2-min1;
}

void skaityti(int ryte[], int vakare[]){
    ifstream read_file("U1.txt");

    int begimai;

    read_file >> begimai;

    for(int i = 0;i<begimai;i++){
        int diena;
        int val,min,bval,bmin;

        read_file >> diena;

        read_file >> val >> min;

        read_file >> bval >> bmin;
        ryte[diena] = sugaisoLaiko(val, min, bval, bmin);

        read_file >> val >> min;

        read_file >> bval >> bmin;
        vakare[diena] = sugaisoLaiko(val, min, bval, bmin);
    }
}

void isvalyti(int arr[], int iki_index){
    for(int i = 0;i<iki_index;i++){
        arr[i] = 0;
    }
}

void rastiMin(int ryte[], int vakare[], int res[], int& min){
    int index = 0;
    for(int diena = 0;diena<32;diena++){
        if(ryte[diena] == 0 || vakare[diena] == 0){
            continue;
        }

        if(min == 0){
            min = ryte[diena] + vakare[diena];
            res[index] = diena;
            index++;
        }
        else if(min == ryte[diena] + vakare[diena]){
            min = ryte[diena] + vakare[diena];
            res[index] = diena;
            index++;
        }
        else if(min > ryte[diena] + vakare[diena]){
            min = ryte[diena] + vakare[diena];

            //isvalyti arr
            isvalyti(res, index);
            
            index = 0;
            res[index] = diena;
        }
    }
}

void init(int arr[]){
    for(int i = 0;i<32;i++){
        arr[i] = 0;
    }
}

void rasyti(int res[], int min){
    ofstream write_file("U1rez.txt");

    write_file << "Minimalus laikas" << endl;
    write_file << min << endl;
    write_file << "Dienos" << endl;

    for(int i = 0;i<31;i++){
        if(res[i] == 0){
            return;
        }

        write_file << res[i] << " ";
    }
}

int main(){
    int ryte[32], vakare[32];
    init(ryte); init(vakare);

    skaityti(ryte, vakare);

    int res[31];
    init(res);

    int maz_laikas = 0;
    rastiMin(ryte, vakare, res, maz_laikas);

    rasyti(res, maz_laikas);
}
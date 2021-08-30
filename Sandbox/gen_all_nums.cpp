#include <iostream>
#include <vector>

using namespace std;

vector<string> all_num;

int g(int sk_k, vector<int> skai_arr, string txt){

    for(int i = 0;i<skai_arr.size();i++){

        txt += char(skai_arr[i] + '0');

        if(sk_k-1 != 0){ 
            g(sk_k-1, skai_arr, txt);
        }
        else{
            all_num.push_back(txt);
        }

        txt.pop_back();
    }

    return 0;
}

int main()
{
    g(3,{0,1,2,3,4},""); //sugeneruoja visus sk_k skaitmenu skaicius kuriuos galima padaryti is skai_arr skaitmenu

    for(int i = 0;i<all_num.size();i++){
        cout << all_num[i] << endl;
    }

    cout << "\n\n" << "Skaiciu kiekis: " << all_num.size() << endl;

}
#include <iostream>
#include <vector>

using namespace std;

void generateLPSarray(vector<int>& lps_arr, const string& pat){
    int cur_ind = 1;
    int ps_len = 0; //longest prefix-sufix length

    lps_arr.push_back(0);

    while(cur_ind < pat.length()){
        if(pat[cur_ind] == pat[ps_len]){
            ps_len++;
            lps_arr.push_back(ps_len);
            cur_ind++;
        }
        else{
            if(ps_len != 0){
                ps_len = lps_arr[ps_len-1];
            }
            else{
                lps_arr.push_back(ps_len);
                cur_ind++;
            }
        }
    }
}

void KMPsearch(const string& txt, const string& pat){
    vector<int> lps_arr;
    generateLPSarray(lps_arr, pat);

    int pat_ind = 0;
    int txt_ind = 0;

    while(txt_ind < txt.length()){
        if(txt[txt_ind] == pat[pat_ind]){
            pat_ind++;
            txt_ind++;
        }

        if(pat_ind == pat.length()){
            cout << "Pattern start at index: " << txt_ind-pat_ind << endl;
            pat_ind = lps_arr[pat_ind-1];
        }
        else if(txt_ind < txt.length() && txt[txt_ind] != pat[pat_ind]){
            if(pat_ind == 0){
                txt_ind++;
            }
            else{
                pat_ind = lps_arr[pat_ind-1];
            }
        }
    }

}

int main(){
    KMPsearch("mammamam","mam");
}
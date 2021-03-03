#include <iostream>
#include <fstream>
#include "C:\Users\Inesa\Desktop\C++\TimeMeasure.h"

using namespace std;

struct LinkedList{
    int data;
    LinkedList* next;
};

LinkedList* linked_start;

int rec(int sek_sk);

int main()
{
    ifstream fr("nice.txt");
    ofstream fd("bokstas-vyr.out");

    int kal_sk, sek_sk;

    fr >> kal_sk >> sek_sk;

    int d;

    LinkedList* b;

    for(int i = 0;i<kal_sk;i++){
        fr >> d;

        LinkedList* a = new LinkedList();

        //cout << i+1 << ". " << a << endl;

        (*a).data = d;

        if(i != 0){
            (*b).next = a;
        }
        else{
            linked_start = a;
        }
        

        b = a;
    }

    int aukstis;

    if(sek_sk != 1){
        aukstis = rec(sek_sk);
    }
    else{
        cout << "0" << endl;
        return 0;
    }

    LinkedList* l = linked_start;

    cout << aukstis << endl;

    if(l == nullptr){
        cout << "0" << endl;
    }

    while(l != nullptr){
        //cout << (*l).data << endl;
        l = (*l).next;
    }
    
    return 0;
}

int rec(int sek_sk)
{
    LinkedList* kub = linked_start;

    LinkedList* buv_kub = nullptr;

    LinkedList* kitok_kub_prad = nullptr;

    int kub_sk;
    int buv_kub_sk = -1;

    int kartojasi = 1;

    bool testi = false;

    int sk = 0;

    while(kub != nullptr){
        kub_sk = (*kub).data;

        sk++;

        if((*kub).next == nullptr){
            if(kub_sk == buv_kub_sk){
                kartojasi++;
            }
        }

        if(kub_sk != buv_kub_sk || ((*kub).next == nullptr)){
            if(kartojasi >= sek_sk){

                if(kitok_kub_prad == nullptr){
                    if((*kub).next != nullptr){
                        linked_start = kub;
                    }
                    else{
                        if(kub_sk == buv_kub_sk){
                            linked_start = nullptr;
                        }
                        else{
                            linked_start = kub;
                        }       
                    }
                }
                else if((*kub).next == nullptr){
                    if(kub_sk == buv_kub_sk){
                        (*kitok_kub_prad).next = nullptr;
                    }
                    else{
                        (*kitok_kub_prad).next = kub;
                    }
                    
                }
                else{
                    (*kitok_kub_prad).next = kub;
                }

                testi = true;
            }   
            else if(buv_kub != nullptr){
                kitok_kub_prad = buv_kub;
            }
            
            kartojasi = 1;
            
        }
        else{
            kartojasi++;
        }


        buv_kub = kub;

        kub = (*kub).next;

        buv_kub_sk = (*buv_kub).data;
    }

    if(testi){
        return rec(sek_sk);
    }
    else{
        return sk;
    }

}
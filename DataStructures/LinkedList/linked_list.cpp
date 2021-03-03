#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

struct LinkedList{
    int data;
    LinkedList *next;
};

int main()
{
    int times = 0;

    clock_t start,end;

    start = clock();

    LinkedList *b;

    LinkedList *f;

    for(int i = 0;i<1000000;i++){
        LinkedList* a = new LinkedList();
        (*a).data = i;

        if(times != 0){
            (*b).next = a;
        }
        else{
            f = a;
        }

        b = a;
    }

    int d = 0;

    while(f != nullptr){
        d = (*f).data; 
        f = (*f).next; 
    }

    end = clock();

    double res = double(end - start)/double(CLOCKS_PER_SEC);

    cout << times << endl;
    
    //Linked listai yra labai naudingi, norint "iskirpti" dali is listo ir pakeisti, nes reikia pakeisti tik next, o vector 
    //turi sukurt nauja vectoriu O(n)

    cout << "Kodas kompiliavosi per: " << fixed << res << setprecision(5) << endl;

    return 0;
}
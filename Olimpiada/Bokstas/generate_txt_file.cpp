#include <fstream>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int main()
{
    ofstream fd("nice.txt");

    int num_of_elem;
    int pasik;

    cout << "Ivesk skaiciu kieki: "; cin >> num_of_elem;
    cout << "Ivesk pasikartojanciu: "; cin >> pasik;

    int num = 0;

    srand(time(NULL));

    fd << num_of_elem << " " << pasik << endl;

    for(int i = 0;i<num_of_elem;i++){

        num = rand() % 2;

        fd << num << endl;
    }
}
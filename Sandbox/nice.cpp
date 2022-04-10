#include <iostream>

using namespace std;

struct Nice{
    int val = 1528349827;
    Nice* ptr;
};

int main(){
    Nice nice;
    cout << nice.val << endl;
}
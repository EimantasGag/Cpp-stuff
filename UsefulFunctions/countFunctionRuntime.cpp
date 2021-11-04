#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;


int countRuntime(void *(func())){
    auto start = high_resolution_clock::now();

    func();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Duration: " << duration.count() << endl;
}

int main(void *(func())){

}
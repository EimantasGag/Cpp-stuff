#include <iostream>

int main(int argc, char** argv) {
    auto response = cpr::Get(cpr::Url{"http://httpbin.org/get"});
    std::cout << response.text << std::endl;
}
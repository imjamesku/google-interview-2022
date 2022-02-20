#include <iostream>
using namespace std;

int main(void) {
    int a = 100;
    int& b = a;
    auto& c = b;
    c = 123;
    cout << b << "\n";
    return 0;
}
#include <iostream>
using namespace std;
int main(void) {
    int a = 0;
    auto lambda = [&a](int a) {
        cout << a << "\n";
    };
    lambda(100);
}
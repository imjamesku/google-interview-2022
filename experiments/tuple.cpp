#include <iostream>
#include <tuple>
using namespace std;

int main(void) {
    tuple<int, int, int> t{1, 2, 3};
    auto [a, b, c] = t;
    b = 123;
    cout << a << "\n";
    cout << get<1>(t) << "\n";
}
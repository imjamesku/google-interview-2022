#include <iostream>
using namespace std;

constexpr int square(int a) {
    return a * a;
}
int main(void) {
    int a = 10;
    int b;
    cin >> b;
    if (b == 5) {
        a = 20;
    }
    int s = square(a);
    cout << s << "\n";
}
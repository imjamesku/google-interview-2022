#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main(void) {
    tuple<int, int, int> t{1, 2, 3};
    auto [a, b, c] = t;
    b = 123;
    cout << a << "\n";
    cout << get<1>(t) << "\n";

    vector<vector<int>> visited(2, vector<int>(2, false));
    vector<tuple<int, int, int>> stack{{1, 2, 3}};
    tuple<int, int, int> testTuple = {1, 2, 3};
    auto [e1, e2, e3] = testTuple;
}
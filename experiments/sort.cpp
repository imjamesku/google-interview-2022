#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> data{2, 10, 5, 43, 5, 1, 9};
    sort(data.begin(), data.end(), [](int const& a, int const& b) { return a > b; });
    for (int n : data) {
        cout << n << "\n";
    }
}
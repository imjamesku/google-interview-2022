#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;
int main(void) {
    for (auto [i, j] : vector<tuple<int, int>>{{0, 1}, {0, 2}}) {
        printf("i: %d, j: %d\n", i, j);
    }
}
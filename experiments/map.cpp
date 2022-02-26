#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    unordered_map<int, int> umap;

    cout << umap.at(0) << "\n";
}
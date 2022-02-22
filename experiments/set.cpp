#include <iostream>
#include <unordered_set>
using std::cout;
int main(void) {
    std::unordered_set<int> set;
    set.insert(1);
    set.insert(1);
    set.insert(1);
    cout << "size: " << set.size() << "\n";

    std::unordered_multiset<int> mset;
    mset.insert(1);
    mset.insert(1);
    mset.insert(1);
    cout << "size: " << mset.size() << "\n";
}
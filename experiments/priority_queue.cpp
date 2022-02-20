#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct cmp {
    bool operator()(int a, int b) {
        return b < a;
    }
};
int main(void) {
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(3);
    pq.push(100);
    pq.push(123);
    pq.push(5);
    cout << pq.top() << "\n";
    return 0;
}
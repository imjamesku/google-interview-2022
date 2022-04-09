#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string s = "abc123";
    cout << "sub: " << s.substr(0, -2) << "\n";
    char const* p = s.c_str();
    for (size_t i = 0; i <= s.size(); i++) {
        char c = *(p + i);
        cout << *(p + i) << "\n";
        cout << (c != '\0' ? "is char" : "not char")
             << "\n";
    }
    return 0;
}
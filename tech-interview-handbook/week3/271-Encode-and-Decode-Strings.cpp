#include <string>
#include <vector>

using namespace std;
// first try

class Codec {
   public:
    const string sep = "<sep>";

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // <sep> as sep
        string encoded;
        for (string& s : strs) {
            encoded += s + sep;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int start = 0;
        int pos = 0;
        while ((pos = s.find(sep, start)) != string::npos) {
            int len = pos - start;
            decoded.push_back(s.substr(start, len));
            start = pos + sep.size();
        }
        return decoded;
    }
};
// Codec::
// version 2
class Codec {
   public:
    // Encodes a list of strings to a single string.
    int const chunkBytes = 3;
    string numToS(int num) {
        string s = to_string(num);
        return string(chunkBytes - s.size(), '0') + s;
    }
    string encode(vector<string>& strs) {
        // <sep> as sep
        string encoded;
        for (string& s : strs) {
            encoded += numToS(s.size()) + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int start = 0;
        // cout << s << "\n";
        while (start < s.size()) {
            int len = stoi(s.substr(start, chunkBytes));
            decoded.push_back(s.substr(start + chunkBytes, len));
            start = start + len + chunkBytes;
        }
        return decoded;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
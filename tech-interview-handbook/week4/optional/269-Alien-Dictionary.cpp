#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Fist attempt. Spent like an hour
class Solution {
   public:
    string alienOrder(vector<string>& words) {
        // z az ab
        // z->a, z->b

        // t->f
        // w->e
        // r->t
        // e->r
        //  topological sort
        //  children, parent count
        unordered_map<char, unordered_set<char>> children;
        unordered_map<char, int> parentCount;
        unordered_set<char> charSet;
        for (auto& word : words) {
            for (char c : word) {
                charSet.insert(c);
            }
        }
        // build graph
        for (int i = 0; i < words.size() - 1; ++i) {
            bool breaked = false;
            for (int j = 0; j < words[i].size() && j < words[i + 1].size(); j++) {
                if (words[i][j] != words[i + 1][j]) {
                    char parent = words[i][j], child = words[i + 1][j];
                    if (!children[parent].count(child)) {
                        children[parent].insert(child);
                        parentCount[child]++;
                    }
                    breaked = true;
                    break;
                }
            }
            if (!breaked && words[i].size() > words[i + 1].size()) {
                // invalid input. eg: ["abc", "ab"]
                return "";
            }
        }

        string zeroPre = "";

        for (char c : charSet) {
            if (parentCount[c] == 0) {
                zeroPre += c;
            }
        }
        for (int i = 0; i < zeroPre.size(); i++) {
            for (char next : children[zeroPre[i]]) {
                parentCount[next]--;
                if (parentCount[next] == 0) {
                    zeroPre += next;
                }
            }
        }
        if (zeroPre.size() == charSet.size()) {
            return zeroPre;
        }
        return "";
    }
};
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// first working solution
class Solution {
   public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int lastEnd = 0;
        string res = "";
        // sort by indices
        auto sortedIndices = getSortedIndices(indices);

        auto newIndices = applyIndices(indices, sortedIndices);
        auto newSources = applyIndices(sources, sortedIndices);
        auto newTargets = applyIndices(targets, sortedIndices);

        for (int i = 0; i < newIndices.size(); i++) {
            if (newIndices[i] > lastEnd) {
                // end not including
                res += s.substr(lastEnd, newIndices[i] - lastEnd);
            }
            if (s.substr(newIndices[i], newSources[i].size()) == newSources[i]) {
                res += newTargets[i];
                lastEnd = newIndices[i] + newSources[i].size();
            } else {
                lastEnd = newIndices[i];
            }
        }
        if (lastEnd < s.size()) {
            res += s.substr(lastEnd, string::npos);
        }
        return res;
    }

   private:
    vector<int> getSortedIndices(vector<int>& vec) {
        vector<int> ref(vec.size());
        std::iota(ref.begin(), ref.end(), 0);
        sort(ref.begin(), ref.end(), [&](int a, int b) {
            return vec[a] < vec[b];
        });
        return ref;
    }
    template <typename T>
    vector<T> applyIndices(vector<T>& original, vector<int>& indices) {
        vector<T> applied(original.size());
        for (int i = 0; i < applied.size(); i++) {
            applied[i] = original[indices[i]];
        }
        return applied;
    }
};

class Solution {
   public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int lastEnd = 0;
        string res = "";
        // sort by indices
        unordered_map<int, string> sourcesMap, targetsMap;

        for (int i = 0; i < indices.size(); i++) {
            sourcesMap[indices[i]] = sources[i];
            targetsMap[indices[i]] = targets[i];
        }

        sort(indices.begin(), indices.end());

        for (int i : indices) {
            // end not including
            res += s.substr(lastEnd, i - lastEnd);
            if (s.substr(i, sourcesMap[i].size()) == sourcesMap[i]) {
                res += targetsMap[i];
                lastEnd = i + sourcesMap[i].size();
            } else {
                lastEnd = i;
            }
        }
        if (lastEnd < s.size()) {
            res += s.substr(lastEnd, string::npos);
        }
        return res;
    }
};
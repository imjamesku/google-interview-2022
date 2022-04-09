#include <string>
#include <vector>

using namespace std;

// fist attempt. took about 50 mins
class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> toInclude;
        int totalWordsLen = 0;
        vector<string> result;
        for (size_t i = 0; i < words.size(); i++) {
            // min length of all previously included words
            int currentLen = toInclude.size() >= 2 ? totalWordsLen + toInclude.size() - 1 : totalWordsLen;
            // current len with current word included
            int newLen = currentLen > 0 ? currentLen + 1 + words[i].size() : words[i].size();

            if (newLen > maxWidth) {
                // construct row
                result.push_back(buildRow(maxWidth, words, toInclude));

                // reset
                totalWordsLen = words[i].size();
                toInclude.clear();
                toInclude.push_back(i);
            } else {
                // append to current row
                toInclude.push_back(i);
                currentLen += 1 + words[i].size();
                totalWordsLen += words[i].size();
            }
        }
        if (toInclude.size() > 0) {
            result.push_back(buildLastRow(maxWidth, words, toInclude));
        }
        return result;
    }

   private:
    string buildLastRow(int maxWidth, vector<string>& words, vector<int>& toInclude) {
        string row = words[toInclude[0]];
        for (int i = 1; i < toInclude.size(); i++) {
            row += " " + words[toInclude[i]];
        }
        row = row + string(maxWidth - row.size(), ' ');
        return row;
    }
    string buildRow(int maxWidth, vector<string>& words, vector<int>& toInclude) {
        if (toInclude.size() == 1) {
            auto& word = words[toInclude[0]];
            return word + string(maxWidth - word.size(), ' ');
        }
        int totalWordsLen = 0;
        for (int wordIdx : toInclude) {
            totalWordsLen += words[wordIdx].size();
        }
        string row = "";
        int spaces = toInclude.size() - 1;
        int baseSpaceLen = (maxWidth - totalWordsLen) / spaces;
        int remaining = (maxWidth - totalWordsLen) % spaces;
        for (int wordIdx : toInclude) {
            row += words[wordIdx];
            if (spaces > 0) {
                row += string(baseSpaceLen, ' ');
                spaces--;
            }
            if (remaining > 0) {
                row += " ";
                remaining--;
            }
        }
        return row;
    }
};
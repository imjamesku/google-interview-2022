#include <vector>
using namespace std;

// first attempt: 13mins
class Solution {
   public:
    bool removeOnes(vector<vector<int>>& grid) {
        // flip first row or not flip the first row
        auto temp = grid;
        // not flip first row
        for (int i = 0; i < temp[0].size(); i++) {
            if (temp[0][i] == 1) {
                flipCol(temp, i);
            }
        }
        bool flag = true;
        for (int i = 0; i < temp.size(); i++) {
            if (checkRow(temp[i]) == false) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
        // flip first row
        temp = grid;
        flipRow(temp, 0);
        for (int i = 0; i < temp[0].size(); i++) {
            if (temp[0][i] == 1) {
                flipCol(temp, i);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            if (checkRow(temp[i]) == false) {
                flag = false;
                break;
            }
        }
        return flag;
    }

   private:
    void flipCol(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); i++) {
            grid[i][col] = !grid[i][col];
        }
    }
    void flipRow(vector<vector<int>>& grid, int row) {
        for (int i = 0; i < grid[row].size(); i++) {
            grid[row][i] = !grid[row][i];
        }
    }
    bool checkRow(vector<int>& row) {
        auto first = row[0];
        for (int n : row) {
            if (n != first) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
   public:
    bool removeOnes(vector<vector<int>>& grid) {
        // check if all rows are the same pattern
        for (int i = 1; i < grid.size(); i++) {
            bool invert = grid[i][0] == grid[0][0];
            for (int j = 1; j < grid[0].size(); j++) {
                if (invert != (grid[i][j] == grid[0][j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
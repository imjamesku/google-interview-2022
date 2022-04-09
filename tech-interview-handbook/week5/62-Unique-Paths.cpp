class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m, vector<int>(n, 0));
        table[0][0] = 1;
        auto getCell = [&](int i, int j) {
            if (i >= 0 && i < m && j >= 0 && j < n) {
                return table[i][j];
            }
            return 0;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] += getCell(i - 1, j) + getCell(i, j - 1);
            }
        }
        return table[m - 1][n - 1];
    }
};
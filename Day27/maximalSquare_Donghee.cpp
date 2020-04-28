// Donghee Lee
// 4/27/2020

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        
        int rsize = matrix.size();
        int csize = matrix[0].size();
        
        // dp array
        vector<vector<int>> dp(rsize, vector<int>(csize));
        int maxsize = 0;
        int n = -1;

        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (matrix[i][j] != '0') {
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        // minimum of surrounding (above left, above, left cells) + 1
                        n = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                    } else {
                        n = 1;
                    }
                    dp[i][j] = n;
                    maxsize = max(maxsize, n);
                } // if it is 0, then stay 0
            }
        }

        return maxsize * maxsize;
    }
};
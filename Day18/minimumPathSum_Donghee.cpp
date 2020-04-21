class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {

        // vec should be initialized to INT_MAX : unvisited
        vector<vector<int>> vec(grid.size(), vector<int>(grid[0].size()));
        vec[0][0] = grid[0][0];
        
        for (int i = 1; i < grid.size(); i++) {
            vec[i][0] = grid[i][0] + vec[i-1][0];
        }
        
        for (int j = 1; j < grid[0].size(); j++) {
            vec[0][j] = grid[0][j] + vec[0][j-1];
        }
        
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                vec[i][j] = min(vec[i-1][j] + grid[i][j], vec[i][j-1] + grid[i][j]);
            }
        }

        return vec[grid.size()-1][grid[0].size()-1];
    }
    

    /* Exceeds the Time Limit */    
//     int minPathSum(vector<vector<int>>& grid) {

//         // vec should be initialized to INT_MAX : unvisited
//         vector<vector<int>> vec(grid.size(), vector<int>(grid[0].size(), INT_MAX));
//         vec[0][0] = grid[0][0];

//         return helper(grid, vec, 0, 0);
//     }
    
//     int helper(vector<vector<int>>& org, vector<vector<int>>& vec, int i, int j) {
//         if (i >=  org.size() || j >= org[0].size()) return INT_MAX;
        
//         if (i == org.size() - 1 && j == org[0].size() - 1) return vec[i][j];
        
//         if (i + 1 < org.size()) vec[i+1][j] = min(vec[i+1][j], vec[i][j] + org[i+1][j]);
//         if (j + 1 < org[0].size()) vec[i][j+1] = min(vec[i][j+1], vec[i][j] + org[i][j+1]);
        
//         return min(helper(org, vec, i+1, j), 
//                    helper(org, vec, i, j+1));
//     }

};
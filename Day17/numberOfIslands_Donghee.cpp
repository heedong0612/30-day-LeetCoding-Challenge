class Solution {
public:
    
    void search(int i, int j, vector<vector<char>>& grid) {
		grid[i][j] = '0';
        if (j-1 >= 0 && grid[i][j-1] == '1') search(i,j-1, grid);
        if (j+1 < grid[0].size() && grid[i][j+1] == '1') search(i, j+1, grid);
        if (i-1 >= 0 && grid[i-1][j] == '1') search(i-1, j, grid);
        if (i+1 < grid.size() && grid[i+1][j] == '1') search(i+1, j, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() < 1) return 0;
        if (grid[0].size() < 1) return 0; // check
        int num = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    num++;
                    search(i, j, grid);
                }
            }
        } 
        return num;
    }

};
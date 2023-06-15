class Solution {
public:
    
    
    int helper(int row, int col, vector<vector<int>> &grid, vector<vector<int>>&dp)
    {
        // Negative Base Case: Out of the Grid
        if(row >= grid.size() || col >= grid[0].size()) 
            return INT_MAX;
                
        // Positive Base Case: Destination is Reached
        if(row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
                
        if(dp[row][col] != -1) return dp[row][col];

        int horizontal = helper(row, col + 1, grid, dp); 
        int vertical = helper(row + 1, col, grid, dp);
        
        return dp[row][col] = min(horizontal, vertical) + grid[row][col];
    }
    
    
    
    int tab(vector<vector<int>> grid)
    {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , INT_MAX));
        // base case ;
         for(int i= n - 1; i>=0; i--){
                for(int j= m  - 1; j>=0; j--){
                    if(i == n - 1 && j == m - 1){
                        dp[i][j] = grid[i][j];
                        continue;
                    }
                    
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
                }
            }
        
            return dp[0][0];
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int n = grid.size() ;
        // int m = grid[0].size() ;
        // vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
        // return helper(0 , 0 , grid , dp) ;
        return tab(grid) ;
    }
};
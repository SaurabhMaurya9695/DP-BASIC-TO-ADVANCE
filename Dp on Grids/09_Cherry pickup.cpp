class Solution {
public:
    
    int dp[51][51][2600] ;
    int solve(int i1 , int j1 , int i2 , int j2 , int n , int m , vector<vector<int>> &grid ){
        
        if(i1 >= n ||  j1 >= m ||  i2 >= n||  j2 >= m ||  grid[i1][j1] == -1 ||  grid[i2][j2] == -1){
            return INT_MIN ;
        }
        
        if(i1 == n - 1 && j1 == m - 1) // both reached at same time so check for one only 
        {
            return grid[i1][j1] ;
        }
        
        if(dp[i1][i2][j1] != -1){
            return dp[i1][i2][j1] ;
        }
        int ans = grid[i1][j1] + grid[i2][j2];
        if(i1 == i2 && j1 == j2){
            ans -= grid[i1][j1] ;
        }
        
        int RR = solve(i1, j1 + 1, i2, j2 + 1, n , m , grid);
        int RD = solve(i1, j1 + 1, i2 + 1, j2, n , m , grid);
        int DR = solve(i1 + 1, j1, i2, j2 + 1, n , m , grid);
        int DD = solve(i1 + 1, j1, i2 + 1, j2, n , m , grid);
        
        return dp[i1][i2][j1] = max({RR , RD , DR , DD}) + ans ;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp)) ;
        int ans =  solve(0 , 0 , 0 , 0 , grid.size() , grid[0].size(), grid) ;
        return (ans <= 0) ? 0 : ans ;
    }
};
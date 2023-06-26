class Solution {
public:
    
    const int x8[8] = {+1, +1, -1, -1, +2, +2, -2, -2};
    const int y8[8] = {+2, -2, +2, -2, +1, -1, +1, -1};
    
    
    double solve(int n , int k , int r , int c , vector<vector<vector<double>>> &dp) {
        if(k == 0){
            return 1.0 ;
        }
        
        if(dp[r][c][k] != -1){
            return dp[r][c][k];
        }
        double probability = 0.0 ;
        for(int i = 0 ; i < 8  ; i++){
            int new_row = r + x8[i];
            int new_col = c + y8[i];
            
            if(new_row >=0 && new_row < n && new_col >=0 && new_col < n){
                probability = probability + ((1.0 / 8.0) * solve(n , k - 1 , new_row , new_col , dp ));
            }
        }
        
        return dp[r][c][k] = probability ;
    }
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(n , k , r , c , dp);
    }
};
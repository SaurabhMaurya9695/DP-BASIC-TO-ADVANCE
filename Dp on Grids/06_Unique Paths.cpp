
// unique paths 1 ;
class Solution {
public:
    
    int solve(int i , int j , int m , int n , vector<vector<int>> &dp)
    {
        if(i < 0 ||j  < 0)
        {
            return INT_MAX ;
        }

        if(i ==  m - 1 || j == n-1)
        {
            return 1 ;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j] ;
        }
        int right = solve(i + 1 , j , m , n , dp) ;
        int down = solve(i , j + 1 , m , n , dp);
        return dp[i][j] = (right + down) ;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1 , -1));
        return solve(0 , 0 , m , n, dp) ;
        
    }
};


// ``````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n)) ;
        dp[m-1][n-1] = 1;
        for(int r = m-1; r >= 0; r--){
            for(int c = n-1; c >= 0; c--){
                if(r+1 < m){
                    dp[r][c] += dp[r+1][c];
                }
                else{
                    dp[r][c] += 0;
                }
                if(c+1 < n){
                    dp[r][c] += dp[r][c+1];
                }
                else{
                    dp[r][c] += 0;
                }
            }
        }
        return dp[0][0];
    }
};

// permutation and combination
class Solution {
public:
    int uniquePaths(int m, int n) {
        // for 2 * 3 -> paths are ;
        // r r d , d r r , r d r  
        // now you observe for each every m no of coloum -> you have to go (m - 1) times right ;
        // and for every row -> you have to go (n - 1) dowm ;
        // (m - 1) + (n - 1) = > (m + n - 2) ;
        // you need to fill in 3 boxex out of 2 right or 1 left ;
        // (m + n - 2) C (n - 1) or (m + n - 2) C (m - 1) 
        int N = m + n - 2;
        int r = m - 1 ;
        double res = 1 ;
        // nCr = n * (n - 1) * (n - 2) .... / 1 * 2 * 3 ... r
        for(int i = 1; i <= r; i ++){
            res = res *  (N - r + i) / i ;
        }

        return (int)res ;
    }
};
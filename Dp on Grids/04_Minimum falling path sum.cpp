// multiple source -> multiple destination

public:
    
    int solve(vector<vector<int>> &arr , vector<vector<int>> &dp , int i , int j , int n , int m)
    {
        // base case ;
        // boundary condition
        if( (i < 0  ||  j < 0 || j >= m) )
        {
            return INT_MAX ;
        }
        if( i == n - 1)
        {
            return arr[i][j] ;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int udiag = solve(arr , dp , i + 1 , j - 1 , n , m) ;
        int row   = solve(arr , dp , i + 1 , j , n , m) ;
        int ldiag = solve(arr , dp , i + 1 , j + 1 , n , m);
        int ans = arr[i][j] + min(udiag , min(row , ldiag)) ;
        return dp[i][j] = ans ;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , -1)) ;
        int res = INT_MAX ; 
        for(int j = 0 ; j< m ; j++)
        {
            int ans = solve(matrix , dp , 0 , j , n , m) ; // from every index , our possible ans is ? 
            res = min(res , ans) ;
        }
        return res ;
        
    }
};


//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e6));
        for(int j = 0; j < n; j++) {  // fillled last row
            dp[n - 1][j] = matrix[n - 1][j];
        }
        for(int i = n - 2; i >= 0; i--) { // starting from last - 1 row
            for(int j = 0; j < n; j++) { // filled every column 
                // write all conditions herer
                int minSum = dp[i + 1][j];
                if(j - 1 >= 0) minSum = min(minSum, dp[i + 1][j - 1]);
                if(j + 1 < n) minSum = min(minSum, dp[i + 1][j + 1]);
                dp[i][j] = matrix[i][j] + minSum;
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());  // your ans store at first row ;
    }
};
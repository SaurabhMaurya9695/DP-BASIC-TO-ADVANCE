class Solution {
public:
    
            // Recursion + Memorization -> top down 
    int solve(int idx , int n , vector<int>&dp)
    {
        if(idx > n) return 0 ; // base case ;
        if(idx ==  n ) return 1;
        if(dp[idx] != -1) return dp[idx]; // lookup
        int left = solve(idx + 1 , n , dp) ;
        int right = solve(idx + 2 , n , dp);
        return dp[idx] = left + right ;
    }
    
    
    int climbStairs(int n) {
        // vector<int> dp(n + 1 , -1);
        //Tabulation 
        
        // vector<int> dp(n + 1) ;
        // if(n == 0 || n == 1) return 1;
        // dp[0] = 1;
        // dp[1] = 1 ;
        // dp[2] = 2 ;
        // for(int i = 3 ; i <= n; i++)
        // {
        //     dp[i ] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        
        
        
        //space optimization
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        int a = 1 ;
        int b = 2;
        int c = 0 ;
        for(int i = 3 ; i<=n ; i++)
        {
            c = a +  b ;
            a = b;
            b = c;
        }
        return c ;
        
        
    }
};










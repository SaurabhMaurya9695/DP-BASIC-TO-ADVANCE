class Solution {
public:
                // Recursion 
        int tribonacci(int n) 
        {
            if(n == 0) return 0;
            if(n == 1) return 1 ;
            if( n == 2) return 1;
            else{
                return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
            }
        }

// ................................................................................

                    // Memorization
    int solve(vector<int>&dp  , int n)
    {
        if(n == 0) return 0;
        if(n == 1) return 1 ;
        if( n == 2) return 1;
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        dp[n] = solve(dp ,  n - 1) + solve(dp ,  n - 2) + solve(dp , n - 3);
        return dp[n];
        
    }
    
    int tribonacci(int n)
    {
        vector<int> dp(n + 1 , -1);
        return solve(dp ,  n);
    }
    
// ................................................................................

                    // 3 - tabulation 
    int tribonacci(int n) 
    {
        vector<int> dp(38);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }

// ................................................................................

    
                // 4 - space optimization 
    int tribonacci(int n)
    {
        if(n == 0) return 0;
        if(n == 1) return 1 ;
        if( n == 2) return 1;
        int prev1 = 0 ;
        int prev2 = 1 ;
        int prev3 = 1 ;
        int curr = 0 ;
        for(int i = 3 ; i <= n ; i++)
        {
            curr = prev1 + prev2 +  prev3;
            prev1 = prev2 ;
            prev2 = prev3 ;
            prev3 = curr ;
        }
        return curr;
    }
};





class Solution
{
    public:
    #define mod 1000000007
    //Function to count the number of ways in which frog can reach the top.
     int solve(int idx , int n , vector<int>&dp)
    {
        if(idx > n) return 0 ; // base case ;
        if(idx ==  n ) return 1;
        if(dp[idx] != -1) return dp[idx]; // lookup
        int a = solve(idx + 1 , n , dp) ;
        int b = solve(idx + 2 , n , dp);
        int c =  solve(idx + 3 , n , dp);
        return dp[idx] = ((a % mod +  b % mod ) % mod  +  c % mod ) % mod ;
    }
    long long countWays(int n)
    {
        vector<int> dp(n + 1 , -1);
        return solve(0 , n , dp) % mod;
    }
};
class Solution {
public:
    #define ll long long 
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<ll> ptr(primes.size() ) ;
        vector<ll> dp(n + 1);
        dp[0] = 1 ;
        for(ll i = 1 ; i <= n ; i++) // for filling dp 
        {
            ll ans = INT_MAX;
            for(ll j = 0 ; j < primes.size() ; j ++)
            {                                             // 0 1 2 3
                ans = min(ans , dp[ptr[j]] * primes[j]) ; // 2 3 4 1 =>  1
            }                                             // 1 1 2 2 => ptr
            dp[i] = ans ;
            
            // update pointer ;
            for(ll j = 0 ; j< primes.size() ; j++)
            {
                if(ans == dp[ptr[j]] * primes[j])  // 1 1
                {
                    ptr[j]++;
                }
            }
        }
        
        return dp[n - 1];
        
        
    }
};
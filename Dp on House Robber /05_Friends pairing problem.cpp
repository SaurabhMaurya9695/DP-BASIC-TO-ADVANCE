
// https://www.codingninjas.com/codestudio/problems/friends-pairing-problem_1214625?leftPanelTab=1

class Solution
{
public:

#define ll long long
#define mod 1000000007
    int solve(ll n , vector<ll> &dp)
    {
        if(n == 0 || n ==1) return 1 ;
        if(dp[n] != -1)
        {
            return dp[n];
        }
        // two choices  ;
        ll single = solve( n - 1 , dp) % mod ;
        ll pair = (solve( n - 2 , dp) * (n  - 1)) % mod ;
        return (dp[n] = single + pair ) % mod ;
    }
    int countFriendsPairings(int n) 
    { 
        vector<ll> dp(n + 1 , -1) ;
        return solve(n , dp) ;
    }
};    
 

//dp
int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1,0);
        dp[0]=1;  // null subset
        dp[1]=1;  // 1 way possible
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=(1*dp[i-1] + (i-1)*dp[i-2];
        }
        return dp[n];
    }
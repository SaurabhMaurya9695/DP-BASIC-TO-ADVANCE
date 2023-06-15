// https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    #define ll long long
    ll dp[100005] ;
    ll solve(ll idx , ll n , vector<vector<int>>& arr )
    {
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx] ;
        }
        ll solved = arr[idx][0] + solve(idx + 1 + arr[idx][1] , n , arr);
        ll skip  = solve(idx + 1 , n , arr);
        
        return dp[idx]  =  max(solved , skip);
    }
    long long mostPoints(vector<vector<int>>& arr) {
        ll n = arr.size() ;
        memset(dp , -1 , sizeof(dp)) ;
        return solve(0 , n , arr) ;
    }
};
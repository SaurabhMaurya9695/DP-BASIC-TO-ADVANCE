// we have to paint our house with k colors  such that no two adjecent are same ;
class Solution {
public:
    #define ll long long 
    int solve(ll n , vector<vector<int>> arr , ll idx , ll prev , ll k , vector<vector<int>> dp)
    {
        if(idx == n) return 0 ;

        if(prev >=0  && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        int ans = INT_MAX;
        for(int i = 0 ; i< k ; i++){
            ans = min(ans , ((prev == i) ? INT_MAX : solve(n , arr , idx + 1 , i , k , dp) + arr[idx][i]));
        }

        if(prev == -1) return ans;
        return dp[idx][prev] = ans ;
    }

    int minCostII(vector<vector<int>> &costs) {
        int k = costs[0].size();
        int n = costs.size();
        vector<vector<int>> dp(n + 1 , vector<int>( k , -1));
        // cout << solve(n , arr , 0 , 0 , 0 , dp)  << endl;
        return solve(n , costs , 0 , -1 , k , dp);
    }
};
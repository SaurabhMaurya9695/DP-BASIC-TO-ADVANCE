//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  #define ll long long 
  ll solve(int nums[] , ll target  ,ll lastcoin ,vector<vector<ll>> &dp , int N){
        
        if(target < 0 ) return 0;
        if(target == 0){
            return 1;
        }
        
        if(dp[target][lastcoin] != -1){
            return dp[target][lastcoin] ;
        }
        ll ans = 0;
        for(ll i = lastcoin; i < N ; i ++){
            ans += solve(nums , target - nums[i] , i , dp , N);

        }
        return dp[target][lastcoin] = ans ;
    }
    long long int count(int coins[], int N, int amount) {
        vector<vector<ll>>dp (amount + 1, vector<ll>(N , -1));
        return solve(coins , amount ,   0 , dp , N) ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
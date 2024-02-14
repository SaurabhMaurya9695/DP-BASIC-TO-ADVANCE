class Solution {
public:
    
    #define ll long long 
    
    long long  dp[501];
    
    /*
    int solve (vector<int>& arr, int k , int idx){
        if (idx == arr.size()){
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];

        int maxE = INT_MIN, sum = INT_MIN, n = arr.size();
        for(int i = idx; i < min(n,idx+k); i++){
            maxE = max(maxE, arr[i]);
            sum = max(sum, maxE*(i-idx+1) + solve(arr,k,i+1));
        }
        return dp[idx] = sum;
        
        
    }
    */
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // memset(dp , -1 ,sizeof(dp)) ;
        // int n = arr.size() ;
        // return (ll)solve(arr  , k , 0);
        
         int n = arr.size();
        //base case n+1 is 0 in dp!
        vector<int>dp(n+1,0);

        for(int idx = n-1; idx >= 0; idx--){
            int maxE = -1;
            for(int i = idx; i < min(n,idx+k); i++){
                maxE = max(maxE, arr[i]);
                dp[idx] = max(dp[idx], maxE*(i-idx+1) + dp[i+1]);
            }
        }
        return dp[0];
    }
};
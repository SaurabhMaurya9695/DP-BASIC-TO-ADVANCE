class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& arr, int n, int idx, int d) {
        
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if (d == 1) {
            return *max_element(begin(arr) + idx, end(arr));
        }
        
        if (dp[idx][d] != -1)
            return dp[idx][d];
    
        int Max = INT_MIN;
        int result = INT_MAX;
        
        // Try one by one with all possibilities
        /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            and so on
            
            Then find the optimal one among all the results
        */
        for (int i = idx; i <= n - d; i++) {
            Max = max(Max, arr[i]);
            result = min(result, Max + solve(arr, n, i + 1, d - 1));
        }
        
        return dp[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        
        if (n < d)
            return -1;

        memset(dp, -1, sizeof(dp));
        
        return solve(arr, n, 0, d);
    }
};
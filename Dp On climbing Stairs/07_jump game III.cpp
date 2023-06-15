class Solution {
public:
    bool solve(int idx, int n, vector<int>& arr, vector<bool>& dp) {
        if (idx < 0 || idx >= n || dp[idx]) return false; // base case's
        if (arr[idx] == 0) return true; // if we reach at arr[idx] == 0 
        dp[idx] = true;
        bool left = solve(idx + arr[idx], n, arr, dp) ; // left call 
        bool right = solve(idx - arr[idx], n, arr, dp);  // right call
        return  (left || right) ;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> dp(n, 0);
        return solve(start, n, arr, dp);
    }
};
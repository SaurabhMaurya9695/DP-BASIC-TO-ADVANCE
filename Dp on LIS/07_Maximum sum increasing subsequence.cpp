// https://leetcode.com/problems/best-team-with-no-conflicts/discuss/899452/C%2B%2B-DP-with-comments-Find-the-maximum-sum-of-increasing-subsequence

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int sum = 0 ;
	    vector<int>dp (n + 1) ;
	    int ans = 0;
	    for(int i = 0 ; i < n ; i++){
	        dp[i] = arr[i] ;
	        for(int j = 0 ; j < i ; j++){
	            if(arr[i] > arr[j] ){
	                dp[i] = max(dp[i] , dp[j] + arr[i]) ; 
	            }
	        }
	        ans = max(ans , dp[i]) ;
	    }
	    
	    return ans ;
	}  
};


class Solution{
		

	public:
	int solve(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp) {
	    if(ind == n) {
	        return 0;
	    }
	    
	    if(dp[ind][prev_ind+1] != -1) {
	       return dp[ind][prev_ind+1]; 
	    }
	    
	    int not_taken = solve(ind+1, prev_ind, arr, n, dp);
	    int taken = INT_MIN;
	    
	    if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
	        taken = arr[ind] + solve(ind+1, ind, arr, n, dp);
	    }
	    
	    return dp[ind][prev_ind+1] = max(taken, not_taken);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n, vector<int>(n+1, -1));
	    return solve(0, -1, arr, n, dp);
	}  
};
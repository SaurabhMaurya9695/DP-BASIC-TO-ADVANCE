bool solve1(int i , int target , vector<int> arr ,vector<vector<int>> &dp , int n )
	{
	    if (target < 0)
            return 0;
        if (i == n) {
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];

        bool no = solve1(i + 1, target, arr, dp , n);
        bool yes = solve1(i + 1, target - arr[i], arr, dp , n);
        return dp[i][target] = (no | yes) ; // just change here
	}

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size() ;
    vector<vector<int>>dp(n + 1 , vector<int>(B + 1 , -1)) ;
    return solve1(0 , B , A , dp , n);
}


//tabulation



int Solution::solve(vector<int> &arr, int B)
{
    int n = arr.size() ;
    int target = B;
    vector<vector<int>>dp(n + 1, vector<int>(target + 1 , 0)) ;
    dp[0][0] = 1 ;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            int no = dp[i - 1][j]; // No Call
            int yes = (j >= arr[i - 1]) ? dp[i - 1][j - arr[i - 1]] : 0;

            dp[i][j] = (no | yes);
        }
    }

    return dp[n][target];
}

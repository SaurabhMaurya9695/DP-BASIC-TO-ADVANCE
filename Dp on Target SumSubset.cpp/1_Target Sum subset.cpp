class Solution{

	public:
    // time -> O(N * target);
    // space -> O(N * target);
	const int mod = 1e7 ;
	int solve(int i , int target , int arr[] ,vector<vector<int>> &dp , int n )
	{
        // you can't write target == 0 , we have to go till last idx , our arr can contains zero
        // {2,4} and {2,4,0} same 
	    if (target < 0)
            return 0;
        if (i == n) {
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];

        int no = solve(i + 1, target, arr, dp , n);
        int yes = solve(i + 1, target - arr[i], arr, dp , n);
        return dp[i][target] = (no + yes) % 1000000007;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp (n + 1 , vector<int> (sum + 1 , -1)) ;
        return solve(0, sum, arr, dp , n) ;
	}
	  
};


//tabulation -> O(n * target)
class Solution{

	public:
	#define mod 1000000007
	int perfectSum(int arr[], int n, int target)
	{
	    vector<vector<int>>dp(n + 1, vector<int>(target + 1 , 0)) ;
	    dp[0][0] = 1 ;
	    for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int no = dp[i - 1][j]; // No Call
                int yes = (j >= arr[i - 1]) ? dp[i - 1][j - arr[i - 1]] : 0;

                dp[i][j] = (no + yes) % 1000000007;
            }
        }

        return dp[n][target];
	}
	  
};


//space optimization
class Solution{

	public:
	#define mod 1000000007
	int perfectSum(int arr[], int n, int target)
	{
	    vector<int> dp(target + 1);
	    dp[0] = 1; // Empty Subset to form 0 Target

        for (int i = 1; i <= n; i++) {
            vector<int>newdp(target + 1); // making ans from previous row ;
            for (int j = 0; j <= target; j++) {
                int no = dp[j]; // No Call
                int yes = (j >= arr[i - 1]) ? dp[j - arr[i - 1]] : 0;

                newdp[j] = (no + yes) % 1000000007;
            }

            dp = newdp; // update 
        }

        return dp[target];
	}
	  
};
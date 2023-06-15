class Solution {
public:
    
    int dp[201][20001] ;
    int solve(int i , vector<int>& arr , int target , int n )
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

        int no = solve(i + 1, arr , target, n);
        int yes = solve(i + 1, arr , target - arr[i], n);
        return dp[i][target] = (no | yes) ;
	}
    
    bool canPartition(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp)) ;
        int sum = accumulate(nums.begin() , nums.end() ,0ll) ;
        if(sum % 2 != 0){
            return false;
        }
        else{
            int target = sum / 2;
            int n = nums.size() ;
            return solve(0 , nums , target , n) ;
        }
    }
};


// tabulation
// same as previous tabulation

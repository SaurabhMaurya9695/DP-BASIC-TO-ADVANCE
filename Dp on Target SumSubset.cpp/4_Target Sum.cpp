// same code as before
class Solution {
public:
    int dp[21][2005] ;
    int solve(int idx , vector<int>& arr , int target , int n )
	{
	    if (target < 0)
            return 0;
        if (idx == n) {
            if (target == 0)
                return 1;
            return 0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target] ;

        int no = solve(idx + 1, arr , target, n );
        int yes = solve(idx + 1, arr , target - arr[idx], n );
        return dp[idx][target ] = (no + yes) ;
	}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0 ;
        for(int x : nums)  totalsum += x;
        //we are assuming that we are dividing a subset into the two set where s1-s2  = target
        //positive element in one set and -ive element in another set ;
        
        if(target  > totalsum) return 0;
        if((totalsum - target ) % 2 == 1)
        {
            return 0;
        }
        int targetx = (totalsum - target ) / 2 ;
        memset(dp ,-1, sizeof(dp)) ;
        return solve(0 , nums  , targetx  ,  nums.size() ) ;
    }
};

// or you can do this question by giving choices at every stage ;
class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i,vector<int> &nums,int target,int n){
        if(i==n and target==0) return 1;
        if(i==n) return 0;
        if(dp[i][target+1000]!=-1) return dp[i][target+1000];
        int a=0;
        int left =helper(i+1,nums,target-nums[i],n);
        int right = helper(i+1,nums,target+nums[i],n);
        return dp[i][target+1000]= left + right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),s=0;
        dp.resize(n+1,vector<int>(target+2001,-1));
        return helper(0,nums,target,n);
    }
};

// tabulation is same as before 
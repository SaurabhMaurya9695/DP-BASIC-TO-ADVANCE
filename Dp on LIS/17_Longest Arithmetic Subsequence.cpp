class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ;
        // here we can see there is two states first is idx and other is differnce
        int ans=1;
        vector<vector<int>>  dp(n,vector<int>(1005,1));
        
        for(int i = 1 ; i < n; i ++) {
            for(int j = 0 ; j < i ; j ++){
                int d = nums[i] - nums[j] + 500 ;
                dp[i][d] = 1+ dp[j][d] ;
                ans=max(ans,  dp[i][d]);
            }
        }
        
        return ans;
        
    }
};
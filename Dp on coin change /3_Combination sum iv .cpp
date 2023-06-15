class Solution {
public:
    
    // this is permutation varience
    //time -> O(amount * coins) ;
    //space -> O(amount);
    int solve(vector<int> nums , int target  , vector<int> &dp){
        
        if(target < 0 ) return 0;
        if(target == 0){
            return 1;
        }
        
        if(dp[target] != -1){
            return dp[target] ;
        }
        int ans = 0;
        for(int i = 0; i < nums.size() ; i ++){
            if(target - nums[i] >= 0){
                ans += solve(nums , target - nums[i] , dp);
            }
        }
        return dp[target] = ans ;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int > dp(1001 , -1) ;
        return solve(nums , target , dp) ;
    }
};



//tabulation
class Solution {
public:
    int combinationSum4(vector<int>& nums, int amount) {
        vector<unsigned int> dp(amount+1, 0);
        dp[0] = 1; // Ways to reach dest when src = dest is 1. (Empty String)
        
        for(int i=1; i<= amount; i++){
            for(int coin: nums){
                if(i >= coin){
                    dp[i] += dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};
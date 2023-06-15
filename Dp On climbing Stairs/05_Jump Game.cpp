class Solution {
public:    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, false);
        dp[n-1] = true; // smaller problem 
        // smaller problem to larger problem go 
        for(int i = n-2; i >= 0; i--){
            for(int j=1; j<=nums[i] and i+j < n; j++){
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
``````````````````````````````````````````````````````````````````````````````````````````````````
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
       int reach = 0 ; // maximum reach 
        // think greedy
        for(int i = 0 ; i < nums.size() ;i ++){
            if(i > reach){ 
                return false;
            }
            
            if(i + nums[i] >= reach){
                reach = i + nums[i] ;
            }
            
            
        }
        
        return true;
    }
};
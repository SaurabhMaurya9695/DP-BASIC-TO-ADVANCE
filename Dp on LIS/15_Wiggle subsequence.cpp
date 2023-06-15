class Solution {
public:

    // time -> O(N) , space -> O(1);
    int wiggleMaxLength(vector<int>& nums) {
        // if the last diff is positive then we can't add the positive again
        // we need to add -ive this time , and if last diff is 
        // -ive then we have to add +ive .
        
        int n = nums.size() ;
        if(n < 2) {
            return n ;
        }
        
        int prev = nums[1] - nums[0] ; // if it is +ive then search for -ive or vice versa
        int cnt = (prev != 0 ? 2 : 1) ;// minimum 2 length subsequence should be present ;
        for(int i = 2 ; i < n ; i++){
            int diff = nums[i] - nums[i-1] ;
            if(diff > 0 && prev <= 0){
                cnt ++ ;
                prev = diff;
            }
            
            if(diff < 0 && prev >= 0){
                cnt ++ ;
                prev = diff;
            }
            
            // if both are same , prev and diff then just skip that element
            if((prev > 0 && diff > 0 ) or (prev < 0 && diff < 0)){
                continue;
            }
            
        }
        return cnt  ;
    }
};




// Memorization 
class Solution {
public:
    
    // time -> O(N) , space -> O(N * 2);
    int dp[1005][2];
    int helper(vector<int>& nums, int i, int n, bool flag)
    {
        // if one element is present
        if(i == n - 1){
            return 1;
        }
        
        // if already calculated
        if(dp[i][flag] != -1)
            return dp[i][flag];
        
        int ans = 0;
        
        if(flag)  // we need positive diff.
        {
            if(nums[i + 1] > nums[i])  // include
            {
                ans = max(ans, 1 + helper(nums, i + 1, n, false));
            }
            else  // exclude
            {
                ans = max(ans, helper(nums, i + 1, n, true));
            }
        }
        else   // we need negative diff
        {
            if(nums[i + 1] < nums[i])   // include
            {
                ans = max(ans, 1 + helper(nums, i + 1, n, true));
            }
            else  // exclude
            {
                ans = max(ans, helper(nums, i + 1, n, false));
            }
        }
        
        // store the ans in dp   
        return dp[i][flag] = ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = INT_MIN;
        
        memset(dp, -1, sizeof(dp));
        // by taking positive as first diff.
        
        ans = max(ans, helper(nums, 0, n, true));
        
        memset(dp, -1, sizeof(dp));
        // by taking negative as first diff.
        
        ans = max(ans, helper(nums, 0, n, false));
        return ans;
    }
};
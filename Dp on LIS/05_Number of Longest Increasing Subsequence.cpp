class Solution {
public:

    // time complexity - > O(N * N) ;
    // space -> O(N + N) => O(N) ;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n + 1, 1);
        vector<int> cnt(n + 1, 1);
        
        int maxLIS = 0;
        
        for(int i = 0 ; i< n ; i ++){
            // as from the previous value whether the previous value is 
            // lesser than curr val then we can add  in ans ;
            for(int j = 0 ;j < i; j ++){
                if(nums[i] > nums[j] && dp[j] + 1 >= dp[i]){ // check for incresing && if length is increasing 
                   if(dp[j] + 1 > dp[i] ){ // rejecting the smaller subsequence ,
                       // here if we can't add the smaller subsequences ; these one's {1} ,{2} 
                       cnt[i] = 0;
                   } 
                   dp[i] = max(dp[i] , dp[j] + 1) ; // update with max length ;
                   cnt[i] += cnt[j]; // take the previous subsequence after removing the smaller subsequences 
                }
            }
            maxLIS = max(maxLIS , dp[i]) ;
        }
        
        int ans = 0 ;
        for(int i = 0 ; i< n; i ++)
        {
            if(dp[i] == maxLIS){
                ans += cnt[i] ; // add  all the maximum length subsequences in ans 
            }
        }
        
        return ans ;
    }
};
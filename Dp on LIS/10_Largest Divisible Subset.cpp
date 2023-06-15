class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // we have to dp sorting first .. this is a vartion of LIS
        // we can give multiple ans , so ordering not matter ;
        // {1 2 4 8} , {8,2,4,1} , {2,4,1,8} -> these all permutations valid  , so first sort the 
        // use LIS logic with condition ar[i] % arr[j] == 0 , j > i ;
        
        // 3 4 8 16
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ; // sorting is neccessary here
        vector<int> dp(n , 1) ; // minimum length of size 1 LIS is present for every idx ;
        
        vector<int> prev(n ,-1) ; // till then we din't add in front of anyone ;
        
        int maxLIS = 0 , maxLISidx = 0;
        for(int i = 1 ; i < n ; i ++){
            for(int j = i - 1 ; j>= 0 ; j --){ // asking kiske aagy lag skta hu
                if(nums[i] % nums[j] == 0 && dp[j] + 1> dp[i]) // check for condition 
                {
                    prev[i] = j ; // we add this element which follows the condition 
                    dp[i] =  dp[j] + 1;
                }
            }
            
            // find the max length and its idx 
            if(dp[i]  > maxLIS ){
                maxLIS = dp[i] ;
                maxLISidx = i ;
            }
        }
        
        // cout << maxLISidx << " "; // we have our max lis which is ending at this idx ;
        
        vector<int> ans;
        while(maxLISidx != -1){
            ans.push_back(nums[maxLISidx]) ;
            maxLISidx = prev[maxLISidx]; 
        }
        return ans ;
        
        
        
        
    }
};
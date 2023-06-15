// https://leetcode.com/problems/maximum-subarray/

// brute force 
// generate all the subarray and take max of all sum of subaarrays

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;
        for(int i = 0;  i< n ; i ++){
            int sum = 0 ;
            for(int j = i; j < n ; j ++){
                 sum = sum + nums[j] ;
                 ans = max(ans , sum);
            }
        }
        
        return ans ;
    }
};



// optimized -> O(N);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;
        int curr_sum = nums[0] ;
        int overall_sum = nums[0] ;
        
        //starting form one 
        for(int i = 1 ;i < n ;i++){
            if(curr_sum >= 0){
                curr_sum += nums[i];
            }
            else{
                curr_sum = nums[i];
            }
            if(curr_sum > overall_sum){
                overall_sum = curr_sum;
            }
        }
        
        return overall_sum;
    }
};
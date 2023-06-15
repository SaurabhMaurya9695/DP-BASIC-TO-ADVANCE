class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n  = nums.size() ;
        vector<int> pref(n , 1) ; // minimum length of incresing subsequence is 1;

        //find max LIS from front
        // time to find LIS -> o(n * n);
        for(int i = 0 ; i< n ; i++){
            for(int j =0 ; j < i ; j ++){
                if(nums[i] > nums[j]){
                    pref[i] = max(pref[i] , pref[j] + 1) ;
                }
            }
        }
        
        reverse(nums.begin(), nums.end()) ;
        vector<int> suff(n , 1) ; // minimum length of incresing subsequence is 1;
        //find max LIS from front in suff means from back
        // time to find LIS -> o(n * n);
        for(int i = 0 ; i< n ; i++){
            for(int j =0 ; j < i ; j ++){
                if(nums[i] > nums[j]){
                    suff[i] = max(suff[i] , suff[j] + 1) ;
                }
            }
        }
        
        reverse(suff.begin(), suff.end());
        int ans = INT_MIN ;
        for(int i = 0 ; i < n ; i++){
            if(pref[i] > 1 && suff[i] > 1){
                ans = max(ans , pref[i] + suff[i] - 1);
            }
        }
        return n - ans ;
    }
};
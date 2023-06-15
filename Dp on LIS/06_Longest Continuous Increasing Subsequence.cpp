// using basic loop iteration 
class Solution {
public:
    // time -> O(N);
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 , length = 0 ;
        for(int i = 0;  i< n  ; i++){
            if(i > 0 && nums[i] > nums[i - 1 ] ){
                length ++ ;
            }
            else{
                ans = max(ans , length) ;
                length = 1;
            }
        }
        ans = max(ans , length) ;
        return ans ;
    }
};
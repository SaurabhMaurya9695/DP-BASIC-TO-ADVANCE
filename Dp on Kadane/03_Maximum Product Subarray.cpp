// Method 1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        // our ans lies in between in left subarray or in right subarray ;
        
        int ans = INT_MIN ;
        // for left subarray 
        int left_pro = 1 ;
        for(int i = 0 ; i < n ; i ++){
            left_pro *= nums[i];
            ans = max(ans , left_pro);
            if(left_pro == 0){ // this means nums[i] == 0
                left_pro = 1;
            }
        }
        
        // for right subarray 
        int right_pro = 1 ;
        for(int i = n - 1 ; i >= 0 ; i --){
            right_pro *= nums[i];
            ans = max(ans , right_pro); 
            if(right_pro == 0){ // this means nums[i] == 0
                right_pro = 1;
            }
        }
        
        return ans ;
    }
};

//Method 2

class Solution {
public:
        // invert all values or we can do this by without inverting also 
        // if we inverted then find max_sum_subarray or
        // else find min_sum_subarray in order to find ans ;
        
        // inverted ? -1 * (total - max_sum_subarray)  : (total - min_sum_subarray)
        
        // if all are -ive ;

        // below code is without inverting
        
    int maxSubarraySumCircular(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = A.size();
        int max_straight_SUM = INT_MIN;
        int min_straight_SUM = INT_MAX;
        int array_SUM = 0;
        
        int temp_maxSUM = 0;
        int temp_minSUM = 0;
        
        for(int i=0;i<n;++i)
        {
            array_SUM +=A[i];
            
            temp_maxSUM += A[i];
            max_straight_SUM = max_straight_SUM<temp_maxSUM? temp_maxSUM:max_straight_SUM;
            temp_maxSUM = temp_maxSUM<0?0:temp_maxSUM;
            
            temp_minSUM += A[i];
            min_straight_SUM = min_straight_SUM>temp_minSUM? temp_minSUM:min_straight_SUM;
            temp_minSUM = temp_minSUM>0?0:temp_minSUM;
        }
        if(array_SUM==min_straight_SUM)
            return max_straight_SUM;
        return max(max_straight_SUM,(array_SUM-min_straight_SUM));
    }
};


// method 2
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // we can use the kadane algorithm first hand 
        //but we can see that its a circular array so subtracting 
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int curm = 0;
        int curmi = 0;
        int i = 0 ;
        int sum = accumulate(nums.begin(),nums.end(),0);
        while (i<nums.size()){
            curm+=nums[i];
            curmi+=nums[i];
            maxi = max(curm,maxi);
            mini= min(curmi,mini);
            if(curm<0){
                curm=0;
            }
            if (curmi>0)
            curmi=0;
            i++;
        }
        int minans = sum-mini;
        if (sum == mini)return maxi;
        else 
        return minans>maxi ? minans : maxi;
    }
};


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n  = nums.size();
        int curr = 0;
        int maxm = INT_MIN, sum = 0;;

        for(int i=0; i<n;i++){
            curr+=nums[i];
            maxm = max(maxm, curr);
            sum+=nums[i];
            if(curr <0){
                curr = 0;
            }
        }
        
        int maxm1 = 0;
        curr =0;
        for(int i=1; i<n-1; i++){
           curr+=nums[i];
            maxm1 = min(curr, maxm1);
            
            if(curr>0){
                curr = 0;
            }
           
        }
        
        return max(maxm, sum-maxm1);
    }
};
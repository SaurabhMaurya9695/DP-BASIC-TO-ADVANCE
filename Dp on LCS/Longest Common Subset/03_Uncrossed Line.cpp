
//observe this is nothing but just variation of LCS

class Solution {
public:
    int dp[501][501];
    int solve(int i , int j ,vector<int> &nums1 , vector<int> & nums2 ){
        if(i == nums1.size() || j == nums2.size()){
            return 0 ;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int x = nums1[i];
        int y = nums2[j];
        
        if(x == y){
            return 1 + solve(i + 1,  j + 1 ,nums1 , nums2);
        }
        else{
            int x = solve(i , j + 1, nums1 , nums2);
            int y = solve(i + 1 , j , nums1 , nums2);
            
            return  dp[i][j] = max(x , y);
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       // this question is nothing but variation of LCS
        memset(dp , -1, sizeof(dp));
        return solve(0 , 0 , nums1 , nums2) ;
    }
};
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/1595288/Java-%2B-Dynamic-Programming-%2B-O(n2)-and-O(nlogn)-%2B-With-explanation

class Solution {
public:

    // time -> O(N * N) => O(idx * prev);
    // space -> O(N * N) => O(curr * prev); 
    int dp[2501][2501]; 
    int solve(int idx , int prev_idx , vector<int>&nums)
    {
        if(idx == nums.size() ) return 0;
        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1]; //prev_idx + 1] to store previous idx also 
        
        int yes = (prev_idx == -1 || nums[prev_idx] < nums[idx])
                   ? solve(idx + 1, idx, nums) + 1 : 0;
            
        int no = solve(idx + 1, prev_idx, nums);
        
        return dp[idx][prev_idx +1 ] = max(yes, no);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp ,-1, sizeof(dp)) ;
        return solve(0 , -1 , nums);
    }
};

// method 2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int l=dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]){
                    l=max(l, 1+dp[i+1][i+1]);
                }
                dp[i][j+1]=l;
            }
        }
        return dp[0][0];
    }
};

// tabulation 1

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
       int n = arr.size() ;
       vector<int> dp (n + 1 , 1);
        // 1 length smallest LIS should be possible for each index ;
        for(int i = 0 ; i < n ; i ++) // for every idx;
        {
            for(int j = 0 ;j < i ; j ++){ // ask from the previous idx value whether i can be added or not
            // if added then increase dp[i] = dp[j] + 1 .. adding our value itself 
                if(arr[i] > arr[j] ){ // current idx should be > then the previous idx 
                    dp[i] = max(dp[i] , dp[j] + 1) ; // take the max length from before
                }
            }
        }
        
        
        return *max_element(dp.begin() , dp.end()) ;
    }
};
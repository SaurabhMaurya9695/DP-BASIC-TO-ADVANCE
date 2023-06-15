class Solution {
public:
    
    // time complexity - >o (N * JUmps) ;
    // space -> o(n)
    long long solve(vector<int> &cell , int idx , vector<long long>&dp)
    {
        if(idx == cell.size() -1){
            return 0;
        
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        long long  ans = INT_MAX;
        // make all the possible jump from the current cell ;
        for(int jump = 1; jump <= cell[idx] ; jump++){
            if(idx + jump < cell.size() )
                // take the mini coming from all the path and add + 1 for yourself 
                ans = min(ans , solve(cell , idx + jump , dp) + 1ll) ;
        }
        
        dp[idx] = ans ;
        return ans ;
    }
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        vector<long long > dp (n + 1 , -1);
        return (int)solve(nums , 0 , dp) ;
    }
};


// tabulation

class Solution {
public:
    #define ll long long 
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(n,0); // minimum number of steps to reach end from ith position
        dp[n-1]=0; // smaller problem 
        for(int i=n-2;i>=0;i--){ // smaller to larger problem we go
            int m = 10000; // max ans be 
            for(int j=1;j<=nums[i] && j+i<n;j++){
                m = min(dp[j+i],m);
            }
            dp[i]=m+1; // +1 for our jump also
        }
        return dp[0];

    }
};
//leetcode ->https://leetcode.com/discuss/interview-question/1707239/Rod-Cutting-DP
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution{
  public:
  
    int dp[1001];
    int solve(int price[] , int n)
    {
        if(n == 0){
            return 0 ;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0 ;
        for(int cut = 1 ; cut <= n ;cut ++){ // make all the possible cuts 
            ans = max(ans , price[cut - 1] + solve(price , n - cut));
        }
        
        return dp[n] = ans ;
    }
    int cutRod(int price[], int n) {
        //code here
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(price , n );
    }
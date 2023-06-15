class Solution {
public:
    
    // create a length of 2 , 3 , 4 ....... n
    // and try to put zero and one in each placed zero or one number of times ;
    

    #define mod 1000000007
    
    int dp[100005];
    int solve(int n , int zero , int one ){
        if(n == 0){
            return 1;
        }
        
        if(n < 0 ){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        int Zero_Placed =  solve(n - zero , zero , one )  % mod;
        int One_Placed  =  solve(n - one , zero , one ) % mod ;
        
        return dp[n] = (Zero_Placed + One_Placed) % mod ;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        memset(dp ,-1, sizeof(dp));
        int ans = 0 ;
        for(int i = low ; i <= high ;  i++){
            ans = ( ans + solve(i , zero , one) ) % mod;
        }

        return ans % mod ;
    }
};
// https://leetcode.com/problems/perfect-squares/

// Memorization

class Solution {
public:
    int dp[10001] ;
    int solve(int n){
        
        if(n < 0){
            return INT_MAX ;
        }
        
        if(n == 0){
            return 0;
        }
            
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        int ans = n ;
        // give all choices;
        for(int i = 1;  i * i <= n ;  i++){
            ans = min(ans ,  1 + solve(n - i*i)) ;
        }

        return  dp[n] = ans  ;
    }
    
    int numSquares(int n) {
        memset(dp , -1 , sizeof(dp)) ;
        return solve(n);
    }
};


//Tabultaion
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, 0) ;
        for(int i = 1 ; i <= n ; i ++) // filling dp table;
        {
            dp[i] = i;  // max to max ans is i ;
            for(int j =1; j * j <= i ; j ++){
                dp[i] = min(dp[i] , dp[i -j * j] + 1) ;
            }
        }
        
        return dp[n] ;
    }
};
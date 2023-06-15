// https://leetcode.com/discuss/general-discussion/1278305/all-about-matrix-chain-multiplication-easy

class Solution{
public:
    
    int dp[501][501] ;
    int solve(int i , int j  , int arr[] ){
        
        // base case 
        if(i == j){
            return 0 ;
        }
        if(dp[i][j] != -1 ){
            return dp[i][j];
        }
        
        int ans = INT_MAX ;
        
        // make all possible cuts 
        for(int cut = i ; cut < j  ; cut ++){
            int steps = arr[i-1] * arr[cut] * arr[j] + solve( i , cut, arr) + solve(cut + 1, j, arr) ;
            ans = min(ans , steps );
        }
        
        return dp[i][j] = ans ;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp ,-1 , sizeof(dp)) ;
        return  solve( 1 ,  N - 1, arr) ;
    }
}


// tabulation 
class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[501][501] ;
        for(int i = 0 ; i < N; i ++){
            dp[i][i] = 0;
        }
        for(int i = N - 1; i>= 1; i --){
            for(int j = i + 1 ; j < N ; j ++){
                int ans = INT_MAX ;
                // make all possible cuts 
                for(int cut = i ; cut < j  ; cut ++){
                    int steps = arr[i-1] * arr[cut] * arr[j] + dp[i][cut] +  dp[cut + 1][j] ;
                    ans = min(ans , steps );
                }
                
                 dp[i][j] = ans ;
            }
        }
        
        return dp[1][N-1] ;
    }
};
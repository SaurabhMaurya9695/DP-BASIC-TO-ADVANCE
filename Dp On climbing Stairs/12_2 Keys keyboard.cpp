class Solution {
public:
    #define ll long long 
    ll dp[1005][2005];
    
    ll solve(ll screenChar , ll bufferChar , ll n  ){
        
        if(screenChar > n || bufferChar > n) return INT_MAX;
        if(screenChar == n) return 0;
        
        if(dp[screenChar][bufferChar] != -1){
            return dp[screenChar][bufferChar];
        }
        
        //copyPaste call ;
        ll copyPaste = 2ll + solve( 2ll * screenChar  , screenChar , n);
        //ignoring the repeted calls in copyPaste call ;
        ll paste = 1ll + solve(screenChar + bufferChar , bufferChar , n) ;
        
        dp[screenChar][bufferChar] = min(copyPaste , paste) ;
        return dp[screenChar][bufferChar] ;
    }
    
    int minSteps(int n) {
        if(n == 1) return 0;
        for(int i = 0 ; i<= n ; i ++){
            for(int j = 0 ; j <= n ; j++){
                dp[i][j] = -1;
            }
        }
        return 1ll + solve(1ll , 1ll , n ) ;
    }
};
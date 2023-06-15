
// in this we can do at most k transaction .. so completed our transaction when wen perform 
// sell there our transaction completed ..

class Solution {
public:
    int dp[10001][2][101] ;
    int solve(vector<int>& cost , int buy , int idx , int cap){
        
        if(cap == 0){ // at any moment our capacity become zero then we can't do next transaction
            return 0;
        }
        if(idx == cost.size()){
            return 0 ; // if we reached at last idx then our profit will be zero 
        }
        
        if(dp[idx][buy][cap] != -1){
            return dp[idx][buy][cap];
        }
        int ans = 0 ;
        if(buy == 1){ 
            int take =  -cost[idx] + solve(cost , 0 , idx + 1 , cap ) ;
            int notTake = 0 + solve(cost , 1 , idx + 1 , cap ) ; 
            ans = max(take , notTake) ;
        }
        else if(buy == 0) // buy == 0 means previous we buy somewhere we have to sell now ;
        {
            int take2 =  cost[idx] + solve(cost , 1 , idx + 1 , cap - 1) ;
            int notTake2 = 0 + solve(cost , 0 , idx + 1 , cap ) ;
            ans = max(take2 , notTake2) ;
        }
        
        return dp[idx][buy][cap] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
         memset(dp , -1 , sizeof(dp)) ;
        return solve(prices , 1 , 0 , k) ;
    }
};
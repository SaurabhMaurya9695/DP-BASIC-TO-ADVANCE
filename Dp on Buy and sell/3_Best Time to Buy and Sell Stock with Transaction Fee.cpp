class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>& cost , int buy , int idx , int fee){
        
        
        if(idx == cost.size()){
            return 0 ; // if we reached at last idx then our profit will be zero 
        }
        
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        //every idx has two possiblility's ti buy or sell ;
        int ans = 0 ;
        if(buy == 1){ // we have given idx to buy
            int take =  -fee - cost[idx] + solve(cost , 0 , idx + 1 , fee) ; 
            int notTake = 0 + solve(cost , 1 , idx + 1 , fee) ; 
            ans = max(take , notTake) ;
        }
        else if(buy == 0) // buy == 0 means previous we buy somewhere we have to sell now ;
        {
            int take2 =   cost[idx] + solve(cost , 1 , idx + 1 , fee) ; 
            int notTake2 = 0 + solve(cost , 0 , idx + 1 , fee) ; 
            ans = max(take2 , notTake2) ;
        }
        
        return dp[idx][buy] = ans ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(prices , 1 , 0 , fee) ;
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy[ n + 1];
        int sell[n + 1] ;
        if(n == 1){
            return 0 ;
        }

        buy[0] = -prices[0];
        sell[0] = 0;
        int ans [n + 1];
 
        for (int i = 1; i < prices.size(); i++) {
            // Treat today as Buying Day
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            // Treat today as Selling Day
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
            ans[i] = max(buy[i] , sell[i]) ;
        }

        return ans[n - 1];
    }
};
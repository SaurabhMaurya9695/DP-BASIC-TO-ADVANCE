// we have to mentain a colldowm 
// we can directly buy after sell but can't start buying after sell
// you have to take a rest before agin buying .. this question is same as before 
// just change is that if you want to buy again then you need to ask for the dp[sell - 2] ;

class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& cost , int buy , int idx){
        
        
        if(idx >= cost.size()){
            return 0 ; // if we reached at last idx then our profit will be zero 
        }
        
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        //every idx has two possiblility's ti buy or sell ;
        int ans = 0 ;
        if(buy == 1){ // we have given idx to buy
            int take =  -cost[idx] + solve(cost , 0 , idx + 1) ; // selling on this index 
            int notTake = 0 + solve(cost , 1 , idx + 1) ; // we are buying on this day ;
            ans = max(take , notTake) ;
        }
        else if(buy == 0) // buy == 0 means previous we buy somewhere we have to sell now ;
        {
            int take2 =  cost[idx] + solve(cost , 1 , idx + 2) ; // on selling we adding our price and from next idx we are buying again ; 
            int notTake2 = 0 + solve(cost , 0 , idx + 1) ; // if we didn't sell on this day , so add profit as 0 and selling on next day ;
            ans = max(take2 , notTake2) ;
        }
        
        return dp[idx][buy] = ans ;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(prices , 1 , 0) ; 
    }
};


//tabulation -> O(N) and space ->O(N);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;

        int buy[prices.size()]  ;
        int sell[prices.size()]  ;

        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(-prices[0], -prices[1]); // Either buy 0th stock or 1st stock
        sell[1] = max(0, prices[1] - prices[0]); // Either do nothing or Buy 0 Sell 1

        //for maintain a cooldown you need to ask ans from i - 2;
        for (int i = 2; i < prices.size(); i++) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return sell[prices.size() - 1];
    }
};

//space optimization  -> O(N) and space ->O(1);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;

        int buy0 = -prices[0];
        int sell0 = 0;
        int buy1 = max(-prices[0], -prices[1]); // Either buy 0th stock or 1st stock
        int sell1 = max(0, prices[1] - prices[0]); // Either do nothing or Buy 0 Sell 1

        for (int i = 2; i < prices.size(); i++) {
            int newbuy = max(buy1, sell0 - prices[i]);
            int newsell = max(sell1, buy1 + prices[i]);
            buy0 = buy1;
            sell0 = sell1;
            buy1 = newbuy;
            sell1 = newsell;
        }

        return sell1;
    }
};
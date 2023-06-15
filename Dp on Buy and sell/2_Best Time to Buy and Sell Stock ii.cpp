https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/2423189/C%2B%2B-or-Intuition-or-Memoization-greater-Tabulation-greater-1D-array
//approach 1:
//time - O(N) , space ->O(N);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>stk;
        int ans = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            if(stk.size() > 0 && stk.top() < prices[i]){
                ans += prices[i] - stk.top();
                stk.pop();
            }
            stk.push(prices[i]) ;
        }
        return ans;
    }
};


//appraoch 2-> Time is same as above but space is reduced ;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyingDay = prices[0] ;
        int ans = 0;
        for(int i =  0; i < prices.size() ; i ++){
            if(buyingDay < prices[i]){
                ans += abs(prices[i] - buyingDay);
                
            }
            buyingDay = prices[i];
            
        }
        
        return ans ;
    }
};


//valley peak approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size() ;
        int valley = 0;
        int ans = 0 ;
        while (valley < n){
            int peak = valley ;
            while(peak + 1 < n && prices[peak + 1] >= prices[peak] ){
                peak ++ ;
            }
            
            ans += prices[peak] - prices[valley] ;
            valley = peak + 1;
        }
        
        return ans ;
    }
};

// using recursion O(2 ^ N) ;
// time complexity -> O( N * 2) ;
// space -> O(N * 2) + O(N);
class Solution {
public:
    
    int dp[30001][2];
    int solve(vector<int>& cost , int buy , int idx){
        
        
        if(idx == cost.size()){
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
            int take2 =  cost[idx] + solve(cost , 1 , idx + 1) ; // on selling we adding our price and from next idx we are buying again ; 
            int notTake2 = 0 + solve(cost , 0 , idx + 1) ; // if we didn't sell on this day , so add profit as 0 and selling on next day ;
            ans = max(take2 , notTake2) ;
        }
        
        return dp[idx][buy] = ans ;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(prices , 1 , 0) ; // we are making first idx as buying day 
    }
};

// tabulation
class Solution {
public:

    // time -> O(n) , space -> O(buy + sell + ans) => o(N) ;
    int maxProfit(vector<int>& prices) {
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
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
            ans[i] = max(buy[i] , sell[i]) ;
        }

        return ans[n - 1];
    }
};


//space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;

        for (int i = 1; i < prices.size(); i++) {

            // Treat today as Buying Day
            int newBuy = max(buy, sell - prices[i]);

            // Treat today as Selling Day
            int newSell = max(sell, buy + prices[i]);

            buy = newBuy;
            sell = newSell;
        }
        return sell;
    }
};
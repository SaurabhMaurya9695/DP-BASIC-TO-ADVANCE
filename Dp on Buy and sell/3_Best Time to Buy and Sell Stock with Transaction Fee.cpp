class Solution {
public:
    int dp[100006][2];
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1,sizeof(dp));
        return solve(prices, fee, 0, prices.size() , 0);
    }

    int solve(vector<int>& arr, int fee, int idx , int n , int buy) {

        if(idx >= n){
            return 0;
        }

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        int ans ;
        if(buy == 1){
            // means we already buyed and its time to sell or leave it
            int sell = (arr[idx] - fee) + solve(arr , fee , idx + 1 , n , 0); // now we are done with this transcation
            int skip = solve(arr , fee , idx + 1 , n , 1); 
            ans = max(sell , skip);
        }
        else{
            // means we have to buy now , either buy or skip
            int buy = -arr[idx] + solve(arr , fee , idx + 1 , n , 1); // started a transcation
            int skip = solve(arr , fee , idx + 1 , n , 0); 
            ans = max(buy , skip);
        }

        return dp[idx][buy] = ans ;
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

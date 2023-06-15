

//greedy 
// we have to  find valley and peak element , and just we need to find the 2 best valley and peak 
// buy this peakValley approach may be there is any peak present btwn who does't give us maximum;



// recursion + memorization ;
// we can complete our transaction when we done with BS ..
// time  -> O(N * 2 * 3) ;
// space -> O(N * 2 * 3) ;
class Solution {
public:
    int dp[100001][2][3];
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
            int take =  -cost[idx] + solve(cost , 0 , idx + 1 , cap) ;  //adding buying cost and next sell we are going to do ;
            int notTake = 0 + solve(cost , 1 , idx + 1 , cap ) ; // same choice we are given to the next  day with profit zero ;
            ans = max(take , notTake) ;
        }
        else if(buy == 0) // buy == 0 means previous we buy somewhere we have to sell now ;
        {
            int take2 =  cost[idx] + solve(cost , 1 , idx + 1 , cap - 1) ; // on selling we adding our price and from next idx we are buying again so here our one transaction done we reduce our cap -1 ;
            int notTake2 = 0 + solve(cost , 0 , idx + 1 , cap ) ; // if we didn't sell on this day , so add profit as 0 and selling on next day ;
            ans = max(take2 , notTake2) ;
        }
        
        return dp[idx][buy][cap] = ans;
    }
    int maxProfit(vector<int>& prices) {
        //there is three changing state. , so it is a 3d dp ;
        // idx , buy | Not Buy , capacity ;
        memset(dp , -1 , sizeof(dp)) ;
        return solve(prices , 1 , 0 , 2) ;
    }
};

//tabulation -> O(N * 2 * 3);
class Solution{
public:
	int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (2, vector<int> (3, 0))); 
        // initilized 3d DP dp[idx][buy][cap];
        // traverse in opposit direction 
        for(int idx = n - 1; idx >=0; idx --) 
        {
            for(int buy = 0; buy <= 1; buy ++)
            {
                for(int cap = 1; cap <= 2; cap ++) 
                {
                    // write the recurrence relation of memorized code ;
                    if(buy == 1)  //state of buying
                        dp[idx][buy][cap] = max(-prices[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap]);
                    else        //state of selling
                        dp[idx][buy][cap] = max(+prices[idx] + dp[idx+1][1][cap - 1], dp[idx + 1][0][cap]);
                }
            }
        }
        
        return dp[0][1][2];
    }
};


//space optimization technique
// wherever you see dp[i+1] replace with after and store in curr array
class Solution{
public:
	int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> after (2, vector<int> (3, 0));
        vector<vector<int>> curr (2, vector<int> (3, 0));
        // initilized 3d DP dp[idx][buy][cap];
        // traverse in opposit direction 
        for(int idx = n - 1; idx >=0; idx --) 
        {
            for(int buy = 0; buy <= 1; buy ++)
            {
                for(int cap = 1; cap <= 2; cap ++) 
                {
                    // write the recurrence relation of memorized code ;
                    if(buy == 1)  //state of buying
                        curr[buy][cap] = max(-prices[idx] + after[0][cap], after[1][cap]);
                    else        //state of selling
                        curr[buy][cap] = max(+prices[idx] + after[1][cap - 1], after[0][cap]);
                }
            }
            after = curr ;
        }
        
        return curr[1][2];
    }
};

// prefix and suffix dp ->
// time ->O(n) , space -> O(n) ;
class Solution {
public:
	int maxProfit(vector<int>& arr) {
	   int n = arr.size();

	   // pref[i] : maximum buying and selling profit till ith position
	   // suff[i] : maximum buying and selling profit from ith to n position
	   vector<int> pref(n) , suff(n);

	   int best_sell = arr[0];
	   for(int i=1;i<n;i++){
		   best_sell = min(best_sell , arr[i]);
		   pref[i] = max(pref[i-1] , arr[i] - best_sell); 
	   }

	   best_sell = arr[n-1];
	   for(int i=n-2;i>=0;i--){
		  best_sell = max(best_sell , arr[i]);
		  suff[i] = max(suff[i+1] , best_sell - arr[i]);
	   }

	   // find maximum of all i position 
	   int ans = 0;
	   for(int i=0;i<n;i++){
		   ans = max(ans , pref[i] + suff[i]);
	   }  
	   return ans;
	}
};
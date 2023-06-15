class Solution {
public:
    
    //recursion  + Memoriation
    // int solve(int sr , int dc , vector<int> cost , vector<int>&dp)
    // {
    //     if(sr == dc) return cost[sr];
    //     if(sr > dc) return  0;
    //     // lookup table ;
    //     if(dp[sr] != -1)
    //     {
    //         return dp[sr];
    //     }
    //     int left = solve(sr + 1 ,dc , cost , dp) + cost[sr];
    //     int right = solve(sr + 2 ,dc , cost , dp) + cost[sr];
    //     return dp[sr] = min(left , right) ;
    // }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size() ;
        
        // vector<int> dp(n +  1 , -1);
        // int zidx = solve(0 , n - 1 , cost , dp) ;
        // int fidx = solve( 1 , n - 1 , cost , dp);
         // return min(zidx , fidx);
        
                        // tabulation
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[n-1]=cost[n-1];
        for(int i=n-2;i>=0;i--)

        {
            dp[i]=min(cost[i]+dp[i+1],cost[i]+dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
    
};



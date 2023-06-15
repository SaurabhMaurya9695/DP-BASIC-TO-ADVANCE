//unbounded knapsack
// contrain
// 1 - you have to choose maximum loot
// 2 - capcity >= wt
// 3 - items can't be divided 
// 4 - infinite supply 
//https://leetcode.com/problems/coin-change/discuss/141064/unbounded-knapsack


// we are taking one wt many times until caapcity zero;
class Solution{
public:
    
    int dp[1001][1001] ;
    int solve(int n , int totalBagCapacity , int cost[] , int wt[]  ,int idx){
        
        if(idx == n) return 0 ;
        
        if(dp[idx][totalBagCapacity] != -1){
            return dp[idx][totalBagCapacity];
        }
        
        int ans = INT_MIN;
        for(int freq = 0 ; totalBagCapacity >= freq * wt[idx]  ; freq ++ ){
            int temp = solve(n ,totalBagCapacity - freq * wt[idx] , cost , wt , idx + 1 ) 
                        + freq * cost[idx] ;
            // if we taken in we have to include that many times in ans ;
            ans = max(ans , temp );
        }
        
        return dp[idx][totalBagCapacity] = ans ;
        
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp , -1 , sizeof(dp));
        return solve(N , W , val , wt , 0) ;
    }
};



// approach 2;
class Solution{
public:
    
    int dp[1001][1001];
    int solve(int N, int cap, int val[], int wt[] , int idx){
        if(idx == N){
            return 0;
        }
        
        if(cap == 0){
            return 0 ;
        }
        
        if(dp[idx][cap] != -1){
            return dp[idx][cap];
        }
        // every items has two possibilty 
        // to take in bage or not , if we take in bag then we can again give the same choice 
        // to that item , and add its cost 
        int yes = (cap >= wt[idx] ) ? solve(N , cap - wt[idx] ,val ,  wt , idx) + val[idx] : -1 ;
        int no = solve(N , cap , val , wt , idx + 1 ) ;
        
        return dp[idx][cap] = max(yes, no) ;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp , -1 , sizeof(dp)) ;
        return solve(N , W, val , wt , 0) ;
    }
};



//tabulation
class Solution{
public:
    
    //tims -> O(N * W) ;
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N + 1 , vector<int>(W + 1 , 0)) ;
        // we are doing tabulation of 1st approach , in which we are choosing one item
        // many number of times unit our capacity become zero;
        // we are choosing one item on one level so our dp is filling (your choice) row
        // by row first for first item , then second item
        //   0 1 2 3 4 5 6 7 8
        // 0 0 0 0 0 0 0 0 0 0
//(1,1) // 1 0
//(3,4) // 2 0
//(4,5) // 3 0 
        // .
        // .
        
        // if capacity is zero then all zero ;
        // if we is zero then all are zero ;
        // now filling from the first col = 1, row = 1;
        for(int item =1 ; item <= N ; item ++){
            for(int cap =1; cap <= W ; cap ++){
                int yes = (cap >= wt[item - 1] ) 
                        ? dp[item][cap - wt[item - 1]] + val[item - 1] 
                        : -1 ;
                int no = dp[item - 1 ][cap];
                
                dp[item][cap] = max(yes , no);
            }
        }
        
        return dp[N][W  ];
    }
};


//reduced on 1D Dp
class Solution{
public:
    
    //Time same as above;
    //space reduced to O(Cap);
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W + 1);
        for(int item =1 ; item <= N ; item ++){
            for(int cap =1; cap <= W ; cap ++){
                int yes = (cap >= wt[item - 1] ) 
                        ? dp[cap - wt[item - 1]] + val[item - 1] 
                        : -1 ;
                int no = dp[cap];
                
                dp[cap] = max(yes , no);
            }
        }
        
        return dp[W  ];
    }
};


//if you have infinite supply then you can form ans from same row;
//or else you can form ans from prev row;

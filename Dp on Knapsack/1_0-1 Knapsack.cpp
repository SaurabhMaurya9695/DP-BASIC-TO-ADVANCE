#include<bits/stdc++.h>
using namespace std;

// time complexity -> O(Capacity * N) ;
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001] ;
    int solve(int capacity ,  int weight [] ,  int cost [] , int totalbag , int idx){
        if(idx == totalbag){
            return 0;
        }
        if(dp[idx][capacity] != -1){
            return dp[idx][capacity];
        }
        
        // if we take in bag then capacity is decrease by its weight 
        int Include = (capacity >= weight[idx]) 
                    ? (solve(capacity - weight[idx] , weight , cost , totalbag , idx + 1) + cost[idx] )
                    : -1; // include in bag and then then we have a profit of cost[idx];
        int NotInclude = solve(capacity , weight , cost , totalbag , idx + 1) ; // not include in bag and give choice to other
        
        // the return the max price 
        return dp[idx][capacity] = max(Include , NotInclude)  ;
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(W , wt , val , n , 0) ;
    }
};
int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}



//tabulation
class Solution
{
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(W + 1 , vector<int>(n + 1 , 0)) ;

       // dp[i][0] && dp[0][i] is filled with zero ;
       //we started from 1;

       // we have to fill col wise ;
       for(int item = 1; item <= n ; item++){
           for(int cap = 1; cap <= W ; cap ++){
               int no = dp[cap][item-1]; // if we taken from no row ;
               int yes = (cap >= wt[item-1]) ? val[item - 1] + dp[cap - wt[item - 1]][item - 1] : -1 ;
               dp[cap][item] = max(no , yes);
           }
       }
       
       return dp[W][n] ; // our ans store at this cell
    } 
};


// space optimization
class Solution
{
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int caps, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> dp(caps + 1 , 0) ; 
       for(int item = 1; item <= n ; item++){
           vector<int> backupDp(caps + 1 , 0);  // our ans is dependent on previous dp t
           for(int cap = 1; cap <= caps ; cap ++){
               int no = dp[cap];
               int yes = (cap >= wt[item-1]) ? val[item - 1] + dp[cap - wt[item - 1]] : -1 ;
               backupDp[cap] = max(no , yes);
           }
           dp = backupDp;
       }
       
       return dp[caps] ;
    } 
};
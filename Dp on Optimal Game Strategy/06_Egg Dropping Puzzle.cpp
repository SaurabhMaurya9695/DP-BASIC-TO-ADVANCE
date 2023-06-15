
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int dp[201][201];
    int solve(int floors , int egg){
        
        // base cases ;
        if(floors == 0){
            return 0;
        }
        
        if(egg == 1) { // then in worst case you can throw from last floor
            return floors ;
        }
        
        if(dp[floors][egg] != -1){
            return dp[floors][egg];
        }
        
        
        int ans = floors;
        //try to throw from each floor ;
        for(int i = 1; i <= floors ; i ++){
            // we are currently at x floor
            // from x floor we can throw up or dowm 
            //. we can throw up when our egg not braks;
            int notBreak = solve(floors - i , egg);
            // if it is break then the quantity of egg is decrese by 1
            int Break = solve(i - 1 , egg - 1); 
            
            int threshold = 1 + max(Break , notBreak) ;
            ans = min(ans , threshold) ;
        }
        
        return dp[floors][egg] = ans ;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp ,-1,sizeof(dp)) ;
        return solve(k ,  n) ;
    }
};

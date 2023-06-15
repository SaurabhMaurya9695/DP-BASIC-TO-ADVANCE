// approach 1:
class Solution {
public:
    int twoEggDrop(int n) {
        // if N == N , and Eggs = 1
        // in worst case we can drop one egg from the top floor , so that egg can be distroyed 
        // here we can use linear serach , failed binary search beacause , if you find ans at some point then
        // your egg distroyed , so we can say this is our ans ;
        
        
        // if N == N , and Eggs = 2;
        
        double ans = (-1.0 + sqrt(1.0 + 8.0 * n ) ) / 2.0  ;
        return (int)(ceil (1.0 * ans)) ;
    }
};


// approach 2 :
class Solution {
public:
    int minMove(int egg,int f,vector<vector<int>> &dp){
        if(egg==1){
            return f;
        }

        if(f==0 || f==1) return f;

        if(dp[egg][f]!=-1) return dp[egg][f];

        int mi=INT_MAX;
        for(int i=1;i<f;++i){
            int Break=minMove(egg-1,i-1,dp);
            int notBreak=minMove(egg,f-i,dp);
            int move=1+max(Break,notBreak);
            mi=min(mi,move);
        }

        return dp[egg][f]=mi;
    }

    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return minMove(2,n,dp);
    }
};


class Solution {
    
    public int f(int eggs,int floors) {
        if(floors == 0 || floors == 1) return floors;
        if(eggs == 1) return floors;

        int ans = Integer.MAX_VALUE;
        for(int i = 1;i <= floors;i++) {
            int min = Math.max( f(eggs-1,i-1) , f(eggs,floors - i));
            if(min < ans) ans = min;
        }
        return ans + 1;
    }
    public int twoEggDrop(int n) {
       int floors = n;
       int eggs = 2;
       return f(eggs,floors);
    }
}
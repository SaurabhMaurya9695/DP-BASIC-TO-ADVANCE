class Solution {
public:
// time -> O(M * N) , space -> O(N * M);
// best case -> O(1) -> if all cell has the value 1;
    int dp[101][101] ;
    int solve(int sr , int sc , int dr , int dc , vector<vector<int>>& arr){
        if(sr > dr || sc  > dc || arr[sr][sc] == 1)
        {
            return 0 ;
        }

        if(sr ==  dr  && sc == dc )
        {
            return 1 ;
        }
        if(dp[sr][sc] != -1)
        {
            return dp[sr][sc] ;
        }
        int right = solve(sr + 1 , sc , dr , dc, arr) ;
        int down  = solve(sr , sc + 1 , dr , dc , arr);
        return dp[sr][sc] = (right + down)  ;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n= arr.size() ;
        int m = arr[0].size() ;
        if(arr[0][0] == 1 || arr[n-1][m-1]){
            return 0 ;
        }
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(0 ,0, n - 1, m  - 1, arr);
    }
};


// tabulation 

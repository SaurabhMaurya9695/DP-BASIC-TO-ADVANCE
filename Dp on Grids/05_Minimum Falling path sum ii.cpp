class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid,int i,int j)
    {
        if(i==grid.size())  //base case{
            return 0;
        }
        if(dp[i][j] != -1){  //if already computed return from there itself
            return dp[i][j];
        }

        int res=INT_MAX;
        for(int k=0;k<grid[0].size();k++)
        {
            //we cant move in same column so if at any point it equals we have to skip it
            if(k==j)
               continue;
            //calulate for other columns recursively
            int ans=grid[i][j]+solve(grid,i+1,k);
            res=min(res,ans); //store the minimum result
        }
        return dp[i][j]=res;//store in dp matrix to avoid duplicate calls and return it
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        if(grid.size()==1)//if size of grid is 1 return the element itself
        {
            return grid[0][0];
        }
        for(int i=0;i<grid[0].size();i++)//traverse over every column and find minimum ans
        {
            ans=min(ans,solve(grid,0,i));
        }
        return ans;    
    }
};
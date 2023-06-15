// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/minimum-cost-path-re-official/ojquestion
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumPath(vector<vector<int>> grid)
{
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , INT_MAX));
    // base case ;
    for(int i= n - 1; i>=0; i--){
        for(int j= m  - 1; j>=0; j--){
            if(i == n - 1 && j == m - 1){
                dp[i][j] = grid[i][j];
                continue;
            }
            
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
    }

    return dp;
}

void dfs(int sr , int sc , vector<vector<int>> & dp , vector<vector<int>> & arr , string s){


    if(sr == arr.size() - 1 && sc == arr[0].size() - 1){
        cout<< s << endl;
        return;
    }

    // check from where min is coming from  ;
    int mini = min(dp[sr + 1][sc] , dp[sr][sc + 1]); 
    
    if(mini == dp[sr ][sc + 1]){
        dfs(sr , sc + 1 , dp , arr , s + "V");
    }

   
    if(mini == dp[sr + 1][sc]){
        dfs(sr + 1 , sc , dp , arr , s + "H");
    }

    
}

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> arr(n , vector<int>(m));
    for(auto &x : arr){
        for(auto &y : x){
            cin >> y ;
        }
    }

    // we have to find a path from source to distination with min cost 
    // for that we need to fill dp table first;
    vector<vector<int>> dp = minimumPath(arr);
    cout<< dp[0][0] << endl;

    // now we have to print all paths .. we can use dfs as well as bfs 
    dfs(0 , 0 , dp , arr , "");
    return 0;
}

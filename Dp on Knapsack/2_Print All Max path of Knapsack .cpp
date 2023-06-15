//first you have to construct dp table  to get all the max path 
//  if you  hav max profit then you can do backtrack and go to that path which is giving us maximum;

// https://www.geeksforgeeks.org/0-1-knapsack-problem-to-print-all-possible-solutions/


//time - > worst case -> exponential (2 ^ n) ;
// average case -> O(V + E) ;
//space - O(V * E) ;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> val {15,14, 10, 45 , 30};
    vector<int> wt{ 2, 5, 1 , 3 ,4};
    int W = 7;
    int n = val.size();
    
    
    // first we have to fill the dp table with maximum profit ;
    vector<vector<int>> dp(W + 1 , vector<int>(n + 1 , 0)) ;
    for(int item = 1; item <= n ; item++){
       for(int cap = 1; cap <= W ; cap ++){
           int no = dp[cap][item-1];
           int yes = (cap >= wt[item-1]) 
                        ? val[item - 1] + dp[cap - wt[item - 1]][item - 1] 
                        : -1 ;
           dp[cap][item] = max(no , yes);
       }
    }
       
       cout<< dp[W][n] << endl;
   // we filled the dp table 
    // now we can use bfs to get the path ;

    // row , col , pathSoFar
    queue<pair< pair<int,int> , string >> q;
    pair<int,int> pp ;
    pp.first = W ;
    pp.second = n ;
    q.push({pp , ""}) ;
    while(!q.empty()){
        pair<pair<int,int>,string> pp = q.front() ;
        int row = pp.first.first ;
        int col = pp.first.second ;
        string psf = pp.second ;

        q.pop();
        if(col == 0) // means we reached to the base index 
        {
            cout << psf << endl;

        }

        if(row >= wt[col- 1] && dp[row][col] == val[col - 1] + dp[row - wt[col- 1]][col -1] ){
            q.push({{(row -  wt[col- 1]) , col - 1} , to_string(col - 1) + " " + psf }) ;
        }
        if(dp[row][col] == dp[row][col - 1]){
            q.push({{row , col - 1} , psf}) ;
        }
    }
    return  0;

}




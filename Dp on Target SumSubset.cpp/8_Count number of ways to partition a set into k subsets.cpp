// worst case -> 2^N ;
#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int solve(int n , int k , vector<vector<int>> dp){
    if (n == 0 || k == 0 || k > n){
        return 0;
    }
    
    if (k == 1 || k == n){
        return 1;
    }

    if(dp[n][k] != -1){
        return dp[n][k];
    }

    //if we shared 
    int SharedAns = solve(n - 1 , k , dp) * k ;
    // if we have private room 
    int PrivateAns = solve(n - 1, k - 1 , dp) ;

    return dp[n][k] = (SharedAns + PrivateAns );

}

int main(){
    ll n ;
    cin >> n ;
    ll k ;
    cin >> k ;

    vector<vector<int>> dp( n + 1, vector<int>(k + 1 ,-1)) ;
    cout <<solve(n , k , dp) << endl;;
}



//tabulation

#include<iostream>
using namespace std;

int countP(int n, int k)
{
    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= k; i++)
        dp[0][k] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        if (j == 1 || i == j)
            dp[i][j] = 1;
        else
            dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];

    return dp[n][k];
}


int main()
{
    cout << countP(5, 2);
    return 0;
}

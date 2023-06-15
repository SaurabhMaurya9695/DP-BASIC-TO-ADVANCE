// worst case -> 2^N ;
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n ;
    cin >> n ;
    vector<ll> arr (n) ;
    for(auto & x : arr){
        cin >> x;
    }
    ll target ;
    cin >> target ;

    vector<vector<int>>dp(n + 1, vector<int>(target + 1 , 0)) ;
    dp[0][0] = 1 ;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            int no = dp[i - 1][j]; // No Call
            int yes = (j >= arr[i - 1]) ? dp[i - 1][j - arr[i - 1]] : 0;

            dp[i][j] = (no + yes) ;
        }
    }
    if(dp[n][target] > 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    // filled our dp with all paths ,
    // cout <<  dp[n][target] << endl;

    queue<pair<pair<int,int> , string>> q;
    q.push({{n , target} , ""}) ; // entering row , col , pathSoFar ;
    while(!q.empty()){
        pair<pair<int,int> , string> pp =  q.front();
        int row = pp.first.first ;
        int col = pp.first.second ;
        int rowVal =  arr[row - 1] ;
        string ans = pp.second ;
        q.pop();


        if(row == 0){
            cout << ans << endl;
            continue;
        }

        //yes call
        if(col >= arr[row - 1]  && dp[row - 1][col - arr[row - 1]] > 0){
            q.push({{ row - 1, col - arr[row - 1]  } , to_string(row - 1) + " "+  ans }) ;
        }

        // if ans is coming from the row -> NO call ;
        if(dp[row - 1][col] > 0){
            q.push({{ row - 1, col } , ans }) ;
        }
    }


}
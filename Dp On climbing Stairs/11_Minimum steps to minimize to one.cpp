#include<bits/stdc++.h>
using namespace std;
/*
 *    coder :: Saurabh Maurya
 *        >>> INDIA <<<
 */
 #define sz(x) (int)(x).size()
#define ll long long
int  solve(ll n , vector<ll > &dp)
{

    if(n == 1){
        return 0 ;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    // if it is divisible by 2 then call 
    int by2 = (n % 2 == 0 && n >= 2) ? solve(n / 2 , dp ) : INT_MAX;

    // if it is divisible by 3 then call 
    int by3 = (n % 3 == 0 && n >= 3) ? solve(n / 3 , dp) : INT_MAX;

    int dec = solve(n - 1  , dp) ;

    return dp[n] = min({by2 , by3 , dec}) + 1;


}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n ;
        cin >> n ;
        vector<ll> dp (n + 1, -1) ;
        cout << solve(n , dp) << endl;

    }
}


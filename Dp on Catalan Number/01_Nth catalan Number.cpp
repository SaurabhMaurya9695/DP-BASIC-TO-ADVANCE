#include<bits/stdc++.h>
using namespace std;

#define ll long long 


void solve()
{
    ll n ;
    cin >> n ;
    vector<ll > catalan(n ) ;
    catalan[0] = 1;
    catalan[1] = 1;
    // to find nth catalan number 
    for(int i = 2 ; i < n; i ++){
        for(int j = 0 ; j < i ; j ++){
            catalan[i] += catalan[j] * catalan[i - j - 1] ;
        }
    }

    for(int i = 0 ; i < catalan.size() ; i++){
        cout << catalan[i] << " " ;
    }

}
 
int main()
{
    solve();

}


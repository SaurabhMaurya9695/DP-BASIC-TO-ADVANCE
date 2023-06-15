//g++  7.4.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long 


void solve()
{
   ll n;
   cin>>n;
   vector<ll>arr(n);
   for (auto &x : arr){
       cin>>x;
   }
   
   unordered_map<ll ,ll > mp;
   for(auto x : arr) mp[x] ++ ; 
   ll maxi =  INT_MIN ;
    ll val = 0;
   for(auto x : mp){
        if(x.second > maxi){
            maxi = x.second ;
            val = x.first ;
        }
   }

   for(int i = 0 ; i < n ; i++){
        if(arr[i] != val){
            cout << i + 1<< " ";
        }
   }
   cout << endl;
   return;

}

int main()
{
    ll t ;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
    
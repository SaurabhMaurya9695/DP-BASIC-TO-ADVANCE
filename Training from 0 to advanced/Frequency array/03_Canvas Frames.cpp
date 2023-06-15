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
   unordered_map<ll,ll>mp;
   for(auto x: arr) mp [x]++;
   ll ans = 0;
   for(auto &[l,r] : mp){
        if(r >= 4){
            ans += (r / 4 );
            mp[l] = (r % 4); 
        }
   }

   ll cnt = 0;
   for(auto &[l,r] : mp){
        if(r >= 2){
            cnt++ ;
        }
   }

   ans += (cnt / 2) ;
   cout<< ans << endl;
   return ;

}

int main()
{
    //ll t = 1;
    //cin>>t;
    //while(t--){
        solve();
    //}
    
    return 0;
}
    
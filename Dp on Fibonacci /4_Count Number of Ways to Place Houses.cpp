			// 1 10 100 ...
			// 0 {00,01} {000,001 ,010} ... -> dp0[i-1] + dp1[i-1];

class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int countHousePlacements(int n) {
       vector<ll > dp0 ( n + 1) ;// ending with zero ;
	   vector<ll > dp1 ( n + 1) ;// ending with ones ;
	   dp0[1] = 1; // length with 1 ;
	   dp1[1] = 1; // length with 1 ;
	   for(ll i = 2 ; i <=  n ; i++)
	   {
	       dp0[i] = (dp0[i - 1] + dp1[i - 1]) % mod;
	       dp1[i] = dp0[i -1 ];
	   }
	   ll ans =  (dp0[n] + dp1[n]) % mod ;
       return (ans * ans) % mod ;
    }
};
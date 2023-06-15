
class Solution{
public:
	#define ll long long
	#define mod 1000000007
	ll countStrings(int n) {
	   vector<ll > dp0 ( n + 1) ;// ending with zero ;
	   vector<ll > dp1 ( n + 1) ;// ending with ones ;
	   dp0[1] = 1; // length with 1 ;
	   dp1[1] = 1; // length with 1 ;
	   for(ll i = 2 ; i <=  n ; i++)
	   {
	       dp0[i] = (dp0[i - 1] + dp1[i - 1]) % mod; 
	       dp1[i] = dp0[i -1 ];
	   }
	   return (dp0[n] + dp1[n]) % mod ;
	   
	}
};


// 
class Solution{
public:
	#define ll long long
	#define mod 1000000007
	ll dp[100005][2] ;
	ll solve(ll n , ll prev){
	    if(n < 0 ) return 0;
	    if(n == 0){
	         return 1;
	    }
	    
	    if(dp[n][prev] != -1){
	        return dp[n][prev];
	    }
	    ll appendWithZero = solve(n - 1 , 0) ;
	    ll appendWithOne = (prev == 0) ? solve(n - 1 , 1) : 0 ;
	    
	    return dp[n][prev] = (appendWithZero + appendWithOne) % mod ;
	}
	
	ll countStrings(int n) {
	    memset(dp ,-1 ,sizeof(dp)) ;
	    return solve(n , 0);
	}
}


// printing all 
void countStrings(int n, string out, int last_digit)
{
    // if the number becomes n–digit, print it
    if (n == 0)
    {
        cout << out << endl;
        return;
    }
 
    // append 0 to the result and recur with one less digit
    countStrings(n - 1, out + "0", 0);
 
    // append 1 to the result and recur with one less digit
    // only if the last digit is 0
    if (last_digit == 0) {
        countStrings(n - 1, out + "1", 1);
    }
}
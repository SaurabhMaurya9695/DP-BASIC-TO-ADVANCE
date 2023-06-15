#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define ll long long
int main()
{
    string s;
    cin >> s;
    string t = "chokudai" ;
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n + 1 , vector<int>( 9 , 0)) ;

    /*
        dp[i][j] = total  number of subsequence of pref of j th element 
        of string t at the end of ith index of string s;
    */

    for(int i = 0 ; i <= m ; i ++){
        if(i == t.size()){
            dp[n][i] = 1;
        }
    }


    for(int i = 0 ; i <= n ; i ++){
        if(i == s.size()){
            dp[i][m] = 1;
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 8 ; j >= 0 ; j --){
            char ch  = s[i] ;
            char ch1 = t[j];
            // if both are same 
            ll part  = 0 ;
            ll Not_part  = 0;
            if(ch == ch1){
                 part     = dp[i + 1][j + 1] % 1000000007;
                 Not_part = dp[i + 1][j] % 1000000007;
            }
            else{
                 Not_part = dp[i + 1][j] % 1000000007;
            }

            dp[i][j] = (part + Not_part) %  1000000007 ; 
        }
    }

    cout << dp[0][0] % 1000000007 << endl ;
}

/*```````````````````````````````````````````````````````````````````````````````````````````````````````*/

#include<bits/stdc++.h>
using namespace std;

// always think for n == 1 , n == 0 
// in 1 sec we can do 10^7
// if choices given think for dp or memorization 
// read the question again , question is giving us the clue ;
// if you have to find number of ways then think for pnc and dp .
// in ways type of question start dry run from n : 0 ,1, 2 ... n and find
// the rec relation 

ll dp[100001][9] ;
ll solve(string s , ll i ,  string t  , ll j)
{
	//base case;
	if(j == t.size()) return 1;
	if(i == s.size() ){
		if(j == t.size()){
			return 1;
		}
		else{
			return  0;
		}
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

    //chokudai
    char ch  = s[i] ;
    char ch1 = t[j];
    // if both are same 
    ll part  = 0 ;
    ll Not_part  = 0;
    if(ch == ch1){
		 part     =   solve(s , i + 1 , t , j + 1) % 1000000007;
		 Not_part =   solve(s , i + 1 , t , j ) % 1000000007;
    }
    else{
    	 Not_part =   solve(s , i + 1 , t , j) % 1000000007;
    }

    return dp[i][j] = (part + Not_part) %  1000000007 ;
}
 
int main()
{
    fast;
    ll t = 1;
    // cin >> t;
    while(t--)
    {
    	memset(dp ,-1 , sizeof(dp)) ;
    	string s;
    	cin >> s;
    	string t = "chokudai" ;
        cout << solve(s ,  0 , t , 0 ) << endl;
    }
}


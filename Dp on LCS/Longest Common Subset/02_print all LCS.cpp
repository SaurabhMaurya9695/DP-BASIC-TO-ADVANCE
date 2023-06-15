#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solve(string s , string t)
{
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n + 1 , vector<int>( m + 1 , 0));

    for(int i = n - 1; i >= 0 ; i --){
        for(int j = m - 1 ; j >= 0 ; j--){
            char ch1 = s[i] ;
            char ch2 = t[j] ;
            if(ch1 == ch2){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }
    }

    return dp;
}

set<string> st ;
void helper(int i , int j , string s1 , string s2 ,  vector<vector<int>> dp , string lcs)
{
    if (i == s1.size() || j == s2.size()) {
        st.insert(lcs);
        return;
    }


    if (s1[i] == s2[j]) {
        // Character Taken (Same)
        helper(i + 1, j + 1, s1, s2, dp, lcs + s1[i] );
    } else {
        // Character Not Taken
        int maxi = max(dp[i][j+1] , dp[i+1][j]);
        if(maxi == dp[i][j+1] && maxi == dp[i+1][j]){ // if we get max form both cells then make 
            //call on both cell
            helper(i + 1 , j , s1, s2 , dp , lcs);
            helper(i  , j + 1 , s1, s2 , dp , lcs);
        }
        else if(maxi != dp[i][j+1] && maxi == dp[i+1][j]){ // otherwise make call on only max cell
            helper(i + 1 , j  , s1, s2 , dp , lcs);   
        }
        else{
            helper(i  , j + 1 , s1, s2 , dp , lcs);
        }
    }
 
}

 
int main()
{
    string s, t;
    cin >> s >> t;
    // this function returning filled LCS dp table ;
    vector<vector<int>> dp = solve(s , t);

    // now we have to print ALL LCS
    helper(0 , 0 , s, t , dp , "" );

    for(auto x : st){
        cout << x << " ";
    }
    cout << endl;
    return 0 ;

}


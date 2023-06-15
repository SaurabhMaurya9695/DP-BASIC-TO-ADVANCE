//User function template for C++

class Solution{
  public:
  int tab(string s , string t)
    {
        int n = s.size() ;
        int m = t.size() ;
        vector<vector<int>>dp(n + 1 , vector<int> (m + 1 )) ;
        for(int i = n - 1 ; i>=0 ; i--)
        {
            for(int j = m - 1 ; j>=0 ; j--)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else{
                    dp[i][j] = 0 + max(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        return dp[0][0] ;
        
    }
    int minimumNumberOfDeletions(string s) { 
       string t = s;
        reverse(s.begin() , s.end()) ;
        int LCS =  tab(s , t) ;
        return (s.size() - LCS);
    } 
};
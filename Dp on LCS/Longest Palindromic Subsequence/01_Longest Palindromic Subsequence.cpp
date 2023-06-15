class Solution {
public:
    
    vector<vector<int>> dp ;
    int LCS(int i, int j, string &s1, string &s2)
    {
        if(i == s1.size() || j == s2.size()) 
            return 0; // LCS of Empty String with Other String is Empty String only
        
        if(dp[i][j] != -1) return dp[i][j];
        
        char ch1 = s1[i];
        char ch2 = s2[j];
        
        if(ch1 == ch2) // If characters are same, take the common from both of them
            return dp[i][j] = 1 + LCS(i + 1, j + 1, s1, s2);
        
        // If character is uncommon, either not take s1[i] or not take s2[j]
        int option1 = LCS(i + 1, j, s1, s2);
        int option2 = LCS(i, j + 1, s1, s2);
        return dp[i][j] =   max(option1, option2);
    }
    int longestPalindromeSubseq(string s) {
        
        string t = s;
        int n = s.size() ;
        dp.resize(n+1 , vector<int>(n + 1 ,-1));
        reverse(s.begin() , s.end());
        return LCS(0, 0 , s , t);
    }
};


//tabulation 
int longestPalindromeSubseq(string s) 
{
    string t = s;
    int n = s.size() ;
    reverse(s.begin() , s.end());
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
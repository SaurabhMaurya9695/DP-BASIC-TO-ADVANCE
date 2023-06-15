class Solution {
public:

        
    //  Time - O(N * M + N + M), Space - O(N * M) 2D DP
    vector<vector<int>> Filled_LCS(string &s , string &t){
        int n = s.size() ;
        int m = t.size() ;
        vector<vector<int>>dp(n + 1 , vector<int> (m + 1 , 0)) ;
        for(int i = n - 1 ; i>=0 ; i--)
        {
            for(int j = m - 1 ; j>=0 ; j--)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        return dp;
    }
    
    
    string scs = "";
    void SuperSS(int i, int j , string &s , string &t, vector<vector<int>> &dp, string ans){
        
        if (i == s.size() && j == t.size()) {
            scs = ans;
            return;
        }

        char ch1 = (i < s.size()) ? s[i] : 'A';
        char ch2 = (j < t.size()) ? t[j] : 'B';

        if (ch1 == ch2) {
            // Yes - Diagonal
            SuperSS(i + 1, j + 1, s, t, dp, ans + ch1);
        } else if (i + 1 <= s.length() && dp[i][j] == dp[i + 1][j]) {
            // No - Down
            SuperSS(i + 1, j, s, t, dp, ans + ch1);
        } else {
            // No - Right
            SuperSS(i, j + 1, s, t, dp, ans + ch2);
        }
        
    }

    
    string shortestCommonSupersequence(string s, string t) {
        // order should be preserved and common in both
        // abac  cab 
        // cabac -> cab present and abac present ;
        
        // possible ans is : abacab , cabac , cababac ,
        // the LCS of both string is : ab ;
        // if you observe here , we are writing above LCS two times ,
        // if we write LCS one time then we can get a shortestCommonSubsequence ;
        
        // if this question ask for length  s.size() + t.size() - LCS_length ;
        
        // then we need LCS table , with the help of LCS table 
        
        vector<vector<int>> dp = Filled_LCS(s , t);
        // here we have filled dp ;
        // now we have to do backtrack on dp table to make the supersubsequence;
        SuperSS(0,0,s,t,dp,"");
        
        return scs;
    }
};
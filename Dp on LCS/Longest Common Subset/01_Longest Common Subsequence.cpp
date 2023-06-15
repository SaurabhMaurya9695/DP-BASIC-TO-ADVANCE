// for a string s , we have subsequece 2 ^ n , every char has a option to be included in ans
// or not
// for subsequence order of subsequence should be matters 

                // time -> O(n * n) , space -> O(s.size() * t.size()) ;
class Solution {
public:
    int dp[1001][1001];
    int LCS(int i, int j, string s1, string s2)
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
        return dp[i][j] =  0 + max(option1, option2);
    }

    int longestCommonSubsequence(string s, string t) 
    {
        int n = s.size() ;
        int m = t.size() ;
        memset(dp , -1 , sizeof(dp)) ;
        return LCS(0,0, s, t);
    }
};
    
// working
class Solution {
    int dfs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + dfs(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(dfs(i - 1, j, s1, s2, dp), dfs(i, j - 1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        
        return dfs(n, m, s1, s2, dp);
    }
};


// Tabulation 
int longestCommonSubsequence(string s, string t) 
    {
        int n = s.size() ;
        int m = t.size() ;
        vector<vector<int>>dp(n + 1 , vector<int> (m + 1 , 0)) ; // whole dp table filled with 0 
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
        return dp[0][0] ;
        
        
    }
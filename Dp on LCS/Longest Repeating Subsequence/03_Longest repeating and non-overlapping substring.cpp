

class Solution {
  public:
    string longestSubstring(string s, int n) {
        // banana -> LCSS -> ana , ana in both a is common in both of the strings
        int dp[n+1][n+1];
        int idx = s.size(), len = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = s.size() - 1; j >= 0; j--) {
                char ch1 = s[i];
                char ch2 = s[j];

                if (ch1 == ch2 && i != j)
                    dp[i][j] = 1 + dp[i + 1][j + 1];

                if (abs(i - j) <= dp[i][j]) {
                    // Overlapping Substrings
                    dp[i][j] = 0;
                }

                if (dp[i][j] >= len) {
                    idx = i;
                    len = dp[i][j];
                }
            }
        }

        if (len == 0)
            return "-1";
        string res ="";
        for (int i = idx ; i <= idx + len; i++)
            res += s[i ];
        return res ;
    }
};


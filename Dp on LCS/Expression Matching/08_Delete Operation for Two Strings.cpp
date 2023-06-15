class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , string s , string t){
        
        int n = s.size();
        int m = t.size();
        
        if(i == s.size() && j == t.size()){
            return 0 ;
        }
        if(i == s.size() && j < t.size()){
            return m - j ;
        }
        if(i < s.size() && j == t.size()){
            return n - i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        char x = s[i];
        char y = t[j];
        
        if(x != y){
            int left_exclude = solve(i + 1 , j ,  s , t);
            int right_exclude = solve(i , j + 1 ,  s , t);
            return  dp[i][j] = 1 + min(left_exclude , right_exclude) ;
        }
        return dp[i][j] = solve(i + 1, j + 1, s,  t);
    }
    int minDistance(string word1, string word2) {
        memset(dp , -1 , sizeof(dp)) ;
        return solve(0 , 0 , word1 , word2) ;
    }
};
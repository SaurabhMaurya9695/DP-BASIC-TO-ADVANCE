// s = babgbag , t = bag

// if both of char is matching then make call of yes , s = abgbag , t = ag 
// if t says not to include in ans , s = abgbag , t = bag 

// LCS(i , j) =>  (s[i] == t[j]) LCS(i + 1 , j + 1) + LCS(i + 1, j) ;
// (s[i] != t[j]) LCS(i+1 , j);

// time -> O( n * m) ;
// space -> O(n * m);
class Solution {
public:
    
    int dp[1001][1001];
    int solve(int i , int j , string &s , string &t){
        if( j == t.size()) {   // second string is totally exhasuted , we found int s string 
            return 1;
            
        }
        if(i == s.size() ){
            // we exhausted fully s string  nothing to match left ;
            return 0 ;
        }
        if(dp[i][j]  != -1){
            return dp[i][j]  ;
        }
        char ch = s[i];
        char ch1 = t[j];
        
        if(ch == ch1){ // if both of the char is matching 
            int left  = solve(i + 1 , j + 1, s , t);
            int right = solve(i + 1 , j , s , t);
            return dp[i][j] = (left + right);
        }
        return dp[i][j]  = solve(i + 1 , j , s ,t);
        
    }
    
    int numDistinct(string s, string t) {
        memset(dp ,-1, sizeof(dp));
        return solve(0 ,0 ,s ,t);
    }
};
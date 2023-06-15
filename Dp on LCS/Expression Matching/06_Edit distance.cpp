class Solution {
public:
    
    int dp[501][501];
    // time - > O(N * N) // worst case ;
    int solve(int i , int j , string &s , string &t){
        
        // base cases ;
        if(i == s.size() && j == t.size()){ // both strings are empty
            return 0;
        }
        if(i == s.size() && j < t.size()){ // "" "abc" -> n operations to insert
            return t.size() - j  ;
        }
        
        if(i < s.size() && j == t.size()){ // "abc" ""-> n operations to delete
            return s.size() - i;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        if(s[i] != t[j]){ // if the char is not same make all 3 calls and take min of them
            int insert  = solve(i , j + 1, s , t);
            int deleted = solve(i + 1 , j , s , t);
            int replace = solve(i + 1 , j + 1, s , t);
            
            return dp[i][j]  = 1 + min({insert , deleted , replace}) ;
        }
        else{
            return dp[i][j] =  solve(i + 1 , j + 1, s , t) ;
        }
    }
    int minDistance(string s, string t) {
        memset(dp ,-1 , sizeof(dp));
        return solve(0 , 0 , s , t);
    }
};
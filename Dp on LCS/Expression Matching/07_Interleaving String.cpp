class Solution {
public:
    
    int dp[101][101][202];
    bool solve(int i , int j ,int k , string &s1 , string &s2, string &s3){
        
        if(k == s3.size()) // resultant is empty
        {
            return true;
        }
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        char ch =  (i < s1.size()) ? s1[i] : 'A'; // for protecting our string s1 to be empty so just assign random char
        char ch1 = (j < s2.size()) ? s2[j] : 'B';
        
        
        if(ch == s3[k] && ch1 == s3[k]){
            // we have to two calls here 
            bool left  =  solve(i + 1, j , k + 1, s1, s2, s3) ;
            bool right = solve(i , j + 1, k + 1, s1, s2, s3) ;
            return dp[i][j][k] = (left || right);
        }
        else if(ch == s3[k] && ch1 != s3[k]){
            return dp[i][j][k] = solve(i + 1, j , k + 1, s1, s2, s3) ;
        }
        else if(ch != s3[k] && ch1 == s3[k]){
            return dp[i][j][k] = solve(i , j + 1, k + 1, s1, s2, s3) ;
        }
        return dp[i][j][k] = false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        memset(dp , -1 ,sizeof(dp)) ;
        return solve(0,0,0,s1,s2,s3) ;
    }
};
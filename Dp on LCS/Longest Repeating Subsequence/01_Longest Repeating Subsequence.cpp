// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// TLE on gfg 
class Solution {
	public:
	
	    int dp[1001][1001];
	    int solve(string s , string t , int i , int j){
	        if(i == s.size() || j == t.size()) {
	            return 0;
	        }
	        
	        if(dp[i][j] != -1){
	            return dp[i][j];
	        }
	        
	        char ch = s[i];
	        char ch1 = s[j];
	        if(ch == ch1 && i != j) // just one change is here 
	        {
	            dp[i][j] =  1 + solve(s , t , i + 1 , j + 1);
	        }
	        else{
	            int left = solve(s , t , i + 1, j);
	            int right = solve(s , t , i, j + 1);
	            
	            dp[i][j] =  max(left, right) ;
	        }
	        
	        return dp[i][j] ;
	    }
		int LongestRepeatingSubsequence(string str){
		    // take LCS with itself but the condition is for both idx ,
		    // value should be different ;
		    
		    memset(dp , -1, sizeof(dp));
		    return solve(str , str , 0 , 0) ;
		}

};




// tabulation
class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    int n = s.size() ;
		    vector<vector<int>> dp(n + 1, vector<int>(n + 1 , 0));
		    for(int i = n - 1 ; i>= 0 ; i --){
		        for(int j = n - 1; j >= 0 ; j--){
		            char x = s[i];
		            char y = s[j];
		            if(x == y && i != j){
		                dp[i][j] = 1 + dp[i+1][j+1];
		            }
		            else{
		                dp[i][j] = max(dp[i][j+1] , dp[i+1][j]);
		            }
		        }
		    }
		    
		    return dp[0][0];
		}

};
class Solution{
		

	public:
	int minOperations(string s, string t) 
	{ 
	   //this is nothing but for delete from str1 opertion is : n - LCS
	   //this is nothing but for delete from str1 opertion is : m - LCS
	   
	   int n = s.size() , m = t.size() ;
	   vector<vector<int>> dp(n + 1 , vector<int>(m + 1,  0)) ;
	   for(int i = n - 1; i >= 0 ; i --){
	       for(int j = m - 1; j >= 0; j --){
	           if(s[i] == t[j]){
	               dp[i][j] = 1 + dp[i+1][j+1];
	           }
	           else{
	               dp[i][j] = max(dp[i][j+1] , dp[i+1][j]);
	           }
	       }
	   }
	   
	   int LCS = dp[0][0] ;
	   return (n - LCS) + (m - LCS) ;
	   
	    
	} 
};
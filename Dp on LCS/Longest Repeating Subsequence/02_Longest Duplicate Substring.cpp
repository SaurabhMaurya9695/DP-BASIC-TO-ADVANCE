
        // Failed on some TC , and it will give TLE , 
        // expected Rolling hash algo
class Solution {
public:
    string longestDupSubstring(string s) {
        //https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
        // do this questiob before solving this
            int n = s.size() ;
            int LDSS = 0 ,  idx = s.size() ;
		    vector<vector<int>> dp(n + 1, vector<int>(n + 1 , 0));
		    for(int i = n - 1 ; i>= 0 ; i --){
		        for(int j = n - 1; j >= 0 ; j--){
		            char x = s[i];
		            char y = s[j];
		            if(x == y && i != j){
		                dp[i][j] = 1 + dp[i+1][j+1];
		            }
		            
                    if(dp[i][j] > LDSS){
                        LDSS = dp[i][j];
                        idx = i;
                    }
                    
                    // LDSS = max(LDSS , dp[i][j]);
		        }
		    }
		    cout << LDSS << endl;
		    return s.substr(idx , idx + LDSS);
        
    }
};
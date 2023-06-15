// substring should be contiguous - "abcdabc" "bcdbca"
// then the Longest common Substring is : "bcd" , "cd" , "bc" . 
// "bcd" which is continues in nature 

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//tabulation

int longestCommonSubstr (string s, string t , int n, int m)
{
    // return solve(S1,S2 , n , m , 0 , 0);
    vector<vector<int>> dp ( n + 1 , vector<int>(m + 1 , 0)) ;
    int maxLCSS = 0;
    for(int i = n - 1 ; i>= 0 ; i--){
        for(int j = m - 1; j >= 0 ; j--){
            if(s[i] == t[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            
            maxLCSS = max(maxLCSS , dp[i][j]); //our ans can be present anywhere in cell 
        }
        
    }
    
    return maxLCSS;
}


// memorization
class Solution{
    public:
    
    int dp[1001][1001];
    int lcs(string X, string Y, int i, int j, int count)
    {
     
        if (i == 0 || j == 0)
            return count;
     
        if (X[i - 1] == Y[j - 1]) {
            count = lcs(X , Y , i - 1, j - 1, count + 1);
        
        }
        count = max(count, max(lcs( X , Y , i, j - 1, 0), lcs(X , Y , i - 1, j, 0)));
        return count ;
    }
    
    int longestCommonSubstr (string s, string t , int n, int m)
    {
        
        memset(dp ,-1 , sizeof(dp)) ;
        return lcs(s,t , n , m , 0);
        
    }
}

// Memorixation
class Solution{
    int ans=0;
    int solve(String s1,String s2,int n,int m,int[][] dp){
        if(n==0||m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int count=0;
        if(s1.charAt(n-1)==s2.charAt(m-1)){
            count=1+solve(s1,s2,n-1,m-1,dp);
            ans=Math.max(ans,count);
        }
        solve(s1,s2,n-1,m,dp);
        solve(s1,s2,n,m-1,dp);
        return dp[n][m]=count;
       
    }
    int longestCommonSubstr(String s1, String s2, int n, int m){
        // code here
        int dp[][]=new int[n+1][m+1];
        for(int[] arr:dp)
        {
            Arrays.fill(arr,-1);
        }
        solve(s1,s2,n,m,dp);
        return ans;
    }
}
class Solution {
public:
    // time - >O(N  * N / 2) ;
    //space -> O (N) ;
    bool isPalindrome(string &S)
    {
        for (int i = 0; i < S.length() / 2; i++)
        {
            if (S[i] != S[S.length() - i - 1])
            {
                return false;
            }
        }

        return true;
    }
    
    int dp[2001] ;
    int solve(int i , string &s){
        
        if(i == s.size()){
            return  0 ;
        }
        
        if(dp[i] != -1){
            return dp[i] ;
        }
        int minCost = INT_MAX ;
        string temp = "";
        for(int j = i ; j < s.size() ; j ++){ 
            temp += s[j] ;
            if(isPalindrome(temp) == true){
                int cost = 1 + solve(j + 1, s);
                minCost = min(minCost,  cost) ;
            }
        }
        
        return dp[i] = minCost ;
    }
    int minCut(string s) {
        memset(dp ,-1 , sizeof(dp)) ;
        return solve(0 , s) - 1;  // we did -1 because 
        // if take a example of ABC ;
        // if i == n then we stand up at c then we did A | B | C |  to remove last partition we subtract -1
    }
};



//tabulation
// here we reduced recursion stack space;
class Solution {
public:
    bool isPalindrome(string &S)
    {
        for (int i = 0; i < S.length() / 2; i++)
        {
            if (S[i] != S[S.length() - i - 1])
            {
                return false;
            }
        }

        return true;
    }
    
    int minCut(string s) {
        int n = s.size() ;
        vector<int> dp (n + 1,  0) ;
        
        // base case 
        dp[n] = 0;
        for(int i = n- 1 ; i>= 0 ; i--){
            int minCost = INT_MAX ;
            string temp = "";
            for(int j = i ; j < s.size() ; j ++){
                temp += s[j] ;
                if(isPalindrome(temp) == true){
                    int cost = 1 + dp[j + 1] ;
                    minCost = min(minCost,  cost) ;
                }
            }
            dp[i] = minCost ;
        }
        
        return dp[0] - 1 ;
        
    }
};

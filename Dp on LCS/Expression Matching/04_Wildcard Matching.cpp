// s =  architagg
// pattern = a*h?t*a?g

// you can replace * with single or group of char 'a' , 'aa' , 'abc' or you can replace with "" ;
// ? -> you can replace with single char 

// for this question we have four things while writing a recursion 

// 1 - s[i] == t[j] || t[j] == '?' || t[j] == '*' || s[i] != t[j] 

class Solution {
public:
    
    int dp[2001][2001] ;
    bool solve(int i , int j , string &s , string &p ){
        if (i >= s.size() && j >= p.size()) {
            return true;
        }

        if (i < s.size() && j == p.size()) {
            // first string is not empty, second string is empty
            return false;
        }

        if (i == s.size() && j < p.size()) {
            // first string is empty, second string is still left
            for (int k = j; k < p.size(); k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        char ch1 = s[i];
        char ch2 = p[j];

        if (ch1 == ch2 || ch2 == '?') {
            return dp[i][j] = solve(i + 1, j + 1, s, p);
        }

        if (ch2 == '*') {
            bool no = solve(i, j + 1, s, p);
            bool yes = solve(i + 1, j, s, p);
            return dp[i][j] = (yes || no );
        }

        // unequal characters
        return dp[i][j] = false;
        
    }
    
    bool isMatch(string s, string p) {
        memset(dp , -1, sizeof(dp));
        return solve( 0 , 0 , s , p) ;
    }
};



//````````````````````````//````````````````````````//````````````````````````//````````````````````````
class Solution {
public:
    bool func(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        //Base Case :- If my pattern string is consumed then check that my input string is consumed or not.
        if(j == p.size())return i == s.size();
        
        //If my input string is consumed then check for the pattern string that it contains all *'s or not.
        if(i == s.size())return p[j] == '*' && func(s,p,i,j+1,dp);
        
        //If i already stored the result then return it, no need to compute it again.
        if(dp[i][j] != -1)return dp[i][j];
        
        //If we found a match or p[j] == '?' then increment the pointers
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = func(s,p,i+1,j+1,dp);
        
        //If we found a '*' then we have two conditions: take or not
        if(p[j] == '*')
            return dp[i][j] = func(s,p,i,j+1,dp) | func(s,p,i+1,j,dp);
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return func(s,p,0,0,dp);
    }
};
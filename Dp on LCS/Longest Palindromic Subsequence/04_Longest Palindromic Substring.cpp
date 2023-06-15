            // Wrong on TC 53
class Solution {
public:
    
    bool ispalindrome(string &s){
        int i = 0 , j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i ++ ;
            j -- ;
        }
        return true;
    }
    
    string solve(string s , string t){
        int n = s.size() ;
        vector<vector<int>>dp(n + 1 , vector<int> ( n + 1 , 0)) ; // whole dp table filled with 0 
        
        string res = ""  ;
        for(int i = n - 1 ; i>=0 ; i--)
        {
            for(int j = n - 1 ; j>=0 ; j--)
            {
                if(s[i] == t[j] )
                {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                if(dp[i][j] >= res.size() ){
                    string check ;
                    for(int k = i ; k  < i + dp[i][j] ; k++){
                        check += s[k];
                    }
                    if(ispalindrome(check) == true){
                        res = check;
                    }
                }
            }
        }

        return res ;
    }
    string longestPalindrome(string s) {
        // this is just same as longest common substring 
        // but for palindorm we have to make LCS with reverse of s ;
        // and for substring we just need to add one more condition  i != j
        // s = "abcbe"
        // t = "ebcba"
        string t = s;
        reverse(s.begin() , s.end()) ;
        return solve(t , s ) ;
        
    }
};


// ``````````````````````````````````````````````````````````````````````````````````````````````````````/

                //Method 2 -> expand around center ;


// https://leetcode.com/problems/longest-palindromic-substring/discuss/3401644/Detailed-recursive-explaination-with-Pictures-in-C%2B%2BJavaPythonDPtwo-pointers

class Solution {
public:
    string ans = "";
    void expand(string &s , int left ,int right)
    {
        while(left >= 0 &&  right < s.size()) // go on left and right 
        {
            if(s[left] != s[right])  // unitl this condition meets
                break;
            left--,right++;
        }
        
        if(ans.size() < right - left )
            ans = s.substr(left + 1 , right - left - 1);
    }
    string longestPalindrome(string s) {
        
        int n =s.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            expand(s , i , i);  // for even partion 
            expand(s , i , i+1); // for odd partion 
        }
        return ans;
    }
};



// ````````````````````````````````````````````````````````````````````````````````````````````````````````````````````



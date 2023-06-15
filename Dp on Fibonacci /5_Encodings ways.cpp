class Solution {
public:
    
    int dp[1005] ;
    int solve(int idx , string s , int n )
    {
        int left = 0 , right  = 0 ;
        if(idx == n)
        {
            if(s[idx] == '0') return 0 ;   // 0
            else{
                return 1;
            }
        }
        // lookup table;
        if(dp[idx] != - 1)
        {
            return dp[idx];
        }
        int ch = s[idx] - '0';
        if(ch >= 1 && ch <= 9)
        {
            left += solve(idx + 1 , s, n );
        }
        else{
            left += 0;
        }
        if(idx+1 < n)
        {
            int ch2 =  (s[idx] - '0') * 10 + (s[idx + 1] - '0');
            if(ch2 >= 10 && ch2 <= 26)
            {
                right += solve(idx + 2 , s, n);
            }
            else{  //61 58
                right += 0;
            }
        }
         int ans =  left + right ;
        return dp[idx] = ans ;
    }
    int numDecodings(string s) 
    {
        int n = s.size() ;
        memset(dp , -1 , sizeof(dp)) ;
        return solve(0, s, n );
    }
    
};


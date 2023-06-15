class Solution {
public:
    bool isPalindrome(string S)
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
    
    
    vector<vector<string >> res ;
    vector<string> ans ;
    void solve(string s ){
        if(s.size() == 0){
            res.push_back(ans) ;
            return ;
        }
        
        for(int i = 0 ; i < s.size() ; i ++){ 
            string left = s.substr(0, i + 1) ;
            string right = s.substr(i + 1 ) ;
            if(isPalindrome(left) ){
                ans.push_back(left) ;
                solve(right) ; 
                ans.pop_back() ;
            }
            
        }

    }
    vector<vector<string>> partition(string s) {
        int n =s.size () ;
        solve(s) ;
        return res ;
    }
};
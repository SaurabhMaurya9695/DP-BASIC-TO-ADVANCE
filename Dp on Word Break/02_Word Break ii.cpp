class Solution {
public:
    
    vector<string> ans ;
    void solve(int ind,string str,set<string> st , string s){
        if(ind==str.size()) 
        {
            ans.push_back(s.substr(0 , s.size() - 1));
            return ;
        }
        
        string temp="";
        for(int i = ind ; i<str.size() ;i++){
            temp += str[i];
            if(st.find(temp)!=st.end()){
                solve( i + 1 , str , st  , s + temp + " ");
            }
        }
        return ;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x:wordDict) st.insert(x);
        solve(0,s,st , "");
        
        return ans;
    }
};
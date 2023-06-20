// "applepenapple" , dict = {"apple","pen"} ; answere -> true
// make all pertitions and check whether the all partions is present in dict , if all predsent then
// return true else false 

// make a parttion if it is valid partition ..means it has to present in hashset 

// example

// catsanddog  {"cats" , "dog" , "cat" , "and" , "sand"}

// first we make all partition on c, ca, cat , cats , ..but we have to go further on 
// only valid partitions like cat and cats ..

//https://leetcode.com/problems/word-break/discuss/2557501/Fastest-solution-or-Detailed-explanation-or-Easy-understand


//time -> O(N * N);
// space -> O(N)

class Solution {
public:
    bool solve(int ind,string str,set<string> st,vector<int>& dp){
        if(ind==str.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        string temp="";
        for(int i=ind;i<str.size();i++){
            temp+=str[i];
            if(st.find(temp)!=st.end()){
                if(solve(i+1,str,st,dp)){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x:wordDict) st.insert(x);
        vector<int> dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};
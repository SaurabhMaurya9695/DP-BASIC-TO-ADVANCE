class Solution {
public:
    unordered_map<string,bool>mp;
    bool helper(string word,unordered_set<string>&st)
    {
        if(mp.find(word)!=mp.end())
        {
            return mp[word];
        }
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            // current prefix ko rakh lenge apne pass
            string prefix = word.substr(0,i+1);
            // current suffix ko rakh lenge apne paas
            string suffix = word.substr(i+1);
            // ab 2 cases hai jinme mein se ek bhi true hogaya toh hume answer mil jaayega:
            // case-1 : Agar hume current prefix mein milgaya hai toh hume ye check karna hoga ki kahin aesa toh nahi ki suffix jo hai woh bhi concatenated ho
            // case-2 : agar hume current prefix and curren suffix dono hamare words mein mil jaate hai
            if((st.find(prefix)!=st.end() && helper(suffix,st)) || (st.find(prefix)!=st.end() && st.find(suffix)!=st.end()))
            {
                return mp[word] = true;
            }
        }
        // agar current word ke liye koyi bhi prefix ya suffix present nahi hai hamare words mein toh iska matlab current word concatenated word nahi hai
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        unordered_set<string>st;
        vector<string>res;
        mp.clear();
        for(auto it:words)
        {
            st.insert(it);
        }
        for(int i=0;i<n;i++)
        {
            string word = words[i];
            if(helper(word,st))
            {
                res.push_back(word);
            }
        }
        return res;
    }
};
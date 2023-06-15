// brute force is : traverse and check whether it is has prime factorization of 2, 3 and 5 if yes then cnt ++ ;
// time complexity : o(n *sqrt(n));
// it is neither bfs or dfs 

//tabulation is much optimized in this code
class Solution {
public:
    int nthUglyNumber(int n) 
    {
        int dp[n + 1];
        dp[1] = 1;
        int p2 = 1 , p3 = 1 , p5 = 1;
        
        for(int i = 2 ; i<=n ; i++)
        {
            int p22 = 2 * dp[p2];
            int p33 = 3 * dp[p3];
            int p55 = 5 * dp[p5];
            int ans = min({p22 , p33 , p55});
            dp[i] = ans ;
            if(ans == p22) p2++;
            if(ans == p33) p3++;
            if(ans == p55) p5++;
        }
        // for(int  i = 1 ; i<= n ; i++)
        // {
        //     cout<< dp[i] << " ";
        // }
        return dp[n];
    }
};


class Solution {
public:
    
    void solve( set<long long> &s, long long num){
        if(num >=INT_MAX) return;
        if( s.find(num)!=s.end()) return;
        s.insert(num);
        solve(s, num*2);
        solve(s, num*3);
        solve(s, num*5);
    }
    int nthUglyNumber(int n) {
        set<long long> s;
        solve( s, 1);
        int ans =n;
        for( auto i: s){
            n--;
            if( n==0) ans = i;
        }
        return ans;
    }
};

// alsoo this question is done by using pq;
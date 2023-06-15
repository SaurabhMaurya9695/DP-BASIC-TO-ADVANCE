class Solution {
public:
    #define ll long long 
    int numTrees(int n) {
        // variation of catalan number ;
        vector<ll > catalan(n + 1 ) ;
        catalan[0] = 1;
        catalan[1] = 1;
        // to find nth catalan number 
        for(int i = 2 ; i <= n; i ++){
            for(int j = 0 ; j < i ; j ++){
                catalan[i] += catalan[j] * catalan[i - j - 1] ;
            }
        }
        return catalan[n];
    }
};
// greedy work here ,

//best time -> O(N) ;
// worst case -> O(N * N);

// for fail to greedy you just need a contradiction 

class Solution{
public:
    vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } ;
    vector<int> minPartition(int N)
    {
        // sort(coins.begin() , coins.end()) ;
        vector<int> ans ;
        for(int i = coins.size() -1 ; i>= 0 ; i--){
            
            while(N >= coins[i]){
                ans.push_back(coins[i]);
                N -= coins[i];
            }
            if(N == 0) break;
            
        }
        
        return ans ;
    }
};
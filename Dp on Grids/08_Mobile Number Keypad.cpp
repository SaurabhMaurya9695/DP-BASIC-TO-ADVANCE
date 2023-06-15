// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// for n == 1 , we can press any key 1,2,3....9; => 10 ways ignored * and # ;
// for n == 2 , we press again 1 then we can have to combination 11, 12, 14 , and for 22 , 21 , 23, 25
// for 3 =>  33 , 32, 36  
// for a generic n our ans is depend on n - 1 th key preessed 

// dfs(last key pressed , noOfKeysToBePressed) ;
// so it is a 2D dp question -> dp[last key pressed][noOfKeysToBePressed] ;

class Solution{

	public:
	#define ll long long 
	
	// For Each Key, store the neighbouring keys and the same key itself. 
	                        //   0          1              2              3          4 
    vector<vector<ll>> adj = { { 0, 8 }, { 1, 2, 4 }, { 1, 2, 3, 5 }, { 2, 3, 6 }, { 1, 4, 5, 7 },
                                { 2, 4, 5, 6, 8 }, { 3, 5, 6, 9 }, { 4, 7, 8 }, { 0, 5, 7, 8, 9 }, { 6, 8, 9 } };
                   
    ll dp[25][2501]  ;           
    ll dfs(ll lastKey , ll toBePressed){
        
        if(toBePressed == 0){
            return 1;
        }
        
        if(dp[lastKey][toBePressed] != -1){
            return dp[lastKey][toBePressed] ;
        }
        ll res = 0;
        for(auto neightbour : adj[lastKey]){
            res += dfs(neightbour , toBePressed - 1) ;
        }
        return dp[lastKey][toBePressed] = res ;
    }
	long long getCount(int n)
	{
	    memset(dp , -1 , sizeof(dp)) ;
	    ll ans = 0 ;
	    for(int i = 0 ; i < 10 ; i++){
	        ans += dfs(i , n-1) ;
	    }
	    
	    return ans ;
	}


};

// recursion time complexity :
// worst case ->  O(5 ^ H) ;
// memorization -> O( 0 -> 9 , 0 -> N-1) => OVERALL O(N*10) ;
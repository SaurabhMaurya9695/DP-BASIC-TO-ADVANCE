class Solution{
		

	public:
	int minDeletions(int arr[], int n) 
	{ 
	    vector<int>dp( n + 1 , 1) ; //minimum length of sorted subsequnce is 1 ;
	    for(int i = 0 ; i < n ; i ++){
	        for(int j = 0 ; j < i; j ++){
	            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
	                dp[i] = max(dp[i] , dp[j] + 1);
	            }
	        }
	    }
	    
	    int x =  *max_element(dp.begin() , dp.end()) ;
	    return  n - x ;
	} 
};
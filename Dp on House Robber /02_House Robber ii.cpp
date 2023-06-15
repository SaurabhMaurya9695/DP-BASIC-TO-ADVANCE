class Solution {
public:
    // 2 -> 3 -> 2 -> 3-> 2->3.....all are connected in a cyclic order ;
        // we can't choose two ajacent al a same time..
        // we know they are connected in a cyclic that's last and first element can't be        
        // chpoose at a same time
        //we can choose arr[0,......n-1] or arr[1........... n] ;
        //and take maximum ;
        // same as previous ;
        
        
    
    // using recursion ;
    int solve(int idx , vector<int> &arr)
    {
        if(idx == 0)
            return arr[0] ;
        if (idx < 0) 
            return 0;
        int pick = arr[idx] + solve(idx - 2 , arr) ;
        int npick = 0 + solve(idx -1 , arr);
        return max(pick , npick);
    }
    
    //using memorization;
    int solvememo(int index, vector<int> &nums, vector<int> &dp){
        if(index==0){
            return nums[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int pick = nums[index] + solvememo(index-2, nums, dp);
        int notpick = 0 + solvememo(index-1, nums, dp);
        return dp[index]=max(pick, notpick);
    }
    
    //tabulation
    int tab( vector<int>&nums , vector<int> &dp)
    {
        int n = nums.size();
        // vector<int> dp(n, -1);
        dp[0] = nums[0]; // base case initialization
        for (int i = 1; i < n; i++){
            int take = nums[i];
            if(i>1)
                take += dp[i - 2];
            int not_take = dp[i - 1];
            dp[i] = max(take, not_take);
        }
        return dp[n - 1];
        
    }
    
    int rob(vector<int>& arr)
    {
        int n = arr.size()  ;
        if(arr.size()==1){
            return arr[0];
        }
        vector<int> arr1;
        vector<int> arr2;

        for(int i=0; i<n; i++){

            if(i!=0) arr1.push_back(arr[i]);
            if(i!=n-1) arr2.push_back(arr[i]);
        }
        
        //recursion
        // long long int ans1 = solve(arr1.size() - 1 ,arr1);
        // long long int ans2 = solve(arr2.size() -1 , arr2);
        
        //memorization ;
        // vector<int> dp1(n + 1 , -1);
        // vector<int> dp2(n + 1 , -1);
        // long long int ans1 = solvememo(arr1.size() - 1 ,arr1 , dp1);
        // long long int ans2 = solvememo(arr2.size() -1 , arr2 , dp2);
        
        
        //tabulation
        vector<int> dp1(n  , -1);
        vector<int> dp2(n  , -1);
        long long int ans1 = tab( arr1 , dp1);
        long long int ans2 = tab( arr2 , dp2);

        return max(ans1,ans2);
        
    }
};
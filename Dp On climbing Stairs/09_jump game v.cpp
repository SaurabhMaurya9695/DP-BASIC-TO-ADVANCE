class Solution {
public:
    // TOP-DOWN DP APPROACH
    // helper function will calculate the maximum answer we can get from ith building(think of the array values as building blocks to easily understand the problem)
    int helper(vector<int> & dp, vector<int> &arr, int n, int d, int i) {
        // if it goes out of bound return the ans zero (though it won't go out of bound as it's taken care of next)
        if(i<0 or i>=n)
            return 0;

        // if the ans for that partucular building is already calculated return that ans
        if(dp[i] != -1) {
            return dp[i];
        }

        // The current building is already visited once so minimum possible ans is 1, so we initialized ans with 1;
        int ans = 1;

        // maximum d length of leap is allowed so we are taking the leaps of size 1, 2, 3... so on up to d in both the direction and get the maximum ans out of that
        // if a building taller then the current building is encounter the actor cannot go further then that so we won't be visiting the further buildings;


        // front direction
        for(int j=i+1; j<n and j<=i+d; j++) {
            if(arr[j] < arr[i]) {
                ans = max(ans, helper(dp, arr, n, d, j)+1);
            } else {
                break;
            }
        }
        // back direction
        for(int j=i-1; j>=0 and j>=i-d; j--) {
            if(arr[j] < arr[i]) {
                ans = max(ans, helper(dp, arr, n, d, j)+1);
            } else {
                break;
            }
        }
        // ofcourse, do not forget to memoize the ans, or everything you achieved so far will be for nothing;🥺
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;

        // try starting the process from every building and see where you get the maximum answer;
        for(int i=0; i<n; i++) {
            ans = max(ans, helper(dp, arr, n, d, i));
        }
        return ans;
    }
};

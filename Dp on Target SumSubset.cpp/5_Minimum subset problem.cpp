// method 1 -> using memorization only
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int dp[100][10000];
int solve1(vector<int> &arr,int sum1,int sum2,int idx ,int n)
{
    if(idx == n-1)
        return(abs(sum1-sum2));
    if(dp[idx][abs(sum1-sum2)]!=-1){
        return dp[idx][abs(sum1-sum2)];
    }

    int left = solve1(arr , sum1 - arr[idx] , sum2 + arr[idx] , idx + 1 , n) ;
    int right = solve1(arr, sum1 , sum2 , idx + 1 , n) ;
    return dp[idx][abs(sum1-sum2)] = min(left , right);
}
int Solution::solve(vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    int sum1 = 0;
    int sum2 = 0;
    int n = A.size();
    for(int i = 0 ;i < n ;i++)
    {
        sum1 += A[i];
    }
    return solve1(A , sum1 ,sum2 , 0 , n ) ;
}


//usign tabulation

int Solution::solve(vector<int> &arr) {
    int n = arr.size();

    int total = 0;
    for (int val : arr)
        total += val;

    // Check Target Sum Subset with Space Optimization:
    // Time - O(N * Target), Space - O(Target)

    vector<bool> dp(total + 1);
    dp[0] = true; // Empty Subset to form 0 total

    for (int i = 1; i <= n; i++) {
        vector<bool> newdp(total + 1);

        for (int j = 0; j <= total; j++) {
            bool no = dp[j]; // No Call
            bool yes = (j >= arr[i - 1]) ? dp[j - arr[i - 1]] : false;

            newdp[j] = no || yes;
        }

        dp = newdp;
    }

    // first fill the dp table ;
    // Extra Work for this Variation - O(Total) Time, O(1) Space
    int half = (total + 1) / 2;
    for (int s1 = half; s1 <= total; s1++) {
        if (dp[s1] == true) {
            return (s1 - (total - s1));
        }
    }

    return total;

}

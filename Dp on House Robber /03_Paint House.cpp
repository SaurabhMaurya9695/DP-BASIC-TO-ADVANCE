#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

// https://www.lintcode.com/problem/515/
// prev = 0 -> red 
// prev = 1 -> blue else green

int solve(ll n , vector<vector<int>> arr , ll idx , ll prev , vector<vector<int>> dp)
{

    if(idx == n){
        return  0;
    }

    if(dp[idx][prev] != -1){
        return dp[idx][prev];
    }

    int red , blue , green ;
    int ans ;
    if(prev == 0){
        blue  =   arr[idx][0] + solve(n , arr , idx + 1, 1 , dp);
        green =   arr[idx][1] + solve(n , arr , idx + 1, 2 , dp);
        red = INT_MAX;
        
    }
    else if(prev == 1){
        red   =   arr[idx][2]  + solve(n , arr ,idx + 1, 0 , dp);
        green =   arr[idx][1] + solve(n , arr , idx + 1, 2 , dp);
        blue = INT_MAX;
        // ans = min(red , green);
    }
    else if(prev == 2){
        red  =   arr[idx][2]  + solve(n , arr , idx + 1, 0 , dp);
        blue =   arr[idx][0]  + solve(n , arr , idx + 1, 1 , dp);
        green = INT_MAX;
        // ans = min(blue , red);
    }
    ans = min({blue , green , red});
    return dp[idx][prev] = ans ;
}

int main(){
    int n ;
    cin >> n ;
    vector<vector<int>> arr (n , vector<int> (3 )) ;
    for(auto &x : arr){
        for(auto &y : x){
            cin >> y;
        }
    }

    vector<vector<int>> dp(n , vector<int>(3 , -1));
    cout << solve(n , arr , 0 , -1 , dp)  << endl;
    // for(int i{}  ; i < n ; i ++){
    //     for(int j {} ; j < 3 ; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}


//tabulation is same as house robber ;



// tabulation o(N) , o(N)
#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

int main(){
    int n ;
    cin >> n ;
    vector<vector<int>> arr (n , vector<int> (3 )) ;
    for(auto &x : arr){
        for(auto &y : x){
            cin >> y;
        }
    }

    if(n == 0){
        return 0;
    }
    // vector<vector<int>> dp(n , vector<int>(3 , -1));
    // return solve(n , costs , 0 , 0 , dp); 

    int dp[n+1][3];
    dp[0][0] = arr[0][0] ;
    dp[0][1] = arr[0][1] ;
    dp[0][2] = arr[0][2] ;

    for(ll i = 1; i < n ; i ++){
        dp[i][1] = min(dp[i - 1][0] , dp[i-1][2]) + arr[i][1];
        dp[i][0] = min(dp[i - 1][1] , dp[i-1][2]) + arr[i][0];
        dp[i][2] = min(dp[i - 1][0] , dp[i-1][1]) + arr[i][2];
    }

    cout <<  min({dp[n-1][0] , dp[n-1][1] , dp[n-1][2] }) << endl;
    return 0;
}



//space optimixation space O(1) , time -> O(N)
#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

int main(){
    int n ;
    cin >> n ;
    vector<vector<int>> arr (n , vector<int> (3 )) ;
    for(auto &x : arr){
        for(auto &y : x){
            cin >> y;
        }
    }

    if(n == 0){
        return 0;
    }
    // vector<vector<int>> dp(n , vector<int>(3 , -1));
    // return solve(n , costs , 0 , 0 , dp); 

    int dp[n+1][3];
    int prev1 = arr[0][0] ;
    int prev2 = arr[0][1] ;
    int prev3 = arr[0][2] ;

    int curr1 , curr2 , curr3 ;

    for(ll i = 1; i < n ; i ++){
        curr2 = min(prev1 , prev3) + arr[i][1];
        curr1 = min(prev2 , prev3) + arr[i][0];
        curr3 = min(prev1 , prev2) + arr[i][2];

        prev1 = curr1 ;
        prev2 = curr2;
        prev3 = curr3;
    }

    cout <<  min({prev1 , prev2 , prev3 }) << endl;
    return 0;
}



`````````````````````````````````````````````````````````````````````````````````````````````````````````
                                //Java code
// 516. Lintcode: Paint House - II: https://www.lintcode.com/problem/516/

// Memoization - Time O(N * K * K) (Cubic), Space -> O(N * K) (Matrix + Recursion Stack)
// Runtime Error -> Stack Overflow -> N > 10^5
class Memoization {
    public int helper(int[][] costs, int idx, int k, int prev, int[][] dp) {
        if (idx == costs.length)
            return 0;
        if (prev >= 0 && dp[idx][prev] != -1)
            return dp[idx][prev];

        int min = Integer.MAX_VALUE;
        for (int color = 0; color < k; color++) {
            min = Math.min(min, (prev == color) ? Integer.MAX_VALUE
                    : costs[idx][color] + helper(costs, idx + 1, k, color, dp));
        }

        if (prev == -1)
            return min;
        return dp[idx][prev] = min;
    }

    public int minCostII(int[][] costs) {
        int n = costs.length;
        if (n == 0)
            return 0;

        int k = costs[0].length;

        int[][] dp = new int[costs.length + 1][k];
        for (int i = 0; i < costs.length; i++) {
            for (int j = 0; j < k; j++)
                dp[i][j] = -1;
        }

        return helper(costs, 0, k, -1, dp);
    }
}

// Tabulation -> Time O(N * K * K) (Cubic), Space -> O(N * K) (Matrix)
class Tabulation {
    public int minCostII(int[][] costs) {
        int n = costs.length;
        if (n == 0)
            return 0;

        int k = costs[0].length;

        int[][] dp = new int[costs.length + 1][k];
        for (int c = 0; c < k; c++) {
            dp[0][c] = costs[0][c];
        }

        for (int i = 1; i < n; i++) {
            for (int c = 0; c < k; c++) {
                int min = Integer.MAX_VALUE;

                // Extracting Min of Previous Row Excluding Our Column
                for (int prev = 0; prev < k; prev++) {
                    if (prev == c)
                        continue;
                    min = Math.min(min, dp[i - 1][prev]);
                }

                dp[i][c] = costs[i][c] + min;
            }
        }

        int min = Integer.MAX_VALUE;
        for (int c = 0; c < k; c++) {
            min = Math.min(dp[n - 1][c], min);
        }
        return min;
    }
}

// Time -> O(N * K) (Quadratic), Space -> O(N * K) (Matrix)
class TimeOptimization {
    public int minCostII(int[][] costs) {
        int n = costs.length;
        if (n == 0)
            return 0;

        int k = costs[0].length;

        int[][] dp = new int[costs.length + 1][k];
        for (int c = 0; c < k; c++) {
            dp[0][c] = costs[0][c];
        }

        for (int i = 1; i < n; i++) {

            // Finding 1st Min and 2nd Min of Previous Row
            int firstMin = Integer.MAX_VALUE;
            int secondMin = Integer.MAX_VALUE;
            for (int prev = 0; prev < k; prev++) {
                if (dp[i - 1][prev] <= firstMin) {
                    secondMin = firstMin;
                    firstMin = dp[i - 1][prev];
                } else if (dp[i - 1][prev] < secondMin) {
                    secondMin = dp[i - 1][prev];
                }
            }

            // Calculating Current Row DP Using 1st Min and 2nd Min
            for (int c = 0; c < k; c++) {
                if (dp[i - 1][c] == firstMin)
                    dp[i][c] = costs[i][c] + secondMin;
                else
                    dp[i][c] = costs[i][c] + firstMin;
            }
        }

        int min = Integer.MAX_VALUE;
        for (int c = 0; c < k; c++) {
            min = Math.min(dp[n - 1][c], min);
        }
        return min;
    }
}

// Space Optimization: Time -> O(N * K) (Quadratic),
// Space -> O(K) (Linear Array)
class SpaceOptimization {
    public int minCostII(int[][] costs) {
        int n = costs.length;
        if (n == 0)
            return 0;

        int k = costs[0].length;

        int[] dp = new int[k];
        for (int c = 0; c < k; c++) {
            dp[c] = costs[0][c];
        }

        for (int i = 1; i < n; i++) {

            int firstMin = Integer.MAX_VALUE;
            int secondMin = Integer.MAX_VALUE;
            for (int prev = 0; prev < k; prev++) {
                if (dp[prev] <= firstMin) {
                    secondMin = firstMin;
                    firstMin = dp[prev];
                } else if (dp[prev] < secondMin) {
                    secondMin = dp[prev];
                }
            }

            int[] curr = new int[k];

            for (int c = 0; c < k; c++) {
                // Extracting Min of Previous Row Excluding Our Column
                if (dp[c] == firstMin)
                    curr[c] = costs[i][c] + secondMin;
                else
                    curr[c] = costs[i][c] + firstMin;
            }

            dp = curr;
        }

        int min = Integer.MAX_VALUE;
        for (int c = 0; c < k; c++) {
            min = Math.min(dp[c], min);
        }
        return min;
    }
}
class Solution {
public:

    // time complexity : to fill dp table N * N and to iterate on sticks N ;
    // overall O(N ^ 3)
    int dp[101][101];
    int solve(int start_stick, int end_stick, vector<int>& cuts, int left, int right){
        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int cost = 1e9;
        
        for(int i=left; i<=right; i++){ // make all the possible cuts from left to right
            int left_cost  =  solve(start_stick, cuts[i], cuts, left, i-1); // left sub problem 
            int right_cost =  solve(cuts[i], end_stick, cuts, i+1, right);  // right sub problem 
            int current_cost = (end_stick - start_stick) ; // total cost 
            int curr_cost  =  current_cost  + left_cost + right_cost; 
            cost = min(cost,curr_cost);
        }
        
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        // if we didn't sort then the left problem is depend on right problem 
        // 1 3 5 2 .. if we make cut at 5 then left problem is 1 3 5 and right sub problem is 2
        // you can obseve here right sub_problem is a part of left , so we need to sort to 
        // avoid these types of subproblems 

        // you can add 0 at the begenning of the array and length last of the array 
        // Or  directly pass on function here
        return solve(0, n, cuts, 0, cuts.size()-1);
    }
};
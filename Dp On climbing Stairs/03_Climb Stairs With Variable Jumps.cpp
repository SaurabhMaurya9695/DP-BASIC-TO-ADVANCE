#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> arr , int idx , vector<int> dp )
{
    if(idx >= arr.size()){
        return 1; 
    }
    
    if(dp[idx] != -1){
        return dp[idx];
    }
    int ans  = 0 ;
    for(int i = 1; i <= arr[idx] ; i++){ // make all possible jumps from stairs idx 
        if(idx + i <= arr.size()) // if possible to jump them jump;
            ans += solve(arr , idx + i , dp); // make faith on next 
    }

     dp[idx] = ans ;
     return ans;
}

int main(){
    int n ;
    cin >> n ;
    vector<int > arr (n);
    for(auto &x : arr){
        cin >> x;
    }

    vector<int> dp (n + 1 , - 1);
    cout <<solve(arr , 0 , dp)  << endl;
}

```````````````````````````````````````````````````````````````````````````````````````````````````
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n ;
    cin >> n ;
    vector<int > arr (n);
    for(auto &x : arr){
        cin >> x;
    }

    // tabulation 
    // smaller problem is finding the nth and larger is finding the 0th ;
    int dp[n + 1] ;
    dp[n ] = 1; // base case , only one way is there ;
    // going from smaller to larger ;
    for(int cell = n - 1; cell >= 0 ; cell --){
        // jump always forwards
        int ans = 0;
        for(int j = 1 ; j <= arr[cell] ; j ++){
            if(cell + j <= n) // possible to make jump forward then make 
            {
                ans += dp[cell + j];
            }
        }
        dp[cell] = ans ;
    }

    cout << dp[0] << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 

//6
// 10 -> 22 -> 33 -> 41 -> 60 -> 80
// 10 -> 22 -> 33 -> 50 -> 60 -> 80


//time complexity -> o(n*n) {to fill dp} + o(NumberOfSoultions * N) ;
vector<int> LISDP(vector<int>& arr) {
    int n = arr.size() ;
   vector<int> dp (n  , 1);
    for(int i = 0 ; i < n ; i ++) // for every idx;
    {
        for(int j = 0 ;j < i ; j ++){ 
            if(arr[i] > arr[j] ){ 
                dp[i] = max(dp[i] , dp[j] + 1) ; 
            }
        }
    }
    
    
    return dp ;
}

void solve(int n , vector<int> arr){
    vector<int> dp = LISDP(arr) ;
    
    // find the  maxLIS and its idx ;
    int maxi = INT_MIN ;
    int idx = 0;
    for(int i = 0; i< dp.size() ; i ++){
        if(dp[i] > maxi){
            maxi =  dp[i];
            idx = i ;
        }
    }

    cout << maxi  << endl;

    // we have to enter all the values from where we can create 
    // LIS ,we can from more than 1 LIS from same length 


    //normal example ->
    // 9
    // 10 22 9 33 21 50 41 60 80 

    // Theeka example ->

    // 9
    // 10 22 43 33 21 50 41 60 59 3 

    // for theeka example this is the solution : 
    queue<pair< pair<int,int> , pair<int,string> >>  q;
    for(int i = 0 ;i < n ; i ++){
        if(dp[i] == maxi){
            q.push({  {dp[i] , i} , {arr[i] ,  to_string(arr[i])}  });
        }
    }

    while(!q.empty()){
        pair< pair<int,int> , pair<int,string> > ap  = q.front();

        int val = ap.first.first ; // 6
        int idx = ap.first.second; // 8
        int valAtidx = ap.second.first ;  // 80
        string ans = ap.second.second ; // 80 as a string 

        q.pop();

        if(idx == 0){
            cout << ans << endl;
        }

        //check from 0 to idx 
        for(int j = idx - 1 ; j >= 0 ; j --){
            if(dp[j] == val - 1  && arr[j] < arr[idx]){
                q.push({{dp[j] , j} ,{arr[j] , ans + " -> " + to_string(arr[j])}});
            }
        }
    }


    
}


int main()
{
    int n ;
    cin >> n ;
    vector<int> arr (n) ;
    for(auto & x : arr){
        cin >> x;
    }
    solve(n , arr );

}


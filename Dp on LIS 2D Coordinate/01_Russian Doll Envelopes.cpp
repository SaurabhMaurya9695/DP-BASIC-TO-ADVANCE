// 1 - this is noting but , question based on merge interval type ;
// 2 - sort on 1st coordinate and use LIS on second coordinate ;

class Solution {
public:

    // time -> O(n * n + nlogn) ; space -> O(N ) ;
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size() ;
        // sort based on the height 
        sort(arr.begin() , arr.end() , [&](vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
        
        // we know , our height is already sorted ;
        // then use LIS on width only and you'll get the ans ;
        vector<int> dp( n + 1, 1) ; // Minimum Length of LIS ;
        int maxLIS = 1;
        for(int i = 1; i < n ; i ++){
            for(int j = 0 ; j< i ; j ++){
                if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]){
                    dp[i] = max(dp[i] , dp[j] + 1) ;
                }
            }
            
            maxLIS = max(maxLIS , dp[i]) ;
        }
        
        
        return maxLIS  ;
    }
};



class Solution {
public:
    // time -> O(nlogn + nlogn) , space -> O(MAXLIS Length) ;
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size() ;
        sort(arr.begin() , arr.end() , [&](vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
        
        // we know , our height is already sorted ;
        // then use LIS on width only and you'll get the ans ;
        vector<int>LIS;
        for(int i =0;i< n;i++)
        {
            if(LIS.empty() || LIS.back() < arr[i][1]) // if we are adding at the end 
                LIS.push_back(arr[i][1]); // then add that 
            else
            {
                int index = lower_bound(LIS.begin(),LIS.end(),arr[i][1])
                        -   LIS.begin();
                LIS[index] = arr[i][1]; // or add that value at that perfect idx 
            }
        }
        
        return LIS.size();
    }
};
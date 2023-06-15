class Solution {
protected :
    static bool cmp(vector<int> a , vector<int> b){
        if(a[0] == b[0]){
            if(a[1] == b[1]){
                if(b[2] > a[1]){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(b[1] > a[1]){
                return true;
            }
            else{
                return false;
            }
        }
        else if(b[0] > a[0]){
            return true;
        }
        return false;
    };
public:
    
    int maxHeight(vector<vector<int>>& arr) {
        int n = arr.size() ;
        for(int i = 0 ; i< n ; i++){ 
            sort(arr[i].begin(),arr[i].end()) ;
        }
        
        sort(arr.begin() , arr.end() , cmp);
        
        // then make LIS on height
        vector<int> dp(n + 1 , 1);
        for(int i = 0 ; i < n ; i ++){
            dp[i] = arr[i][2];
            for(int j = 0; j< i ; j++){
                //follow the condition 
                if(arr[i][1] >= arr[j][1] && arr[i][0] >= arr[j][0] && arr[i][2] >= arr[j][2])
                {
                    if(dp[j] + arr[i][2] > dp[i]){
                        dp[i] = max(dp[i] ,dp[j] + arr[i][2] ) ;
                    }
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end()) ; // find the maximum sum of LIS
    }
};
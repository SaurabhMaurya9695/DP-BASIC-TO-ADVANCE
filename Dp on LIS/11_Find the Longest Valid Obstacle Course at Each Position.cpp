class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        //time -> O(n * n) -> this will give TLE in 10^5 ,
        // we can go for BS ;
        
        // this is the variation of LIS
        int n = arr.size() ;
        vector<int>ans(n , 1); // minimum one length obsracle present at this idx
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < i ; j ++){
                if(arr[i] >= arr[j]){
                    if(ans[j] + 1 >= ans[i]){
                        ans[i] = max(ans[i] , ans[j] + 1) ;
                    }
                }
            }
        }
        return ans ;
    }
};


// we have to optimized it 
                //time complexity : o(n * logn) ;
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>ans(n, 1), lis;

        for (int i = 0; i < n; i++) {
            int idxToInsert = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if (idxToInsert == lis.size()) { // inserting at the end ;
                lis.push_back(obstacles[i]);
            }
            else {
                lis[idxToInsert] = obstacles[i]; //
            }
            ans[i] = idxToInsert+1; // add in ans , on which idx we inserted
        }
        return ans;
    }
};


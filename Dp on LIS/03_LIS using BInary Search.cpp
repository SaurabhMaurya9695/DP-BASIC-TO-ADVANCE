// this is LIS using BS , concept is same not this code 
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
class Solution {
public:


    //time -> o(n) , space -> o(n);
    int longestMountain(vector<int>& nums) {
        int n = nums.size() ;
        // Longest increasing subarray ending at index i
        vector<int> prefix(n , 1); // minimum length of subarray is 1
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                prefix[i] = prefix[i - 1] + 1;
            }
        }


        vector<int> suffix(n , 1);  // minimum length of subarray is 1
        // Longest decreasing subarray starting at index i
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
            }
        }

        
        // Longest Bitonic Subarray = LIS + LDS - 1
        int ans = 0;
        for (int i = 0; i < n ; i++) {
            if (prefix[i] > 1 && suffix[i] > 1) {
                ans = max(ans , prefix[i] + suffix[i] - 1);
            }
        }

        return ans;
    }
};

// Sliding window

class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        int ans=0;
        int n=arr.size();
        for(int i=1;i<arr.size()-1;i++)
        {
            //treating every element as a peak;
            int start=i;
            int end=i;
            
            //before exploring first check whether exist in left or right 
            //then go in left deep and right deep ;
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            {
                // go till start exist
                while(start>0&&arr[start]>arr[start-1]){
                    start--;
                }
                
                // go till end exist
                while(end<n-1 &&arr[end]>arr[end+1]){
                    end++;
                }
                
                ans=max(end-start+1,ans); // our length our mountain is end-start+1
                end=end+1; // already calculated for start ..check kro end now 
            }
        }
        return ans;
    }
};
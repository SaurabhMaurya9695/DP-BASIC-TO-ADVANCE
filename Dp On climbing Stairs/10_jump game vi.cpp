// class Solution {
// public:             
                // Recursion  -> TLE
    // int ans = -10001;
    // int solve(int curr_idx , vector<int> arr , int k )
    // {
    //     if(curr_idx >= arr.size()  ) 
    //     {
    //         return ans;
    //     }
    //     if(curr_idx == arr.size() - 1 ) return arr[curr_idx] ; 
    //     int score = ans;
    //     // make a possible steps;
    //     for(int i= 1; i<= k ; i++)
    //     {
    //         score = max(score , arr[curr_idx] + solve(curr_idx + i , arr , k )) ;
    //     }
    //     return score ;
    // }

    
                    // Memorization -> MEMORY Limit
//     int ans =  -10000*100000 + 1;;
//     int solve(int curr_idx , vector<int> arr , int k , vector<int>&dp )
//     {
//         if(curr_idx >= arr.size()  ) 
//         {
//             return ans;
//         }
//         if(curr_idx == arr.size() - 1 ) return arr[curr_idx] ; 
//         if(dp[curr_idx] != -1) return dp[curr_idx];
//         int score = ans;
//         // make a possible steps;
//         for(int i= 1; i<= k ; i++)
//         {
//             score = max(score , arr[curr_idx] + solve(curr_idx + i , arr , k  , dp)) ;
//         }
//         return dp[curr_idx] = score ;
//     }
    
//     int maxResult(vector<int>& arr, int k) {
//         vector<int> dp(arr.size() + 1 , -1);
//         return solve(0 , arr , k , dp);
//     }
    
    
// };
    
    
    
    
    
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        long curr=0;
        deque<int> dq;     		// Monoqueue
		
		// Start answering the best possible results for index `i` from the back
        for(int i=nums.size()-1;i>=0;i--)
        {
            curr=nums[i]+(dq.empty()?0:nums[dq.front()]);       // Get current best, the maximum result will be the first element in the monoqueue.
			
			// We remove all the smaller results greedily as they wont get used anyways (This helps the monoqueue to remain sorted)
            while(!dq.empty()&&curr>nums[dq.back()])
                dq.pop_back();	
            dq.push_back(i);              // Insert current index into the monoqueue
			
			// Erase all the indices in deque that are greater than or equal to i+k.
            if(dq.front()>=i+k)
                dq.pop_front();
            nums[i]=curr;               // Use input array as auxillary array to store the best results.
        }
        return curr;                           // `curr` would have the best or the maxium result to reach end from index 0.
    }
    
};
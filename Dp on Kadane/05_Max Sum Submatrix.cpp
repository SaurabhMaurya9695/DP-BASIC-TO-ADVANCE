// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

// brute force apply kadane in each row  and each column ;
// there are n * (n + 1) / 2 * (m * (m + 1) / 2) sub matrix avaialble ;
//  so overall coplexity is O(N ^ 4)


// better approach 
// apply prefix sum on all row  and kadane on coloumns 
// time -> O(n * (n + 1) / 2 * m ) ;
// (n * (n + 1) / 2 ) -> submatrix and m times kadane 

class Solution {
  public:
  
    
    int maximumSumRectangle(int n, int m, vector<vector<int>> arr) {
        
        auto kadane = [&](vector<int> &temp){
            int curr_sum = temp[0] ;
            int overall_sum = temp[0] ;
            for(int i = 1 ; i< temp.size() ; i ++){
                if(curr_sum >= 0){
                    curr_sum += temp[i]; 
                }
                else{
                    curr_sum = temp[i] ;
                }
                
                overall_sum = max(overall_sum , curr_sum);
            }
            
            return overall_sum;
        };
        // code here
        int ans = INT_MIN ;
        for(int i = 0 ; i < n ; i ++){ // for n * (n + 1) / 2 submatrixes 
            vector<int> pref (m ) ;
            for(int j = i ;  j< n ; j ++){ // for jth row
                for(int val = 0 ; val < m ; val ++){
                    pref[val] += arr[j][val] ;
                }
                ans = max(ans , kadane(pref)) ;
            }
            
        }
        
        return ans ;
    }
    
    
};



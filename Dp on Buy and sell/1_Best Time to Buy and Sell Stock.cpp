
//brute force -> o(N * N) ;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j] - prices[i] > maxProfit){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};

 
//greedy  time -> O(N) , space -> O(1);
class Solution {
public:

    // we have to ask our ans from the minimum dip ;

    int maxProfit(vector<int>& price) {
        // we get our ans from the minimum buy values
        int leastSoFar = INT_MAX;
        int n = price.size();
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(leastSoFar > price[i]){
                leastSoFar = price[i] ;
         
            }
            // now we have to find the ans with leastSoFar 
            if(ans < price[i] - leastSoFar){
                ans = price[i] - leastSoFar ;
            }
        }
        return ans;
    }
};


//Time -> O(N) , space -> O(N);

//Method 2  ->using prefix and suffix
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<int> suff(n);
        vector<int> pref(n);
        int minn = INT_MAX;
        int maxx = INT_MIN;

        for(int i=0 ; i<n ; i++){
            minn = min(minn , arr[i]);
            pref[i] = minn;
        }

        for(int i=n-1 ; i>=0 ; i--){
            maxx = max(maxx , arr[i]);
            suff[i] = maxx;
        }

        
        int ans = 0;
        for(int i=0 ; i<n-1;i++){
            ans = max(ans , suff[i+1]-pref[i]);
        }


        return ans;
    }
};

//approach 4 -> finding max from suffix ;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxPrices(n, 0);
        maxPrices[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            maxPrices[i] = max(maxPrices[i+1], prices[i]); 
        }
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, maxPrices[i] - prices[i]); 
        }
        return maxProfit;
    }
};

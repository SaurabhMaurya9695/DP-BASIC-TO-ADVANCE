// question states that n >= 3 ;
// we have to form a longest subsequence with a common differnce ;
// from every idx we can start a new subsequence or we can continue a previous subsequence ;
// to continue prev subsequence you must insure that your common difference should be same ;
// for every subsequence differnce can be differnt , so with the current idx val - previous idx value 
// differnce is same then increase its value otherwise we can start a new subsequence from that point

// this is a question of 2D dp , where 1 state is idx and other state is difference ;
// but for second state we can use matrix because our matrix can contain negative value 
// to avoid this we can use hashMap 

// logic is best our code is small ;

class Solution {
public:
    #define ll long long 

    //time -> O(n * n) , space - > O(1);
	int numberOfArithmeticSlices(vector<int>& a) {
		ll ans = 0, n = a.size();
		vector<unordered_map<ll, ll>> dp(n); //declare a map of array 
        // every idx contain map 
		for (int i = 0; i < n; ++i) { // for every i
			for (int j = 0; j < i; ++j) { // asking from behind 
				ll diff = (ll)a[i] - (ll)a[j]; // taking a differnce 

				dp[i][diff]++; // increase the count of ith value 
				if (dp[j].count(diff)) { // check whether with the same differnce
                    // any value present on j 
                    // if present then add that count on ans 
                    // and including that value make ith value 
					dp[i][diff] += dp[j][diff];
					ans += dp[j][diff];
				}
                
			}
		}
		return ans;
	}
};


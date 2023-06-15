// if coins are {2 , 3 , 7}  target = 8  ;
// if we go greedy then 8 - 7  = 1 , but one is not present in things . so our ans exist if we choose
// 2 * 4times or  (3 + 3 + 2) then our exits , it shows greedy fails ;
// this is 1D dp ... our ans is dependet on sum only ;

                    //coins on level
                    //Time : O(Amount * coins );
                    //space : O(Amount);
class Solution {
public:
    int memo(int amount, vector<int>& coins, int dp[]) {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];

        int minCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                minCoins = min(minCoins, memo(amount - coins[i], coins, dp));
            }
        }

        if (minCoins < INT_MAX)
            minCoins += 1;
        return dp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        ll n = coins.size() ;
        int dp [amount + 1]; 
        memset(dp , -1 ,sizeof(dp)) ;
        int ans = memo(amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

//```````````````````````````````````````````````````````````````
// printing all combinations

void solve(  vector<ll>coins , ll target  , string res)
{   
    if(target == 0){
        cout << res << endl;
        return ;
    }
    if(target < 0){
        return ;
    }
    
    for(ll i = 0; i < coins.size() ; i ++){
        // we have to every choice  ;
        solve( coins , target - coins[i] , res + to_string(coins[i])) ;

    }
}
 
int main()
{
    fast;
    ll n ;
    cin >> n ;
    vector<ll> coins = readvector(n) ;
    ll target ;
    cin >> target ;
    string res ;
    solve(coins , target , res);
    return 0;

}


// our stack is dependent on heights .. so see the second method giving x no of coins to every index ;
// {2 , 3 , 7}  target = 8  ;

// if(we given target 8 
//(no_choice of two) (2^1) (2^2) (2 ^ 3) 
// if we give no choice then ans is itsef 8
// if we give one two then target is 6
// if we give two two then target is 4
// if we give three ^ two then target is  0 
// here we find our ans on level , we don't have to go in deep to find ans ;

// this is much optimized then before and here the less number of chances to be stack overflow

class Solution {
public:
    #define ll long long 
    
    //time & space -> O(amount * coins)
    ll memo(ll amount, ll idx, vector<int>& coins , vector<vector<ll>> dp) {
        if (amount == 0)
            return 0ll;
        if (idx == coins.size())
            return LONG_MAX;
        if (dp[amount][idx] != -1)
            return dp[amount][idx];

        ll minCoins = LONG_MAX;
        for (ll coin = 0; amount >= coins[idx] * coin; coin++) {
            ll ans = memo(amount - coins[idx] * coin, idx + 1, coins, dp);
            if (ans < LONG_MAX)
                ans += coin;
            minCoins = min(minCoins, ans);
        }

        return dp[amount][idx] = minCoins;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<ll>> dp(amount + 1 , vector<ll>(coins.size() + 1 , -1)) ;
        ll ans = memo(amount , 0 , coins , dp);
        return ( ans == LONG_MAX) ? -1 : (int)ans  ;
    }
};

// approach 3 ->
class Solution {
public:
    #define ll long long 
    
    ll memo(ll amount, ll idx, vector<int>& coins , vector<vector<ll>> dp) {
        if(idx == coins.size()){
            return INT_MAX;
        }
        
        if (amount == 0)
            return 0;
        
        if(amount < 0){
            return INT_MAX ;
        }
        
        if(dp[amount][idx] != -1){
            return dp[amount][idx];
        }
        // we have two options to take or not take ;
        // if  we take then we can choose one coins multiple times ;
        int yes = (amount -coins[idx] >=0) ?memo(amount -coins[idx] , idx , coins , dp) : INT_MAX;
        if(yes != INT_MAX){
            yes += 1;
        }
        int no = memo(amount  , idx  + 1 , coins , dp);
        return dp[amount][idx] = min(yes, no) ;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<ll>> dp(amount + 1 , vector<ll>(coins.size() + 1 , -1)) ;
        ll ans = memo(amount , 0 , coins , dp);
        return ( ans == INT_MAX) ? -1 : (int)ans  ;
    }
};

// working solu
class Solution {
public:
    int help(vector<int>& coins, int amount, int n,vector<vector<int>>&h)
    {
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;
        if(h[n][amount]!= -1) return h[n][amount];
        int one = help(coins,amount,n-1,h);
        int two = 1+help(coins,amount-coins[n],n,h);
        h[n][amount] = min(one,two);
        return h[n][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>h(coins.size()+1,vector<int>(amount+1,-1));
        int ans = help(coins,amount,coins.size()-1,h);
        return (ans < INT_MAX-1)?ans:-1;
    }
};

//tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // no way to create amount 
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) { // check for all coins
                if (i >= coin && dp[i - coin] != INT_MAX) { // that cell doesn't has the value INT_MAX then do
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
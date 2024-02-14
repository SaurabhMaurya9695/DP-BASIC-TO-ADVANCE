#include <bits/stdc++.h>
using namespace std;
/*
 *    coder :: Saurabh Maurya
 *        >>> INDIA <<<
 */
#define sz(x) (int)(x).size()
#define ll long long
#define ff first
#define ss second
#define minheap priority_queue<long long, vector<long long>, greater<long long>>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define PI 3.14159265358979323846
#define mod 1000000007
#define maxelement(nums) *max_element(nums.begin(), nums.end());
#define minelement(nums) *min_element(nums.begin(), nums.end());
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define lb lower_bound
#define ub upper_bound
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
// template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k)   returns count of elements strictly smaller than k;

// Debug
#define d1(x) cout << #x << ": " << x << endl
#define d2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl
#define d3(x, y, z) cout << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define d4(a, b, c, d) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define d5(a, b, c, d, e) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define d6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl

// movement in grid -> 2 d
const int x8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int y8[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int x4[4] = {1, -1, 0, 0};
const int y4[4] = {0, 0, -1, 1};

// always think for n == 1 , n == 0
// in 1 sec we can do 10^7
// if choices given think for dp or memorization
// read the question again , question is giving us the clue ;
// if you have to find number of ways then think for pnc and dp .
// in ways type of question start dry run from n : 0 ,1, 2 ... n and find
// the rec relation

class Solution
{
public:
    /*
    Let's say we have n elements in our permutation then Depending on where we put the element (n+1) in our permutation, we may add 0, 1, 2, ..., n new inverse pairs. For example, if we have some permutation of 1...4, then:

    5 x x x x creates 4 new inverse pairs
    x 5 x x x creates 3 new inverse pairs
    ...
    x x x x 5 creates 0 new inverse pairs
    */

    /*if I have an array with size n and k inverse pairs, what will happend if I add an extra element (n + 1) which is greater than all of n elements?
    Approach 
    1 - If I add the (n + 1) at the end (position n+1) -> then the number of inverse pairs will remains the same
    2 - If I add the (n + 1) at (position n) -> then the number of inverse pairs will increase by one
    3 - If I add the (n + 1) at (position n-1) -> then the number of inverse pairs will increase by two
    .
    .
    .
    .
    4 - If I add the (n + 1) at (position 0) -> then the number of inverse pairs will increase by n
    So :
    let dp[i][j] represent the number of arrays with i elements and j inverse pairs

    This value dp[i][j] should be added to dp[i+1][k]
    where k is from j to j + i (Push DP)

    Why? Because extra element of n has the same value of the previous n but with extra range of inverse pairse from 0 to n.

    Finally we can't add this value by a for loop -> TLE
    So we can make a partial sum optimization on the dp -> Look at the code
    */

   // changing state is k & n so 
   
   int dp[1001][1001];
   int solve(int n , int k){
        if(n == 0){
            return 0; // we don't have any size to calculate any inversion 
        }

        if(k == 0){
            return 1;
        }

        if(dp[n][k] != -1){
            return dp[n][k];
        }

        // we are trying to find inversion
        int totalInversions = 0;
        for(int i = 0; i <= min(n-1, k); i++) {
            totalInversions = (totalInversions % mod + solve(n-1, k-i) % mod);
        }

        return dp[n][k] = totalInversions % mod;
   }

    int kInversePairs(ll n, ll k)
    {
        fast;
        memset(dp , -1,sizeof(dp));
        return solve(n , k);
    }
};
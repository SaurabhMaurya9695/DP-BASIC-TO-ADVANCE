#include<bits/stdc++.h>
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
#define all(x) (x).begin() , (x).end()
#define sortarr(arr, n) sort(arr, arr + n);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define PI 3.14159265358979323846
#define mod 1000000007
#define print(v)                       \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }
#define maxelement(nums) *max_element(nums.begin(), nums.end());
#define minelement(nums) *min_element(nums.begin(), nums.end());
#define py "Yes"
#define debug(x) cout << #x << " " << x << endl;
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
 
// movement in grid -> 2 d
const int x8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int y8[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int x4[4] = {1, -1, 0, 0};
const int y4[4] = {0, 0, -1, 1};

template <class T>
vector<T> readvector(T n)
{
    vector<T> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}
template <class T>
void debugst(set<T> &st)
{
    for(auto x : st)
    {
        cout<< x << " ";
    }
    cout<< endl;
}
template <class T>
void debugv(vector<T> &arr)
{
    for(auto x : arr)
    {
        cout<< x << " ";
    }
    cout<< endl;
}

// always think for n == 1 , n == 0 
// in 1 sec we can do 10^7
// if choices given think for dp or memorization 
// read the question again , question is giving us the clue ;
// if you have to find number of ways then think for pnc and dp .
// in ways type of question start dry run from n : 0 ,1, 2 ... n and find
// the rec relation 

ll dp[4001] ;
ll solve(ll n, ll a , ll b , ll c)
{
	if(n < 0){
		return -1e9;
	}

	if(n == 0){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n] ;
	}
	
    // cut of a size ;

    ll x = 1 + solve(n - a , a , b , c) ;
    ll y = 1 + solve(n - b , a , b , c) ;
    ll z = 1 + solve(n - c , a , b , c) ;

    return dp[n] = max({x,y,z}) ;

}
 
int main()
{
    fast;
    ll t = 1;
    // cin >> t;
    while(t--)
    {
    	memset(dp ,-1 ,sizeof(dp));
    	ll n , a, b , c ;
    	cin >> n >> a >> b >> c;

        cout << solve(n , a,  b, c) << endl;
        return 0;
    }
}


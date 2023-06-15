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
// #define sort(a) sort(a.begin(), a.end())
#define sortarr(arr, n) sort(arr, arr + n);
#define all(x) (x).begin(),(x).end()
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
#define pn "No"
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

// movement in grid -> 2 d
const int x8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int y8[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int x4[4] = {1, -1, 0, 0};
const int y4[4] = {0, 0, -1, 1};

// inline ll Div(ll a, ll b, ll m = mod)
// {
//     return ((a % m) * power(b, m - 2ll, m)) % m;
// }

template <class T>
vector<T> readvector(T n)
{
    vector<T> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}

// gcd
ll gcd(ll a, ll b) // TC = O(log n)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// fibonacci of nth no .
ll fib(ll n)
{
    double phi = (1 + sqrt(5)) / 2;
    return (ll)round(pow(phi, n) / sqrt(5));
}

// check whether the no is prime or not.
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int toconvert(int n, int d)
{
    int ans = 0;
    int cnt = 0, rem = 0;
    while (n != 0)
    {
        rem = n % d;
        int c = pow(10, cnt);
        ans += rem * c;
        n /= d;

        cnt++;
    }
    return ans;
}

int power(ll x, int n, int m = mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}
int INV(int x, int m = mod)
{
    return power(x, m - 2, m);
}

bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return false;
        }
    }

    return true;
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

bool sign(ll X)
{
    return abs(X) == X;
}

// c=134217727; always gives &with same no
// cout<<fixed<<setprecision(9)<<ans<<"\n";

// `````````````````````````````````````Code Begins`````````````````````````````````````````

void solve()
{
    ll n ;
    cin >> n ;
    vector<ll > arr = readvector(n);
    unordered_map<ll ,ll > mp ;
    for(auto &x : arr) mp[x]++;
    for(auto &[l , r] : mp){
        if(r >= 3){
            cout << l << endl;
            return ;
        }
    }

    cout << -1 << endl;
    return ;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    // kicstart
    // for(int i =0; i < t ; i++)
    // {
    //     cout<<"Case #"<<i+1<<": ";
    //     solve();
    // }

    return 0;
}

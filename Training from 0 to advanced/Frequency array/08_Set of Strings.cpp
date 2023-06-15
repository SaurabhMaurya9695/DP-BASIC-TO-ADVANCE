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

void solve()
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    set<char > st;
    for(auto x : s ) st.insert(x) ;
    if(sz(st) < k){ // all distinct then we can't divide them in n groups ;
        cout << "NO\n";
        return ;
    }
    if( k == 1){
        cout << "YES\n" << s << endl;
        return ;
    }

    map<char, int>mp;
    string build = "";
    vector<string>v;
    for (int i = 0; i < s.size(); i++) {
        if (!mp[s[i]] && k > 0) { // if it is not present in map && k > 0 , till then we have one build string  
            if (build.size() > 0) // if that string sz is > 0 
                v.push_back(build); // add in ans ;
            k--; // decrease one operation
            build = ""; // and build="";
        }
        build += s[i];
        mp[s[i]]++;
    }
    v.push_back(build);

    if( !k){
        cout <<"YES\n";
        for(auto x : v){
            cout << x << "\n";
        }
        cout << endl;
    }
    else{
        cout <<"NO\n";
        return ;
    }
    return ;

}
 
int main()
{
    fast;
    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
 
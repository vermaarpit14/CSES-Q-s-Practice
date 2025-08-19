/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int f(int i, int j, int n, int m, vector<int> &a, vector<int> &b, vector<vector<int>> &dp){
    if(i==n || j==m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int x = f(i+1, j, n, m, a, b, dp);
    int y = f(i, j+1, n, m, a, b, dp);
    int z = 0;
    if(a[i] == b[j]) z = 1 + f(i+1, j+1, n, m, a, b, dp);
    return dp[i][j] = max({x, y, z});
}

    int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, m) cin>>b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int ans = f(0, 0, n, m, a, b, dp);
    cout<< ans << "\n";
    int i=0, j=0;
    vector<int> res;
    while (i < n && j < m){
        if (a[i] == b[j]){
            res.pb(a[i]);
            i += 1;
            j += 1;
        } else if (f(i + 1, j, n, m, a, b, dp) >= f(i, j + 1, n, m, a, b, dp)) i += 1;
        else j += 1;
    }
    each(x, res) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
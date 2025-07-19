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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, mx=0;
    cin>>t;
    vector<int> n(t);
    for(int i=0 ; i<t ; i++){
        cin>>n[i];
        mx = max(mx, n[i]);
    }
    vector<vector<int>> dp(mx+1, vector<int>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2 ; i<=mx ; i++){
        dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%MOD;
    }
    for(int i=0 ; i<t ; i++){
        int ans = (dp[n[i]][0]+dp[n[i]][1])%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}
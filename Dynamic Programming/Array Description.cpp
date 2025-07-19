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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    rep(i, 0, n) cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    for(int i=1 ; i<=m ; i++){
        if(a[0]==0 || a[0]==i)
        dp[0][i] = 1;
    }
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(a[i]!=0 && a[i]!=j)
            continue;
            int ans = 0;
            ans += dp[i-1][j]%MOD;
            if(j>1) ans += dp[i-1][j-1]%MOD;
            if(j<m) ans += dp[i-1][j+1]%MOD;
            dp[i][j] = ans%MOD;
        }
    }
    int ans = 0;
    for(int i=1 ; i<=m ; i++){
        ans = (ans + dp[n-1][i])%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
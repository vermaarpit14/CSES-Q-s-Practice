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
    string a, b;
    int n, m;
    cin>>a>>b;
    n = a.length(), m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=n ; i>=0 ; i--){
        for(int j=m ; j>=0 ; j--){
            if(i==n || j==m) dp[i][j] = (n-i)+(m-j);
            else dp[i][j] = min({1+dp[i+1][j], 1+dp[i][j+1], dp[i+1][j+1]+(a[i]!=b[j])});
        }
    }
    cout<<dp[0][0]<<"\n";
    return 0;
}
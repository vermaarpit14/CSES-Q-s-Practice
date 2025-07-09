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
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i=0 ; i<n ; i++){
        cin>>grid[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[0][0] != '*')
        dp[0][0] = 1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            if(i-1>=0 && j-1>=0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else if(i-1 >= 0){
                dp[i][j] = dp[i-1][j];
            } else if(j-1 >= 0){
                dp[i][j] = dp[i][j-1];
            }
            if(dp[i][j] >= MOD)
            dp[i][j] -= MOD;
        }
    }    
    cout<<dp[n-1][n-1]<<"\n";
    return 0;
}
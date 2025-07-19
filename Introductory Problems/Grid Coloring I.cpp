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
    vector<string> a(n);
    rep(i, 0, n) cin>>a[i];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if((i+j)&1){
                if(a[i][j] != 'A')
                a[i][j] = 'A';
                else
                a[i][j] = 'B';
            } else {
                if(a[i][j] != 'C')
                a[i][j] = 'C';
                else
                a[i][j] = 'D';
            }
        }
    }
    rep(i, 0, n) cout<<a[i]<<"\n";
    return 0;
}
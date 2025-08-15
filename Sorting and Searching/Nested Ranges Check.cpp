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
    int n; cin>>n;
    vector<pair<int, pair<int, int>>> a(n);
    vector<int> ans1(n, 0), ans2(n, 0);
    rep(i, 0, n) {
        cin>>a[i].ff>>a[i].ss.ff;
        a[i].ss.ss = i;
    }
    sort(all(a), [&](auto a, auto b){
        if(a.ff == b.ff)
        return a.ss.ff > b.ss.ff;
        return a.ff < b.ff; 
    });
    int mn = 1e18;
    per(i, 0, n){
        if (a[i].ss.ff >= mn)
            ans1[a[i].ss.ss] = 1;
        mn = min(mn, a[i].ss.ff);
    }
    int mx = -1;
    rep(i, 0, n){
        if (a[i].ss.ff <= mx)
            ans2[a[i].ss.ss] = 1;
        mx = max(mx, a[i].ss.ff);
    }
    rep(i, 0, n) cout<<ans1[i]<<" ";
    cout<<"\n";
    rep(i, 0, n) cout<<ans2[i]<<" ";
    cout<<"\n";
    return 0;
}
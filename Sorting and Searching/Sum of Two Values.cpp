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
    int n, x;
    cin>>n>>x;
    vector<pair<int, int>> a(n);
    rep(i, 0, n){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));
    int i=0, j=n-1;
    bool ans = false;
    while(i < j){
        if(a[i].first+a[j].first > x)
        j -= 1;
        else if(a[i].first+a[j].first < x)
        i += 1;
        else{
            ans = true;
            break;
        }
    }
    if(ans){
        if(a[i].second <= a[j].second)
            cout << a[i].second << " " << a[j].second << "\n";
        else
            cout << a[j].second << " " << a[i].second << "\n";
    }
    else
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}
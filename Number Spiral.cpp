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
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        int n = max(x, y);
        int tot = 2*n-1;
        int s = ((n-1)*(2+(n-2)*2)/2)+1;
        int e = s+tot-1;
        if(n&1){
            if(x<=y)
                cout<<e-x+1<<"\n";
            else
                cout<<s+y-1<<"\n";
        } else {
            if(x<=y)
                cout<<s+x-1<<"\n";
            else
                cout<<e-y+1<<"\n";
        }
    }
    return 0;
}
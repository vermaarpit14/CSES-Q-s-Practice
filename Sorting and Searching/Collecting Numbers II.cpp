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

vector<bool> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int ans = 1;

void f(int x, int y, int val, vector<pair<int, int>> &a, vector<int> &pos){
    int n = a.size();
    if(pos[x] > pos[y])
    swap(x, y);
    int i=pos[x], j=pos[y];
    if(i-1>=0 && a[i-1].second > a[i].second)
    ans += val;
    if(j+1<n && a[j].second > a[j+1].second)
    ans += val;
    if(i+1 == j){
        if(a[i].second > a[j].second)
        ans += val;
    } else {
        if(a[i].second > a[i+1].second)
        ans += val;
        if(a[j-1].second > a[j].second)
        ans += val;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // code here
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    vector<int> pos(n+1);
    rep(i, 0, n){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    rep(i, 1, n){
        if(a[i-1].second > a[i].second)
        ans += 1;
    }
    rep(i, 0, n) pos[a[i].second] = i;
    while(m--){
        int x, y;
        cin>>x>>y;
        x--; y--;
        f(x, y, -1, a, pos);
        int i=pos[x], j=pos[y];
        swap(a[i].second, a[j].second);
        swap(pos[x], pos[y]);
        f(x, y, 1, a, pos);
        cout<<ans<<"\n";
    }
    return 0;
}
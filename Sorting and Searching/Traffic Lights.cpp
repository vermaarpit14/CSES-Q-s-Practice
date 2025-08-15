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

int lb(set<int> &s, int x){
    auto it = s.lower_bound(x);
    if(it != s.begin()){
        --it;
        return *it;
    }
    return 0;
}

int ub(set<int> &s, int x){
    auto it = s.upper_bound(x);
    if(it != s.end())
    return *it;
    return -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int x, n;
    cin>>x>>n;
    set<int> a;
    multiset<int> b;
    a.insert(0);
    a.insert(x);
    b.insert(x);
    while(n--){
        int p; cin>>p;
        auto right = a.upper_bound(p);
        auto left = prev(right);
        b.erase(b.find((*right)-(*left)));
        a.insert(p);
        b.insert((*right)-p);
        b.insert(p-(*left)); 
        cout<<*b.rbegin()<<" ";
    }
    cout<<"\n";
    return 0;
}
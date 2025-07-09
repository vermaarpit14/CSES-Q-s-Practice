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

void f(int n, int src, int help, int des){
    if(n==0)
    return;
    f(n-1, src, des, help);
    cout<<src<<" "<<des<<"\n";
    f(n-1, help, src, des);
}

    int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n;
    cin>>n;
    int src=1, help=2, des=3;
    cout<<(1LL<<n)-1<<"\n";
    f(n, src, help, des);
    return 0;
}
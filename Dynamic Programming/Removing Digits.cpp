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
    int n, cnt=0;
    cin>>n;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i=1 ; i<=n ; i++){
        int b = i;
        while(b > 0){
            int d = b%10;
            if(i-d >=0){
                dp[i] = min(dp[i], dp[i-d]+1);
            }
            b /= 10;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}

/**************** GREEDY  APPROACH ****************/

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // code here
//     int n, cnt = 0;
//     cin >> n;
//     while (n > 0)
//     {
//         int b = n, mx = 0;
//         while (b > 0)
//         {
//             int d = b % 10;
//             mx = max(mx, d);
//             b /= 10;
//         }
//         cnt += 1;
//         n -= mx;
//     }
//     cout << cnt << "\n";
//     return 0;
// }

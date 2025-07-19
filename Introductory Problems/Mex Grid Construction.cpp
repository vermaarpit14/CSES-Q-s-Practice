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
vector<vector<int>> grid(100, vector<int>(100, 0));
vector<int> pow_2 = {0, 1, 2, 4, 8, 16, 32, 64, 128};

void f(int r, int c){
    int i=0, j=0;
    while(pow_2[i] <= r) i += 1;
    while(pow_2[j] <= c) j += 1;
    i -= 1;
    j -= 1;
    if(pow_2[i] == pow_2[j]){
        grid[r][c] = grid[r - pow_2[i]][c - pow_2[j]];
    } else if(pow_2[i] > pow_2[j]){
        grid[r][c] = grid[r - pow_2[i]][c] + pow_2[i];
    } else {
        grid[r][c] = grid[r][c - pow_2[j]] + pow_2[j];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            f(i, j);
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
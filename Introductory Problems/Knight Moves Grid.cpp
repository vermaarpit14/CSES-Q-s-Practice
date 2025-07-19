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
    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0 ; i<8 ; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<n && nx>=0 && ny<n && ny>=0 && board[nx][ny]==-1){
                board[nx][ny] = board[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    rep(i, 0, n){
        rep(j, 0, n){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
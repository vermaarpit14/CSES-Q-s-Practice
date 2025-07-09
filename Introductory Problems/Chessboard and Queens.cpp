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

int cnt = 0;

bool isSafe(int row, int col, vector<string> &board){
    for (int i = 0; i < col; i++){
        if (board[row][i] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--){
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void solve(int col, vector<string> &board)
{
    if (col == 8){
        cnt++;
        return;
    }
    for (int row = 0; row < 8; row++){
        if (board[row][col] != '*' && isSafe(row, col, board)){
            board[row][col] = 'Q';
            solve(col + 1, board);
            board[row][col] = '.';
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> board(8);
    rep(i, 0, 8) cin >> board[i];
    solve(0, board);
    cout << cnt << "\n";
    return 0;
}
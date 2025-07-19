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

bool poss(vector<int> &freq, int i, int j, int n){
    int rem = n-1-i;
    freq[j]--;
    int mx = -1;
    for(int i=0 ; i<26 ; i++){
        mx = max(mx, freq[i]);
    }
    freq[j]++;
    if(mx <= (rem+1)/2)
    return true;
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    string s, ans="";
    cin>>s;
    int n = s.length();
    vector<int> freq(26, 0);
    int mx = -1;
    for(int i=0 ; i<n ; i++){
        freq[s[i]-'A']++;
        mx = max(mx, freq[s[i]-'A']);
    }
    if(mx > (n+1)/2){
        cout<<-1<<"\n";
    } else {
        char last = '0';
        for (int i = 0; i < n; i++){
            bool f = false;
            for (int j = 0; j < 26; j++){
                if (last != (char)(j+65) && freq[j] > 0 && poss(freq, i, j, n)){
                    freq[j]--;
                    f = true;
                    ans += (char)(j+65);
                    last = (char)(j+65);
                    break;
                }
            }
            if (!f){
                ans = "-1";
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
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
    string s;
    cin>>s;
    int odd_freq = 0;
    string odd_char = "", res = "";
    bool ans = true;
    int n = s.length();
    vector<int> freq(26, 0);
    for(int i=0 ; i<n ; i++)
        freq[s[i]-'A']++;
    for(int i=0 ; i<26 ; i++){
        if(freq[i]&1){
            odd_freq += 1;
            odd_char += string(freq[i], char(i+65));
        }
        if(odd_freq > 1){
            ans = false;
            break;
        }
    }
    if(!ans){
        cout<<"NO SOLUTION"<<"\n";
    } else {
        for(int i=0 ; i<26 ; i++){
            char ch = char(i+65);
            if(freq[i]%2 == 0){
                for(int j=1 ; j<=freq[i]/2 ; j++)
                    res += ch;
            }
        }
        string res_rev = res;
        reverse(all(res_rev));
        cout<<res+odd_char+res_rev<<"\n";
    }
    return 0;
}
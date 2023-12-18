#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
ll a, b;
string num;
ll dp[20][10][20][2], cnt[20][10][20][2];

pll fun(ll pos, ll prev, ll am, bool bound) {
    if (pos==num.size()) return make_pair(prev*am*am, 1);
    ll &val = dp[pos][prev][am][bound], &cont = cnt[pos][prev][am][bound];
    if (val!=-1) return make_pair(val, cont);
    val = 0;//cont =0;
    ll upp = bound ? num[pos]-'0' : 9;
    for (int i = 0; i <= upp; i++) {
        if (i==prev) {
            pll tmp = fun(pos+1, i, am+1, (bound and upp==i));
            val += tmp.first; cont +=tmp.second;
        }
        else {
            pll tmp = fun(pos+1, i, 1, (bound and upp==i));
            cont+=tmp.second;
            val += tmp.first + am*am*prev*tmp.second;
        }
    }
    return make_pair(val, cont);
}

int main() {
    cin >> a >> b;
    memset(dp,-1, sizeof(dp));
    num = to_string(b);
    pll big = fun(0, 0, 0, 1);
    memset(dp, -1, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    a--;
    num = to_string(a);
    pll small = fun(0, 0, 0, 1);
    cout << big.first-small.first << endl;
}
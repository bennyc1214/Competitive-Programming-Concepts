#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
const int M = 1e5+7;
ll n, m;
ll a[M];
ll bit[M];
ll freq[M];
ll f[M];

void updateBIT(ll val, ll pos) {
    for (int i = pos; i<M; i+=i&-i) {
        bit[i] += val;
    }
}

ll qBIT(int pos) {
    ll ret= 0;
    for (int i = pos; i>0; i-=i&-i) {
        ret+=bit[i];
    }
    return ret;
}

void updateFREQ(ll val, ll pos) {
    for (int i = pos; i<M; i+=i&-i) {
        freq[i] += val;
    }
}

int qFREQ(ll pos) {
    ll ret= 0;
    for (int i = pos; i>0; i-=i&-i) {
        ret+=freq[i];
    }
    return ret;
}

int main() {
    cin >> n >> m;
    ll x, v, l, r;
    for (int i = 1; i <=n; i++) {
        cin >>x;
        updateFREQ(1, x);
        a[i] = x;
        f[x]++;
        updateBIT(x, i);
    }
    char c;
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c=='C') {
            cin >> x >> v;
            updateBIT(v-a[x], x);
            if (a[x]!=v) {
                updateFREQ(-1, a[x]);
                updateFREQ(1, v);
                a[x] = v;
            }
            

        }
        else if (c=='S') {
            cin >> l >> r;
            ll ans = qBIT(r) - qBIT(l-1);
            cout << ans << endl;
        }
        else {
            cin >> v;
            cout << qFREQ(v) << endl;
        }
    }
}
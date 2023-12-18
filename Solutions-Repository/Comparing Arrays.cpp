#include <bits/stdc++.h>

using namespace std;

const int M = 5e5+5, mod =1e9+7, base = 1e8+7;
#define ll long long
#define pii pair<int, int>
int n, q, a[M];
ll bit[M], pw[M];

void update(int pos, ll val) {
    for (int i =pos; i <=n; i+=i&-i) {
        bit[i] = (bit[i]+val)%mod;
    }

}

ll query(int pos) {
    ll ret=0;
    for (int i = pos; i>0; i-=i&-i) {
        ret = (ret+bit[i])%mod;
    }
    return ret;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        pw[i] = pw[i-1] *base%mod;
        update(i, a[i]*pw[i]%mod);
    }
    for (int i = 1, op, l1, r1, l2, r2, p, v; i<=q; i++) {
        cin >> op;
        if (op==1) {
            cin >> l1 >> r1 >> l2 >> r2;
            ll v1 = (query(r1)-query(l1-1)+mod)%mod;
            ll v2 = (query(r2)-query(l2-1)+mod)%mod;
            if (v1*pw[l2]%mod==v2*pw[l1]%mod) cout << "1\n";
            else cout << "0\n";
        }
        else {
            cin >> p >> v;
            update(p, (-a[p]+v+mod)*pw[p]%mod);
            a[p] = v;
        }
    }
}
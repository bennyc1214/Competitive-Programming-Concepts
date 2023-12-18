#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 2e5+5;
struct node {
    int l, r;
    ll v, lz;
}
seg[3*M];
;

void pushup(int rt) {
    seg[rt].v = max(seg[2*rt].v, seg[2*rt+1].v);
}

void pushdown(int rt) {
    seg[2*rt].v += seg[rt].lz; seg[2*rt].lz+=seg[rt].lz;
    seg[2*rt+1].v += seg[rt].lz; seg[2*rt+1].lz+=seg[rt].lz;
    seg[rt].lz =0;
}

void build(int l, int r, int rt) {
    //rt --> "root"
    seg[rt].r = r;
    seg[rt].l = l;
    if (l==r) return;
    int mid = (l+r)/2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
    pushup(rt);

}

void update(int l, int r, int delta, int rt) {
    if (seg[rt].l==l and seg[rt].r==r) {
        seg[rt].v+=delta;
        seg[rt].lz +=delta;
        return;
    }
    if (seg[rt].lz) {
        pushdown(rt);
    }
    int mid = (seg[rt].l+seg[rt].r)/2;
    if (r<=mid) update(l, r, delta, 2*rt);
    else if (l>mid) update(l, r, delta, 2*rt+1);
    else {
        update(l, mid, delta, 2*rt);
        update(mid+1, r, delta, 2*rt+1);
    }
    pushup(rt);
}

ll query(int l, int r, int rt) {
    if (seg[rt].l==l and seg[rt].r==r) {
        return seg[rt].v;
    }
    if (seg[rt].lz) pushdown(rt);
    int mid = (seg[rt].l+seg[rt].r)/2;
    if (r<=mid) {
        return query(l, r, rt*2);
    }
    else if (l>mid) {
        return query(l, r, rt*2+1);
    }
    else {
        return max(query(l, mid, 2*rt), query(mid+1, r, 2*rt+1));
    }

}

int n, k, q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> q;
    build(0, n-1, 1);
    for (int i = 1, op, x, y; i <=q; i++) {
        cin >> op >> x >> y;
        if (op==0) update(max(0, x-k+1), x, y, 1);
        else cout << query(max(x, 0), min(n-1, y), 1) << endl;
    }
}
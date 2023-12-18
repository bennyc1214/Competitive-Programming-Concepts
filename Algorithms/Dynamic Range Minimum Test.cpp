#include <iostream>

using namespace std;

struct node {
    int left, right, mi;
};

int n, m;
node seg[3 * 100000];
int a[3 * 100000];

void pushup(int ind) {
    seg[ind].mi = min(seg[2 * ind].mi, seg[2 * ind + 1].mi);
}

void build(int l, int r, int ind) {
    //l represents the left half of the interval
    //r represents the right half of the interval
    //ind is the index of the seg array(the node number)

    seg[ind].left = l;
    seg[ind].right = r;
    if (l == r) {
        seg[ind].mi = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * ind); build(mid + 1, r, 2 * ind + 1); pushup(ind);
}

void update(int val, int pos, int ind) {
    int l = seg[ind].left, r = seg[ind].right;
    if (l == r) {
        seg[ind].mi = val; return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        //update left
        update(val, pos, 2 * ind);
    }
    else {
        //update right
        update(val, pos, 2 * ind + 1);
    }
    pushup(ind);
}

int query(int l, int r, int ind) {
    if (seg[ind].left == l and seg[ind].right == r) {
        return seg[ind].mi;
    }
    int mid = (seg[ind].left + seg[ind].right) / 2;
    if (l > mid) {
        return query(l, r, 2 * ind + 1);
    }
    else if (r <= mid) {
        return query(l, r, 2 * ind);
    }
    else {
        return min(query(l, mid, 2 * ind), query(mid + 1, r, 2 * ind + 1));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    build(1, n, 1);
    char c;
    int i, j;

    for (int k = 0; k < m; k++) {
        cin >> c >> i >> j;
        if (c == 'M') {
            update(j, i + 1, 1);
        }
        else {
            cout << query(i+1, j+1, 1) << endl;
        }
    }
}


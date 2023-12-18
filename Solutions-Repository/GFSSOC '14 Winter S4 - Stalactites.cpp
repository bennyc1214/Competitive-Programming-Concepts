#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int M = 252;
int n, q;
ll bit[M][M][M];
ll a[M][M][M];
ll ans;

void update(int x, int y, int z, int val) {
    for (int i = x; i <M; i+=i&-i) {
        for (int j = y; j <M; j+=j&-j) {
            for (int h = z; h <M; h+=h&-h) {
                bit[i][j][h] += val;
            }
        }
    }
}

ll query(int x, int y, int z) {
    ll ret = 0;
    for (int i = x; i >0; i-=i&-i) {
        for (int j = y; j >0; j-=j&-j) {
            for (int h = z; h >0; h-=h&-h) {
                ret += bit[i][j][h];
            }
        }
    }
    return ret;
}

int main() {
    cin >> n >> q;
    int x, y, z, val;
    char type;
    while (q--) {
        cin >> type;
        if (type=='C') {
            cin >> x >> y >> z >> val;
            //update operation
            update(x, y, z, val-a[x][y][z]);
            a[x][y][z] = val;
        }
        else {
            int x1, x2, y1, y2, z1, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ll out= query(x2, y2, z2);
            out-=query(x1-1, y2, z2);
            out-=query(x2, y1-1, z2);
            out-=query(x2, y2, z1-1);
            out += query(x2, y1-1, z1-1);
            out += query(x1-1, y1-1, z2);
            out += query(x1-1, y2, z1-1);
            out -=query(x1-1, y1-1, z1-1);
            ans += out;
        }
    }
    cout << ans << endl;
}
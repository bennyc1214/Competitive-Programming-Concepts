#include<iostream>
#include <algorithm>

using namespace std;
#define ll long long
const int M = 3e3 + 5;
int n, m;
ll bit[M][M];
ll a[M][M];

void update(int r, int c, ll val) {
    if (r % 2 != c % 2) val *= -1;
    for (int i = r; i < M; i += i & -i) {
        for (int j = c; j < M; j += j & -j) {
            bit[i][j] += val-a[r][c];
        }
    }
}

ll query(int r, int c) {
    ll ret=0;
    for (int i = r; i >0; i -= i & -i) {
        for (int j = c; j >0; j -= j & -j) {
            ret += bit[i][j];
        }
    }
    return ret;
}

int main()
{
    cin >> m >> n; 
    int q, r1, c1, r2, c2, x;
    while (true) {
        cin >> q;
        if (q == 0) break;
        if (q == 1) {
            cin >> r1 >> c1 >> x;
            update(r1, c1, x);
            if (r1 % 2 == c1 % 2) {
                a[r1][c1] = x;
            }
            else {
                a[r1][c1] = -x;
            }
            
        }
        else {
            cin >> r1 >> c1 >> r2 >> c2;
            ll ans = query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
            if (r1 % 2 == c1 % 2) {
                //cout << "The query answer is right below\n";
                cout << ans << endl;
            }
            else {
                //cout << "The query answer is right below(multiplied)\n";
                cout << ans * -1 << endl;
            }
        }
    }
}
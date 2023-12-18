#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int M = 1025;
int n, bit[M][M], op;

void update(int r, int c, int val) {
    r++; c++;
    for (int i = r; i < M; i+=i&-i) {
        //cout << "Still updating\n";
        for (int j = c; j < M; j+=j&-j) {
            bit[i][j]+=val;
            //cout << "This is i and j " << i << " " << j << endl;
        }
    }
}

int query(int r, int c) {
    r++; c++;
    int ret = 0;
    for (int i =r; i>0; i-=i&-i) {
        for (int j = c; j >0; j-=j&-j) {
            ret+=bit[i][j];
        }
    }
    return ret;
}

int main() {
    cin >> op >> n;
    int x, y, a, r1, c1, r2, c2;
    while (op!=3) {
        cin >> op;
        if (op==1) {
            cin >> x >> y >> a;
            update(x, y, a);
        }
        else if (op==2) {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << query(r2, c2) - query(r2, c1-1) - query(r1-1, c2) + query(r1-1, c1-1) << "\n"
            ;
        }
    }
}
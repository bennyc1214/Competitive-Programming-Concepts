#include <bits/stdc++.h>

using namespace std;

int n, st, des, ans, mi[8];

int bfs(int st, int ed) {
    queue<int> q;
    bitset<(1<<21)> vis;
    q.push(st);
    vis[st] =1;
    int step=0;
    while (!q.empty()) {
        int sz = q.size();
        for (int k = 0; k <sz; k++) {
            int mask = q.front(); q.pop();
            if (mask==des) return step;
            memset(mi, -1, sizeof(mi));
            for (int i = 0; i<n; i++) {
                int pos = ((mask >> 3*i) & 7);
                if (mi[pos] == -1 or i <mi[pos]) mi[pos] = i;
            }
            for (int i = 0; i < n; i++) {
                if (mi[i]==-1) continue;
                if (i>0 and (mi[i-1]==-1 or mi[i-1]>mi[i])) {
                    int nmask = mask - (i << 3*mi[i]) + ((i-1) << 3*mi[i]);
                    if (!vis[nmask]) {
                        q.push(nmask);
                        vis[nmask] = 1;
                    }
                }

                if (i+1<n and (mi[i+1]==-1 or mi[i+1]>mi[i])) {
                    int nmask = mask - (i << 3*mi[i]) + ((i+1) << 3*mi[i]);
                    if (!vis[nmask]) {
                        q.push(nmask);
                        vis[nmask] = 1;
                    }
                }

            }
        }
        step++;
    }
    return -1;

}

int main() {
    while (cin >> n and n) {
        st = des = 0;
        int x;
        for (int i=0; i<n; i++) {
            cin >> x;
            x--;
            st |= i << 3*x;
            des |= x << 3*x;
        }
        int ans = bfs(st, des);
        if (ans==-1) {
            cout << "IMPOSSIBLE\n";
        }
        else cout << ans << endl;
    }

}
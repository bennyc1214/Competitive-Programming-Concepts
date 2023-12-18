#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
const int M = 20;
int blood[8], patient[8], ans, src=0, des=17, pre[20]; bool vis[20];
int adj[M][M];
//vector<pii> a = {{1, 9}, {1, 10}, {2, 10}, {1, 11}, {3, 11}, {1, 12}, {2, 12}, {3, 12}, {4, 12}, {1, 13}, {5, 13}, {1,}

int bfs() {
    queue<int> q;
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    q.push(src);
    vis[src]=true;
    pre[src]=-1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0;  v<=18; v++) {
            if (adj[u][v]>0 and !vis[v]) {
                q.push(v);
                pre[v] = u;
                vis[v] = true;
            }
        }
        if (vis[des]) break;
    }
    int ret = 1e9;
    for (int u = des; u; u=pre[u]) {
        ret = min(ret, adj[pre[u]][u]);
    }
    return ret;
}

int maxFlow() {
    int flow = 0, dif=0;
    while (dif=bfs()) {
        flow+=dif;
        for (int u = des; u; u=pre[u]) {
            adj[pre[u]][u] -= dif;
            adj[u][pre[u]] += dif;
        }
    }
    return flow;
}

int main() {
    for (int i =1; i <= 8; i++) cin >> adj[src][i];
    for (int i =1; i <= 8; i++) cin >> adj[i+8][des];
    adj[1][9] = min(adj[src][1], adj[1+8][des]);
    for (int i = 1; i <=2; i++) adj[i][10] = min(adj[src][i], adj[10][des]);
    for (int i = 1; i <=3; i+=2) adj[i][11] = min(adj[src][i], adj[11][des]);
    for (int i = 1; i <=4; i++) adj[i][12] = min(adj[src][i], adj[12][des]);
    for (int i = 1; i <=5; i+=4) adj[i][13] = min(adj[src][i], adj[13][des]);

    for (int i = 1; i <=6; i++)
        if (i!=3 and i!=4) adj[i][14] = min(adj[src][i], adj[14][des]);

    for (int i = 1; i <=7; i+=2) adj[i][15] = min(adj[src][i], adj[15][des]);
    for (int i = 1; i <=8; i++) adj[i][16] = min(adj[src][i], adj[16][des]);

    cout << maxFlow() << endl;
}
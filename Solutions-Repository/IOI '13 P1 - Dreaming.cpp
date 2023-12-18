#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5+5;
int N, M, L, pre[MM], rt; vector<pi> adj[MM]; ll dis[MM], ans, D, R; bool vis[MM]; vector<ll> r;
void dfs(int u, int pa, ll d){
    if(d > D) { D = d; rt = u;}
    vis[u] = true; pre[u] = pa; dis[u] = d;
    for(auto &e : adj[u])
        if(e.first != pa) dfs(e.first, u, d + e.second);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> L;
    for(int i=1, u, v, w; i<=M; i++){
        cin >> u >> v >> w; u++; v++;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    for(int i=1; i<=N; i++){
        if(vis[i]) continue;
        D = -1; dfs(i, 0, 0); D = -1; dfs(rt, 0, 0); ans = max(ans, D); R=1e18;
        for(int u=rt; u; u=pre[u]) R = min(R, max(dis[u], D-dis[u]));
        r.push_back(R);
    }
    sort(r.begin(), r.end(), greater<ll>());
    if(r.size() > 1) ans = max(ans, r[0] + r[1] + L);
    if(r.size() > 2) ans = max(ans, r[1] + r[2] + 2*L);
    cout << ans << endl;
}
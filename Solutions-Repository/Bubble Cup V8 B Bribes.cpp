#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+5, mod = 1e9+7, LOG=17;
int N, K, up[MM], dn[MM], dir[MM], dep[MM], anc[LOG][MM], pw[10*MM]; vector<pi> adj[MM]; ll ans;
void dfs1(int u, int pa){
    dep[u] = dep[pa]+1; anc[0][u] = pa;
    for(int k=1; k<LOG; k++) anc[k][u] = anc[k-1][anc[k-1][u]];
    for(auto [v, w] : adj[u]){
        if(v == pa) continue;
        dir[v] = w; dfs1(v, u);
    }
}
int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i=LOG-1; i>=0; i--)
        if(dep[anc[i][u]] >= dep[v]) u = anc[i][u];
    if(u == v) return v;
    for(int i=LOG-1; i>=0; i--)
        if(anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}
void dfs2(int u, int pa){
    for(auto [v, w] : adj[u]){
        if(v == pa) continue;
        dfs2(v, u); up[u]+=up[v]; dn[u]+=dn[v];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1, u, v, w; i<N; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, -w});
    }
    cin >> K; pw[0] = 1;
    for(int i=1; i<=K; i++) pw[i] = pw[i-1] * 2 % mod;
    dfs1(1, 0); int cur = 1;
    for(int i=1, u; i<=K; i++) {
        cin >> u;
        if(u == cur) continue;
        int rt = LCA(cur, u);
        up[cur]++; dn[u]++; up[rt]--; dn[rt]--;  cur=u;
    }
    dfs2(1, 0);
    for(int i=1; i<=N; i++) {
        if(dir[i] > 0) ans += pw[up[i]] - 1;
        else if(dir[i] < 0) ans += pw[dn[i]]-1;
        ans = (ans+mod)%mod;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+5;
int N, K, sz[MM], ans = 1e9; vector<pi> adj[MM], path; bool done[MM]; gp_hash_table<int, int> mp;
void getsz(int u, int pa){
    sz[u] = 1;
    for(pi e : adj[u]){
        if(e.first != pa && !done[e.first]) {
            getsz(e.first, u); sz[u] += sz[e.first];
        }
    }
}
int getcent(int u, int pa, int tot){
    for(pi e : adj[u])
        if(e.first != pa && !done[e.first] && sz[e.first]*2>tot) return getcent(e.first, u, tot);
    return u;
}
void dfs(int u, int pa, int dis, int edge){
    if(dis > K) return;
    if(mp.find(K - dis) != mp.end()) ans = min(ans, edge + mp[K-dis]);
    path.push_back({dis, edge});
    for(pi e : adj[u]){
        int v = e.first, w = e.second;
        if(v != pa && !done[v]) dfs(v, u, dis+w, edge+1);
    }
}
void solve(int rt, int par){
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]); done[rt]=1;
    mp.clear();  mp[0] = 0;
    for(pi e : adj[rt]){
        int v = e.first, w = e.second;
        if(v != par && !done[v]){
            path.clear(); dfs(v, rt, w, 1);
            for(pi e : path){
                if(mp.find(e.first) == mp.end()) mp[e.first] = e.second;
                else mp[e.first] = min(mp[e.first], e.second);
            }
        }
    }
    for(pi e : adj[rt]){
        if(!done[e.first]) solve(e.first, rt);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1, u, v, w; i<N; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    solve(0, -1);
    cout << (ans==1e9? -1:ans) << endl;
}
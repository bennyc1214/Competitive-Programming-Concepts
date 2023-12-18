#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+5;
int n, sz[MM]; vector<pi> adj[MM]; bool done[MM]; unordered_map<int, int> mp; ll ans; char color;
void getsz(int u, int pa){
    sz[u] = 1;
    for(pi e : adj[u])
        if(e.first != pa && !done[e.first]) { getsz(e.first, u);  sz[u] += sz[e.first]; }
}
int getcent(int u, int pa, int tot){
    for(pi e: adj[u]){
        int v = e.first;
        if(v != pa && !done[v] && sz[v] * 2 > tot) return getcent(v, u, tot);
    }
    return u;
}
void dfs(int u, int pa, int d, vector<int> &path){
    ans += mp[1-d] + mp[-1-d]; path.push_back(d); //d + x = 1 or -1  --> x = 1 - d or -1 - d
    for(pi e : adj[u]){
        int v = e.first, w = e.second;
        if(v != pa && !done[v]) dfs(v, u, d + w, path);
    }
}
void solve(int rt){
    getsz(rt, 0); rt = getcent(rt, 0, sz[rt]); done[rt]=true;
    mp.clear(); mp[0] = 1;
    for(pi e: adj[rt]){
        int v = e.first, w = e.second; vector<int> path;
        if(!done[v]){
            dfs(v, rt, w, path);
            for(int d : path) mp[d]++;
        }
    }
    for(pi e: adj[rt])
        if(!done[e.first]) solve(e.first);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1, u, v, w; i<n; i++){
        cin >> u >> v >> color;  w = color == 'r'? 1 : -1;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    solve(1);  cout << ans - (n-1) << endl;
}
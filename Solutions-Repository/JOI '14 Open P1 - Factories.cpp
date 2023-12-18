#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 5e5+5;
int n, sz[MM], lvl[MM], pa[MM]; ll dis[20][MM], dp[MM], ans, inf=0x3f3f3f3f3f3f3f3f; vector<pi> adj[MM]; bool done[MM];
void getsz(int u, int pre){
    sz[u] = 1;
    for(pi e : adj[u])
        if(e.first != pre && !done[e.first]) { getsz(e.first, u); sz[u] += sz[e.first]; }
}
int getcent(int u, int pre, int tot){
    for(pi e : adj[u]){
        int v = e.first;
        if(v != pre && !done[v] && sz[v] * 2 > tot) return getcent(v, u, tot);
    }
    return u;
}
void getdis(int u, int pre, int level, ll d){
    dis[level][u] = d;
    for(pi e : adj[u]){
        int v = e.first, w = e.second;
        if(v != pre && !done[v]) getdis(v, u, level, d + w);
    }
}
void solve(int rt, int pre, int level){
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]);
    done[rt] = true; lvl[rt] = level; pa[rt] = pre;
    getdis(rt, -1, level, 0);
    for(pi e : adj[rt])
        if(!done[e.first]) solve(e.first, rt, level+1);
}
void Init(int N, int A[], int B[], int D[]) {
    n = N; memset(dp, 0x3f, sizeof(dp));
    for(int i=0; i<n-1; i++){
        adj[A[i]].push_back({B[i], D[i]}); adj[B[i]].push_back({A[i], D[i]});
    }
    solve(0, -1, 0);
}
ll Query(int S, int X[], int T, int Y[]) {
    ans = inf;
    for(int i=0; i<S; i++)
        for(int u=X[i], v=X[i]; u!=-1; u=pa[u])
            dp[u] = min(dp[u], dis[lvl[u]][v]);
    for(int i=0; i<T; i++)
        for(int u=Y[i], v=Y[i]; u!=-1; u=pa[u])
            ans = min(ans, dp[u] + dis[lvl[u]][v]);
    for(int i=0; i<S; i++)
        for(int u=X[i]; u!=-1; u=pa[u])
            dp[u] = inf;
    return ans;
}
//int main(){
//    int x = 7, a[6] = {0, 1, 2, 2, 4, 1}, b[6] = {1, 2, 3, 4, 5, 6}, d[6] = {4, 4, 5, 6, 5, 3};
//    Init(x, a, b, d);
//    int X[3] = {0, 1, 3}, Y[2] = {4, 6};
//    cout << Query(3, X, 2, Y) << endl;
//}
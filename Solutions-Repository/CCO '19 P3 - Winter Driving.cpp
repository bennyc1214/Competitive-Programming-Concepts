#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, a[MM], sz[MM]; ll ans, cnt, tot; vector<int> adj[MM], cent;
void dfs(int u, int pa){
    sz[u] = a[u];
    for(int v: adj[u])
        if(v != pa){ dfs(v, u); sz[u] += sz[v]; }
    cnt += 1LL*a[u]*(sz[u] - 1);
}
void getCent(int u, int pa){
    bool flag = (tot - sz[u])*2LL <= tot;
    if(!flag) return;
    for(int v: adj[u]){
        if(v!=pa && sz[v]*2LL > tot) flag = false;
        if(v!= pa) getCent(v, u);
    }
    if(flag) cent.push_back(u);
}
void solve(int rt){
    vector<int> ch; vector<ll> lsz; ll top = 0, mx = 0; cnt = 0;
    dfs(rt, 0); top = tot - a[rt];
    for(int v: adj[rt]) ch.push_back(sz[v]);
    int lft = (int)ch.size() / 2, rit = (int)ch.size() - lft;
    for(int mask = 0, up = (1<<lft); mask < up; mask++){
        ll tmp = 0;
        for(int i=0; i<lft; i++)
            if(mask & (1<<i)) tmp += ch[i];
        lsz.push_back(tmp);
    }
    sort(lsz.begin(), lsz.end());
    for(int mask = 0, up = (1<<rit); mask < up; mask++){
        ll tmp = 0;
        for(int i=0; i<rit; i++)
            if(mask & (1<<i)) tmp += ch[lft+i];
        if(2*(tmp + *lsz.rbegin()) < top) continue;
        auto it = lower_bound(lsz.begin(), lsz.end(), (top+1)/2-tmp);
        mx = max(mx, (tmp + *it) * (top - tmp - *it));
    }
    ans = max(ans, mx + cnt);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=1; i<=N; i++) { scanf("%d", &a[i]); tot+=a[i]; }
    for(int i=2, u; i<=N; i++){
        scanf("%d", &u);
        adj[i].push_back(u); adj[u].push_back(i);
    }
    dfs(1, 0); getCent(1, 0);
    for(int rt: cent) solve(rt);
    printf("%lld\n", ans);
}
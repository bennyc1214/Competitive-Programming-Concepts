#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
const int M = 100005;
ll n, m, a, b, c, ans=LLONG_MAX;
vector<pair<pll, ll>> edges;
vector<pll> adj[M];
ll costs[M];
priority_queue<pll, vector<pll>, greater<pll>> pq;
//go from a -> b in less than c time

void mset() {
    for (int i = 0; i < M; i++) costs[i] = LLONG_MAX;
}

void showadj() {
    for (int i = 1; i <=n; i++) {
        cout << i << ": ";
        for (auto u : adj[i]) {
            cout << u.first << " ";
        }
        cout << endl;
    }
}

void dijkstra() {
    //memset(costs, 0x3f3f3f3f, sizeof(costs));
    mset();
    pq.push(make_pair(0, a));
    costs[a]=0;
    while (!pq.empty()) {
        pll g = pq.top();
        pq.pop();
        if (costs[g.second]!=g.first) continue;
        for (auto u : adj[g.second]) {
            if (g.first+u.second < costs[u.first]) {
                costs[u.first] = g.first+u.second;
                pq.push(make_pair(costs[u.first], u.first));
            }
        }
    }
}

void gen(int am) {
    for (int i = 1; i <=n; i++) adj[i].clear();
    for (int i = 0; i<= am; i++) {
        pair<pll, ll> ed = edges[i];
        adj[ed.first.first].push_back(make_pair(ed.first.second, ed.second));
        adj[ed.first.second].push_back(make_pair(ed.first.first, ed.second));
    }
    dijkstra();
}

void bsearch() {
    ll l=0, r=m-1, mid;
    while (l<=r) {
        mid = (l+r)/2;
        //cout << "I tried " << mid << endl;
        gen(mid);
        //showadj();
        //cout << "This is cost " << costs[b] << endl;
        if (costs[b]<c) {
            //it works
            r=mid-1;
            ans = min(ans, mid);
        }
        else {
            l = mid+1;
        }
    }
}

int main() {
    cin >> n >> m;
    ll x, y, r;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> r;
        edges.push_back(make_pair(make_pair(x, y), r));
    }
    cin >> a >> b  >>c;
    bsearch();
    if (ans==LLONG_MAX) {
        cout << "-1\n";
    }
    else cout << ans+1 << endl;
}
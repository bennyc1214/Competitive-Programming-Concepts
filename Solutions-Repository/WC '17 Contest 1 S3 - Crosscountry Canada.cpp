#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int > > piii;
typedef pair<int, int> pii;
#define mp make_pair

const int M = 1005;
int n, m, l, t;
bool isHortons[M];
vector<pair<int, int>> adj[M];
int dists[M][105];
priority_queue<piii, vector<piii>, greater<piii> > pq;
//first index represents the city that we are visiting
//the second index represents the amount of time spent without tim hortons

void dijkstra() {
    memset(dists, 0x3f, sizeof(dists));
    dists[1][0] = 0;
    pq.push(mp(0, mp(1, 0)));
    //the first is the distance, the second.first is the node
    //the second.second is the time spent without hortons
    while (!pq.empty()) {
        piii g = pq.top();
        pq.pop();
        int cost = g.first, city = g.second.first, hortons = g.second.second;
        if (dists[city][hortons]!=cost) continue;
        for (auto u: adj[city]) {
            int node = u.first;
            int weight = u.second;
            //consider going to tim hortons restaurant at current position
            if (dists[node][0+weight]>t+weight+cost and isHortons[city] and weight<=l) {
                dists[node][weight] = t+weight+cost;
                pq.push(mp(t+weight+cost, mp(node, weight)));
            }
            //dont consider going to tim hortons restaurant at current position
            if (dists[node][hortons+weight]>weight+cost and hortons+weight<=l) {
                dists[node][hortons+weight] = weight+cost;
                pq.push(mp(weight+cost, mp(node, hortons+weight)));
            }
        }
    }

}


int main() {
    cin >> n >> m >> l >> t;
    for (int i = 1; i <= n; i++) {
        cin >> isHortons[i];
    }
    int a,b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >>c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    dijkstra();
    int ans=INT_MAX;
    for (int i = 0; i <=l; i++) {
        ans = min(ans, dists[n][i]);
    }
    if (ans == dists[0][104]) ans = -1;
    cout << ans << endl;

}
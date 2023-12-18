#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 5;
int n, m, start;
vector<pair<int, int>> adj[M];
int dists[M];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;

void dijkstra(int v) {
    for (int i = 0; i < M; i++) dists[i] = INT_MAX;
    dists[v] = 0;
    pq.push(make_pair(0, v));
    while (!pq.empty()) {
        pair<int, int> g = pq.top();
        pq.pop();
        if (dists[g.second] != g.first) continue;
        for (auto u : adj[g.second]) {
            if (g.first + u.second < dists[u.first]) {
                dists[u.first] = g.first + u.second;
                pq.push(make_pair(dists[u.first], u.first));
            }
        }
    }
}

int main()
{
    cout << "How many nodes and edges would you like?(0-indexed)\n";
    cin >> n >> m;
    int x, y, z;
    cout << "Please enter your edges in the form of: node1, node2, cost(directed edges)\n";
    for (int i = 0; i < m; i++) {
        cout << "Please enter your " << i << " edge:";
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
    }
    cout << "Please enter the node that you would like to run Dijkstra from:";
    
    cin >> start;
    dijkstra(start);
    for (int i = 0; i < n; i++) {
        cout << "The distance from " << start << " to " << i << " is: " << dists[i] << endl;
    }
}


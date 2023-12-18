#include <bits/stdc++.h>

using namespace std;

//dfs implementation
//graph is stored via adjacency list, undirected graph

const int M = 2e5+9;
vector<int> adj[M];
int nodes, edges;
int a, b, starting;
bool vis[M];

void dfs(int node) {
    cout << "Visited " << node << "!\n";
    vis[node]=1;
    for (int v : adj[node]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    cout << "How many nodes are in your graph?\n";
    cin >> nodes;
    cout << "How many edges are in your graph?\n";
    cin >> edges;
    for (int i = 1; i<=edges; i++) {
        cout << "Input edge #" << i << endl;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "What node would you like to start the traversal from?\n";
    cin >> starting;
    dfs(starting);
}
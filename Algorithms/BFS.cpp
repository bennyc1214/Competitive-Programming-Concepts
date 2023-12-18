#include <bits/stdc++.h>

using namespace std;

//bfs implementation
//undirected graph, graph stored via adjacency list
int nodes, edges;
const int M = 2e5+9;
vector<int> adj[M];
bool vis[M];
int a, b, starting;
queue<int> q;

void bfs(int node) {
    q.push(node);
    while (!q.empty()) {
        int topNode = q.front();
        cout << "Visited " << topNode << "!\n";
        q.pop(); //remove node from queue now that we are processing it
        vis[topNode] =1;
        for (int v : adj[topNode]) {
            if (!vis[v]) {
                q.push(v);
            }
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
    bfs(starting);

}
#include <bits/stdc++.h>

using namespace std;
const int M = 5e5+9;
//there is a dependency relationship, so we can model this problem with a directed graph
//then, we use topological sort to solve for the optimal order
//indegree 0 means no dependency --> means go first
//use priority queue here instead of queue because we want the largest number first
int n, a[M], in[M], last[M];
vector<int> adj[M], pf[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i =2; i<=n; i++) {
        if (pf[i].empty()) {
            for (int j = i; j <=n; j+=i) {
                pf[j].push_back(i);
                //using sieve to preprocess every distinct prime factor of each number
            }
        }
    }
    for (int i =1,x ; i <=n; i++) {
        cin >> x;
        for (int f : pf[x]) {
            if (last[f]!=0) {
                adj[last[f]].push_back(x);
                in[x]++;
            }
            last[f] = x;
        }
    }

    priority_queue<int> q;
    vector<int> order;
    for (int i = 1; i <=n; i++) {
        if (in[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--in[v]==0) q.push(v);
        }
    }
    for (int i = 0; i <order.size(); i++) cout << order[i] << " \n"[i+1==order.size()];
}
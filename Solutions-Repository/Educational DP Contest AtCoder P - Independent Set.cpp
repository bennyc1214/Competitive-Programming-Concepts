#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int M = 1e5 + 6;
const ll MOD = 1e9 + 7;
vector<int> adj[M];
int n;
ll dp[M][2];
//dp[node][white or black]
//white is 0, black is 1
void solve(int node, int par) {
    if (adj[node].size() == 1 and node != 1) {
        dp[node][1] = 1;
        dp[node][0] = 1;
    }
    else {
        ll whiteVal = 1, blkVal = 1;
        for (auto u : adj[node]) {
            if (u != par) {
                solve(u, node);
                whiteVal *= ((dp[u][1] % MOD) + (dp[u][0] % MOD)) % MOD;
                blkVal *= (dp[u][0] % MOD);
                blkVal %= MOD;
                whiteVal %= MOD;
            }
        }
        dp[node][0] = whiteVal % MOD;
        dp[node][1] = blkVal % MOD;
    }
}

int main()
{
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //root tree at one
    solve(1, 1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}
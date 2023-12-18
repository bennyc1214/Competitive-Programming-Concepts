#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <bits/stdc++.h>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define f first
#define s second
#define ll long long
#define mp make_pair
#define p push
#define pf push_front
#define pb push_back
#define pii pair<int, int>
#define pis pair<int, string>
#define pq priority_queue
#define pll pair<ll, ll>

const int M = 16e6+1;
pii adj[M];
bitset<M> vis;
int inds[M];
int A, B;
queue<int> q;

void bfs(int num) {
	if (vis[num]) return;
	vis[num] = 1;
	if (vis[A*B]) return;
	q.p(num);
	while (!q.empty()) {
		int g = q.front();
		q.pop();
		for (int i = inds[g]; i < M; i++) {
			if (adj[i].f!=g) break;
			if (!vis[adj[i].s]) {
				if (adj[i].s==A*B) {
					vis[A*B]= 1;
					return;
				}
				q.p(adj[i].s);
				vis[adj[i].s] = 1;
			}
		}
	}
}

bool can_escape(int m, int n, std::vector<std::vector<int>> v) {
	A=m;
	B=n;
	int ind = 0;
	for (int i = 1; i<=m; i++) {
		for (int j = 1; j <=n; j++) {
			adj[ind] = mp(i*j, v[i][j]);
			ind++;
		}
	}
	sort(adj, adj+ind);
	int cur = -1;
	//int index=0;
	for (int i = 0; i < ind; i++) {
		if (adj[i].f!=cur) {
			cur = adj[i].f;
			inds[adj[i].f] = i; 
		}
	}
	bfs(1);
	return vis[m*n];
}


int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
}
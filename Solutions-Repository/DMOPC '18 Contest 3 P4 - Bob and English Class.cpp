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
#define mp make_pair
#define p push
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define pis pair<int, string>
#define pii pair<int, int>

const int M = 2e5+5;
int n, k, rt;
vector<pii> adj[M];
int sz[M], a[M];
ll ans = 0;

void dfs1(int u, int pa) {
	sz[u] = a[u];
	for (pii e : adj[u]) {
		if (e.first==pa) continue;
		dfs1(e.f, u); sz[u] += sz[e.f];
	}
}

int getCentroid(int u, int pa, int tot) {
	for (pii v: adj[u]) {
		if (v.f!=pa and sz[v.f]*2>tot) return getCentroid(v.f, u, tot);
	}
	return u;
}

void dfs2(int u, int pa, int d) {
	ans+= 1LL * a[u]*d;
	for (pii e: adj[u]) {
		int v = e.first, w = e.second;
		if (v!=pa) dfs2(v, u, d+w);
		
	}
}
int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i =1, x; i <=k; i++) {
    	cin >> x; a[x]++;
	}
	for (int i = 1, u, v, w; i<n; i++) {
		cin >> u >> v >> w; adj[u].pb({v, w}); adj[v].pb({u, w});
	}
	dfs1(1, 0); rt = getCentroid(1, 0, k); dfs2(rt, 0, 0);
	cout << ans << "\n";
}
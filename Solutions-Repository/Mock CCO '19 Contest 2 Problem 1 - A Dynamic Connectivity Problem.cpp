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
#define pf push_forward
#define pb push_back
#define pii pair<int, int>
#define pis pair<int, string>

int n, m, k;
int parent[400000], sz[400000];
bool vis[400000];
map<int, vector<pii> > edges;
stack<int> order;
int ans;
vector<int> answers;

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;	
}

int root(int v) {
	if (v==parent[v]) return v;
	return parent[v] = root(parent[v]);
}

void unions(int a, int b) {
	a = root(a);
	b = root(b);
	if (a!=b) {
		if (sz[a]<sz[b]) swap(a, b);
		parent[b] = a;
		sz[a]+=sz[b];
	}
	
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <n ;i++) {
    	make_set(i);
	}
    int a, b;
    for (int i = 0; i < m; i++) {
    	cin >> a >> b;
    	edges[a].pb(mp(a, b));
    	edges[b].pb(mp(b, a));
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a;
		vis[a]=1;
		order.p(a);
	}
	
	for (int i = 0; i <n ;i++) {
		if (!vis[i]) {
			for (auto u : edges[i]) {
				if (!vis[u.s]) {
					unions(u.f, u.s);
				}
				
			}
		}
	}
	
	for (int i = 0; i <n; i++) {
		if (root(i)==i and !vis[i]) ans++;
	}
	answers.pb(ans);
	while (!order.empty()) {
		int g = order.top();
		order.pop();
		vis[g]=0;
		bool first = true;
		//if (edges[g].size()==0) ans++;
		int added = 0;
		for (auto u : edges[g]) {
			if (!vis[u.s]) {
				bool flag = root(u.f)==root(u.s);
			//	if (!flag) cout << "These are the two unconnected nodes and finally, the node that has been added " << u.f << " " << u.s << " " << g << "\n";
				unions(u.f, u.s);
				added++;
				if(!flag)  {
					if (!first) {
						ans--;
					//	cout << "Answer has been decremented\n";
					}
					
				}
				first = false;
			}
			
		}
		if (added==0) ans++;
		answers.pb(ans);
	}
	reverse(answers.begin(), answers.end());
	for (auto u : answers) {
		cout << u << "\n";
	}
}
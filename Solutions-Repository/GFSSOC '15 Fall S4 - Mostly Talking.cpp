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
#define pq priority_queue
#define pll pair<long long, long long>

int n, m, d;
const int M = 5*1e5+1;
pq<pll, vector<pll>, greater<pll>> q;
pq<pll, vector<pll>, greater<pll>> qN;
vector<pll> adj[M]; vector<pll> adjN[M];
vector<pair<pii, int> > secrets;
ll costs[M]; ll costsN[M];
ll ans;

void dijkstra() {
	for (int i = 1; i <=n; i++) {
		costs[i] = LLONG_MAX;
	}
	costs[1] = 0;
	q.p({0, 1});
	while (!q.empty()) {
		pll u = q.top();
		q.pop();
		if (u.f!=costs[u.s]) continue;
		for (auto j : adj[u.s]) {
			if (costs[j.f]>u.f+j.s) {
				costs[j.f] = u.f+j.s;
				q.p({costs[j.f], j.f});
			}
		}
	}
}

void dijkstraN() {
	for (int i = 1; i <=n; i++) {
		costsN[i] = LLONG_MAX;
	}
	costsN[n] = 0;
	qN.p({0, n});
	while (!qN.empty()) {
		pll u = qN.top();
		qN.pop();
		if (u.f!=costsN[u.s]) continue;
		for (auto j : adjN[u.s]) {
			if (costsN[j.f]>u.f+j.s) {
				costsN[j.f] = u.f+j.s;
				qN.p({costsN[j.f], j.f});
			}
		}
	}
}

void showdist() {
	for (int i = 1; i <=n; i++) {
		cout << costsN[i] << " ";
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i< m; i++) {
		cin >> a >> b >> c;
		adj[a].pb(mp(b, c));
		adjN[b].pb(mp(a, c));
	}
	cin >> d;
	for (int i = 0; i < d; i++) {
		cin >> a >> b >> c;
		secrets.pb(mp(mp(a, b), c));
	}
	dijkstra();
	dijkstraN();
	ans = costs[n];
	//what if without secret, cannot get to n?
	for (auto u : secrets) {
		//case 1: both are attached to 1 and N
		if (costs[u.f.f]!=LLONG_MAX and costsN[u.f.f]!=LLONG_MAX and costs[u.f.s]!=LLONG_MAX and costsN[u.f.s]!=LLONG_MAX) {
			ans = min(ans, u.s+costsN[u.f.s]+costs[u.f.f]);
		//	cout << "Case 1: " << u.s+costsN[u.f.s]+costs[u.f.f] << endl;
		}
		//case 2: u.f.f is attached to both 1 and N, u.f.s is only attached to N
		else if (costs[u.f.f]!=LLONG_MAX and costsN[u.f.f]!=LLONG_MAX and costsN[u.f.s]!=LLONG_MAX) {
			ans = min(ans, u.s+costsN[u.f.s]+costs[u.f.f]);
		//	cout << "Case 2: " << u.s+costsN[u.f.s]+costs[u.f.f] << endl;
		}
		//case 3: u.f.f is only attached to 1, u.f.s is attached to both 1 and N
		else if (costs[u.f.f]!=LLONG_MAX  and costs[u.f.s]!=LLONG_MAX and costsN[u.f.s]!=LLONG_MAX) {
			ans = min(ans, u.s+costsN[u.f.s]+costs[u.f.f]);
			//cout << "Case 3: " << u.s+costsN[u.f.s]+costs[u.f.f] << endl;
		}
		//case 4: u.f.f is only attached to 1, u.f.s is attached to only N
		else if (costs[u.f.f]!=LLONG_MAX  and costsN[u.f.s]!=LLONG_MAX) {
			ans = min(ans, u.s+costsN[u.f.s]+costs[u.f.f]);
			//cout << "Case 4: " << u.s+costsN[u.f.s]+costs[u.f.f] << endl;
		}
	}
	if (ans == LLONG_MAX) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
	}
}
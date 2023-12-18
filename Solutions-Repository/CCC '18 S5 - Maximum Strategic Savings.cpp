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
#define ull unsigned long long 
int n, m, p, q, ccount, pcount;
const int MM = 1e5+1;
int cparent[MM], pparent[MM];
int szp[MM], szc[MM];
vector<pair<pll, pll> > edges;

void make_set(int v) {
	cparent[v] = v;
	pparent[v] = v;
	szp[v] = 1;
	szc[v] = 1;
}

int croot(int v) {
	if (cparent[v] == v) return v;
	return cparent[v] = croot(cparent[v]);
}

int proot(int v) {
	if (pparent[v] == v) return v;
	return pparent[v] = proot(pparent[v]);
}

void cunion(int a, int b) {
	a = croot(a);
	b = croot(b);
	if (a!=b) {
		if (szc[a]<szc[b]) swap(a, b);
		cparent[b]= a;
		szc[a]+=szc[b];
	}
}

void punion(int a, int b) {
	a = proot(a);
	b = proot(b);
	if (a!=b) {
		if (szp[a]<szp[b]) swap(a, b);
		pparent[b]= a;
		szp[a]+=szp[b];
	}
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p >> q;
    int a, b, c;
    for (int i = 0; i < p; i++) {
		cin >> a >> b >> c;
		edges.pb(mp(mp(c, 0), mp(a, b)));
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		edges.pb(mp(mp(c, 1), mp(a, b)));
	}
	for (int i = 1; i <=max(n, m); i++) {
		make_set(i);
	}
	sort(edges.begin(), edges.end());
	ull cost=0;
	for (auto u : edges) {
		if (u.f.s==0) {
			//connects cities from the same planet
			if (croot(u.s.f)!=croot(u.s.s)) {
				ccount++;
				cost+=u.f.f*(n-pcount);
				cunion(u.s.f, u.s.s);
			}
		}
		else {
			if (proot(u.s.f)!=proot(u.s.s)) {
				pcount++;
				cost+=u.f.f*(m-ccount);
				punion(u.s.f, u.s.s);
			}
		} 
	}
	//now calculate original cost
	ull origcost=0;
	for (auto u : edges) {
		if (u.f.s==0) {
			origcost+=u.f.f*(n);
		}
		else {
			origcost+=u.f.f*(m);
		}
	}
	cout << origcost-cost << "\n";
	//cout << "This was origcost, and this was cost " << origcost << " " << cost;
}
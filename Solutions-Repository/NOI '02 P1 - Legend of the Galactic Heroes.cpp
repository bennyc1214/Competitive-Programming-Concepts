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

int t, x, y;
pii parent[30001];
int sz[30001];
char c;
//parent[i].f represents the parent of i
//parent[i].s represents the distance to the parent of i
void make_set(int v) {
	parent[v] = mp(v, 0);
	sz[v]=1;
}

pii root(int v) {
	if (v!=parent[v].f) {
		int len = parent[v].s;
		parent[v] = root(parent[v].f);
		parent[v].s+=len;
	}
	return parent[v];
}

void unions(int a, int b) {
	//a will always be behind b
	a = root(a).f;
	b = root(b).f;
	if (a!=b) {
		parent[a] = mp(b, sz[b]);
		sz[b]+=sz[a];
	}
	
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= 30000; i++) make_set(i);
    while (t--) {
    	cin >> c >> x >> y;
    	if (c=='M') {
    		unions(x, y);
		}
		else {
			if (root(x).f == root(y).f) {
				cout << abs(root(x).s-root(y).s)-1 << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
}
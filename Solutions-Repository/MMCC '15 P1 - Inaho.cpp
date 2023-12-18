#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <bits/stdc++.h>
#include "inaho.h"
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
#define pbi pair< pair<int, int> , bool >

int parent[500001], sz[500001];
stack<pbi> queries;

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int root(int v) {
	if (v==parent[v]) return v;
	return root(parent[v]);
	//no path compression, so removing edges is easy?
}

void unions(int a, int b) {
	a = root(a);
	b = root(b);
	if (a!=b) {
		if (sz[a]<sz[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sz[a]+=sz[b];
		queries.p(mp(mp(a, b), 1));
		//a will always be >= b
	}
	else {
		if (sz[a]<sz[b]) swap(a, b);
		queries.p(mp(mp(a, b), 0));
	}
}

void Init(int n) {
	for (int i =1; i<=n; i++) {
		make_set(i);
	}
}

void AddEdge(int a, int b) {
	unions(a, b);
}

void RemoveLastEdge() {
	pbi g = queries.top();
	queries.pop();
	if (g.s) {
		sz[g.f.f]-=sz[g.f.s];
		parent[g.f.s] = g.f.s;
	}
}

int GetSize(int u) {
	return sz[root(u)];;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
}
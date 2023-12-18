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
#define pll pair<long long, long long>

const int MM = 1e6+2;
int n; unordered_map<int, ll> dp;


ll f (int w) {
	if (w<=2) {
		return 1;
	}
	if (dp.count(w)) return dp[w];
	int up = sqrt(w); ll ret =0;
	for (int i = 2; i<=up; i++) ret += f(w/i);
	for (int i = up, last = up; i >=1; i--) {
		ret += (w/i-last)*f(i);
		last = w/i;
	}
	return dp[w]=ret;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << f(n) << "\n";
}
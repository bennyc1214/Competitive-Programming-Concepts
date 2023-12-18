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

const int M = 3003;
int n, m, a[M], b[103], dp[M][2][103][103];

int solve(int i, int can, int L, int R) {
	if (dp[i][can][L][R] != -1) return dp[i][can][L][R];
	int ans = 0;
	if (i<=n) {
		ans =max(ans, solve(i+1, true, L, R));
		if (can) ans = max(ans, a[i]+solve(i+1, false, L, R));
	}
	if (L<=R) {
		ans = max(ans, solve(i, true, L+1, R));
		if (can) ans = max(ans, b[R]+solve(i, false, L, R-1));
	}
	return dp[i][can][L][R] = ans;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n ; memset(dp, -1, sizeof(dp));
    for (int i = 1; i <=n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <=m; i++) {
    	cin >> b[i];
	}
	sort(b+1, b+m+1);
	cout << solve(1, 1, 1, m) << "\n";
}
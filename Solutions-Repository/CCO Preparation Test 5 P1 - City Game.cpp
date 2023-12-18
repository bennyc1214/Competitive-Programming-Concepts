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

int t, r, c, ans;
const int M = 1005;
int h[M];
char in;

int getMaxRectInHist(int h[]) {
	stack<int> stk;
	int mx = 0;
	for (int i = 1; i<=c+1; i++) {
		while (!stk.empty() and h[stk.top()]>=h[i]) {
			int id = stk.top();
			stk.pop();
			int rit = i;
			int lft = stk.empty() ? 0 : stk.top();
			mx = max(mx, h[id]*(rit-lft-1));
		}
		stk.p(i);
	}	
	return mx;
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
    	cin >> r  >> c;
    	memset(h, 0, sizeof(h));
    	ans = 0;
    	//cin >> r >>c;
    	for (int i = 1; i <=r ; i++) {
    		for (int j = 1; j <= c; j++) {
    			cin >> in;
    			if (in=='R') {
    				h[j] = 0;
				}
				else {
					h[j]++;
				}
			}
			ans = max(ans, getMaxRectInHist(h));
		}
		
		cout << ans*3 << endl;
	}

}
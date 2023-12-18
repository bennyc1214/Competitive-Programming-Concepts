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

int t, n;
const int MM = 1e6+2;
bool f[MM];
void init() {
	f[0]=f[1]=1;
	for (int i= 2; i <MM; i++) {
		if (!f[i]) {
			for (int j = 2*i; j <MM; j+=i) f[j]=1;
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> t;
    while (t--) {
    	cin >> n;
    	if (n==1) cout << "1\n";
    	else if (n==2 or n==3) cout << "-1\n";
    	else if (n==4) cout << "3 1 4 2\n";
    	else if (n==5) cout << "1 3 5 2 4\n";
    	else if (n==6) cout << "1 3 5 2 4 6\n";
    	else if (n==7) cout << "1 3 5 7 2 4 6\n";
    	//hardcoded cases for small numbers
    	else {
    		bool odd = n%2;
    		if (odd) n--;
    		int x = 0, y = 0;
    		for (x = 3; x*2<=n; x++) {
    			if (!f[x] and !f[n-x]) {
    				break;
				}
			}
			vector<int> ans; int cur = 0;
			for (int i = 0; i <n; i++) {
				ans.pb(cur);
				cur = (cur+x)%n;
			}
			if (odd) ans.pb(n);
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i]+1 << " \n"[i==ans.size()-1];
			}
		}
	}
}
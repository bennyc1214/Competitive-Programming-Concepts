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
#define pll pair<ll, ll>

const int M = 405;
int n, k;
int dp[M][M];
//dp[i][j] is minimum amount of treats needed for i cows with j troughs
int cows[M];

void show() {
	for (int i = 0; i <=n; i++) {
		for (int j = 0; j <=k+1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
    	cin >> cows[i];
	}
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <n; i++) {
		for (int j = i; j <n; j++) {
			int oth = j-i;
			int c =0;
			for (int g = i; g <=j; g++) {
				c += max(0, oth-cows[g]);
			}
			//cout << "This is c " << c << endl;
			for (int g = 0; g <=k; g++) {
				dp[j+1][g+1] = min(dp[j+1][g+1], dp[i][g]+c);
			}
		}
	}
	cout << dp[n][k+1] << endl;
	//show();
}



/*
for (int i =0; i <=n; i++) {
		int tot = 0;
		//i is the length of the trough
		for (int j = 0; j < i; j++) {
			//j is all the cows before to calculate
			tot += (max(0, i-cows[j]));
		}
		dp[i][1] = tot;
	}
	
	for (int i = 0; i <=k+1; i++) {
		dp[0][i] = 0;
	}
	
	for (int i = 0; i <=n; i++) {
		cout << dp[i][1] << " ";
	}

	for (int i = 2; i <=n; i++) {
		//i represents the amount of cows
		for (int j = i; j<=n; j++) {
			int len = j-i+1, tot = 0;
			
			for (int g = j; g>=0; g--) {
				tot += 
			}
			//j represents the amount of troughs
			//dp[i][j] is what we are solving for
			//dp[i][j] = min(dp[i][j], dp[i][j-1])
			//dp[i][j] = min(dp[i][j], dp[i-1][j-1])
			//dp[i][j] = min(dp[i][j], dp[i-2][j-1])
		}
	}
*/
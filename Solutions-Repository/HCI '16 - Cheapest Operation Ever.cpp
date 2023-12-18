#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pii pair<int, int>
#define pis pair<int, string>
#define p push
#define ll long long
#define ull unsigned long long
#define ep emplace_back 

const int M = 1e5+2;
ll dp[M];
int p[M];
int N, H;
deque<int> q; //used to store decision points

double f(int k, int j) {
	return (double) ((dp[j]+1LL*p[j+1]*p[j+1]) - (dp[k] +1LL*p[k+1]*p[k+1]))/(2LL*(p[j+1]-p[k+1]));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;
    for (int i = 1; i <=N; i++) {
		cin >> p[i];
	}
	memset(dp, 0x3f, sizeof(dp)); dp[0]=0;
	q.pb(0);
	for (int i = 1; i <=N; i++) {
		while (q.size() >=2 && f(q[0], q[1])<=p[i]) q.pop_front();
		int j = q[0];
		dp[i] = dp[j]+1LL*(p[i]-p[j+1])*(p[i]-p[j+1])+H;
		while (q.size() >=2 && f(q[q.size()-2], q.back()) >= f(q.back(), i)) q.pop_back();
		q.pb(i);
	}
	cout << dp[N] << endl;
}
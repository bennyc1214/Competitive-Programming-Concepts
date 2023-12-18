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

const int M = 1e5+5;

ll d0[M], d1[M], d2[M];
ll n, t;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
	ll l, r, a, b, c;
    for(int i = 0; i < n; i++) {
		cin >> l >> r >> a >> b >> c;
		d2[l] +=a;
		d2[r+1] -=a;
		d1[l] += b-2*a*l;
		d1[r+1] -=b-2*a*l;
		d0[l]+= (a*l*l+c-b*l);
		d0[r+1]-= (a*l*l+c-b*l);
	}
	for (int i = 2; i <= t; i++) {
		d1[i] += d1[i-1];
		d2[i] += d2[i-1];
		d0[i] += d0[i-1];
	}
	for (ll i = 1; i <=t; i++) {
		cout << d0[i]+d1[i]*i + d2[i]*i*i << " ";
	}
	cout << endl;
}
#include <bits/stdc++.h>

using namespace std;

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

ll A, B;
string a, b;
ll dp[20][10][10][2][2][2][2];
ll smol[20];
ll big[20];

void show() {
	for (int i = 0; i < b.size(); i++) cout << big[i];
	cout << endl;
	for (int i = 0; i <b.size(); i++) cout << smol[i];
	cout << endl;
}

ll fun(ll pos, ll lst, ll lst2, ll lst0, ll lst20, bool upp, bool lo) {
	if (dp[pos][lst][lst2][lst0][lst20][upp][lo]!=-1) return dp[pos][lst][lst2][lst0][lst20][upp][lo];
	if (pos==b.size()) return 1;
	ll ubound = upp? big[pos] : 9;
	ll lbound = lo? smol[pos] : 0;
	ll ret = 0;
	for (int i = lbound; i <=ubound; i++) {
		if ((i!=lst or lst0) and (i!=lst2 or lst20)) {
			ret += fun(pos+1, i, lst, (lst0 and i==0), lst0 , (upp and i==ubound), (lo and i==lbound));
		}
	}
	return dp[pos][lst][lst2][lst0][lst20][upp][lo] = ret;
}


int main() {
	cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    a = to_string(A);
    b = to_string(B);
    for (int i = 0; i < b.size(); i++) {
    	big[i] = b[i]-'0';
	}
	int cnt=0;
	for (int i = 0; i < b.size()-a.size(); i++) {
		smol[i] = 0;
		cnt++;
	}
	//cout << cnt;
	for (int i = b.size()-a.size(); i<b.size(); i++) {
	//	cout << "This is i " << i << endl;
		smol[i] = a[i-b.size()+a.size()] -'0';
	}
	memset(dp, -1, sizeof(dp));
	cout << fun(0, 0, 0, 1, 1, 1, 1) << endl;
	
}
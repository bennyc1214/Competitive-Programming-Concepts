#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 5e5+5;
int n, s, a[MM], f[MM];
pair<bool, ll> check(ll m){
    ll req = 0;  cl(f, 0);
    for(int i=1; i<=n; i++){
        if(a[i] <= (m+1)*s) req += ((m+1)*s - a[i])/s;
        if(req > m*s) return {true, m*s};
    }
    for(int i=1; i<=n; i++){
        if(a[i] <= (m+1)*s) f[a[i]%s]++;
    }
    for(int i=1; i<=n; i++) {
        req += f[i];
        if(req > m*s + i) return {true, m*s+i};
    }
    return {false, 0};
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    if(s >= n){
        for(int i=1; i<=n; i++)
            if(a[i] + 1 <= i) return printf("%d\n", a[i]), 0;
        printf("INF\n"); return 0;
    }
    ll lo = 0, hi = 1e12, pos = 0;
    while(lo <= hi){
        ll m = (lo + hi)/2;
        if(check(m).f){ pos = m; hi = m - 1;}
        else lo = m + 1;
    }
    printf("%lld\n", check(pos).s);
}
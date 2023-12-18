#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
int N, P; ll psa[MM], p[MM], bit[MM], ans;
void update(int pos, int val){
    pos++;
    for(int i=pos; i<MM; i+=i&-i) bit[i] += val;
}
ll query(int pos){
    pos++;  ll sum = 0;
    for(int i=pos; i>0; i-=i&-i) sum += bit[i];
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> psa[i];
    cin >> P;
    for(int i=1; i<=N; i++){
        psa[i] = psa[i] - P + psa[i-1];  p[i] = psa[i];
    }
    sort(p, p+N+1); int sz = unique(p, p+N+1) - p;
    for(int i=0; i<=N; i++){
        int rk = lower_bound(p, p+sz+1, psa[i]) - p;
        ans += query(rk); update(rk, 1);
    }
    cout << ans << "\n";
}
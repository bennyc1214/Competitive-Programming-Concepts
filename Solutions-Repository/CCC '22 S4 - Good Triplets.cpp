#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+4;
int N, C, a[2*MM], cnt[MM]; ll ans;
ll f(int k){ return 1LL*k*(k-1)/2;}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    for(int i=1; i<=N; i++){
        cin >> a[i];  a[i+N] = a[i] + C;
        cnt[a[i]]++;
    }
    sort(a+1, a+2*N+1);
    for(int i=1, j=1; i<=N; i++){
        while(2*(a[j] - a[i]) <= C) j++;
        ans -= f(j - i -1);
    }
    ans += 1LL*N*(N-1)*(N-2)/6;
    if(C % 2 == 0){
        for(int i=C/2; i<=C; i++)
            ans += 1LL*cnt[i]*f(cnt[i-C/2]) + 1LL*f(cnt[i])* cnt[i-C/2];
    }
    cout << ans << endl;
}
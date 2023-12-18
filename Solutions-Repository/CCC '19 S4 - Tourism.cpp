#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
typedef long long ll;
int N, K, a[MM], pmx[MM], day[MM];  ll dp[MM], dp1[MM], dp2[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> a[i];  day[i] = (i+K-1)/K;
    }
    for(int i=1; i<=K; i++){
        dp[i] = pmx[i] = max(pmx[i-1], a[i]);
    }
    for(int i=K+1; i<=N; i+=K) {
        int smx = 0;
        for(int j=(day[i]-1)*K; j > (day[i]-2)*K; j--){
            dp1[j] = max(dp1[j+1], dp[j]);
            dp2[j] = max(dp2[j+1], dp[j] + smx);
            smx = max(smx, a[j]);
        }
        for(int j=i; j<=min(i+K, N); j++){
            if(day[j] == day[j-1] ) pmx[j] = max(pmx[j-1], a[j]);
            else pmx[j] = a[j];
            dp[j] = max(dp1[j-K] + pmx[j], dp2[j-K]);
        }
    }
    cout << dp[N] << endl;
}
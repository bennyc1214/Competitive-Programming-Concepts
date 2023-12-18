#include <bits/stdc++.h>

using namespace std;

const int M = 405;
int n, psa[M], ans;
int dp[M][M];

int sum(int l, int r) {
    return psa[r]-psa[l-1];
}

int main() {
    cin >> n;
    int x;
    for (int i = 1; i <=n; i++) {
        cin >> x;
        psa[i] = psa[i-1] +x;
        ans = max(ans, x);
        dp[i][i] = 1;
    }
    for (int len = 1; len<n; len++) {
        for (int l = 1, r =l+len; r<=n; l++, r++) {
            for (int p = l, q=r; p+1<=q; ) {
                if (dp[l][p] and dp[q][r] and (p+1==q || dp[p+1][q-1]) and sum(l, p)==sum(q, r)) {
                    dp[l][r] = 1;
                }
                if (sum(l, p) < sum(q, r)) p++;
                else q--;
            }
            if (dp[l][r]) ans = max(ans, sum(l, r));
        }
    }
    cout << ans << endl;
}
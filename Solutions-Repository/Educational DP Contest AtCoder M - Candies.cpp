#include <iostream>
#include <algorithm>

using namespace std;

/*
dp[children][candies]
dp[children][candies] =
0 if children are 0:(can't divide by 0 so invalid)
1 if children are 1:(1 child must get all of the candies)
1 if candies are 0:(only one way to divide 0 candies, all children get none)
sum of (dp[children-1][candies]->dp[children-1][candies-aj])
*/

typedef long long ll;
const int M = 105;
const ll MOD = 1e9 + 7;
int n, k;
ll candies[M];
ll dp[M][100009];
ll psa[100009];

void show() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> candies[i];
    }
    //sets amount of ways to share when there are no candies to be 1
    for (int i = 1; i <= n; i++) dp[i][0] = 1;
    //sets amount of ways to share when there is one child to be 1
    for (int i = 0; i <= k; i++) if (candies[1] >= i) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        //compute psa here  
        psa[0] = dp[i - 1][0] % MOD;
        for (int j = 1; j <= k; j++) {
            psa[j] = (dp[i - 1][j]) % MOD + (psa[j - 1]) % MOD;
            psa[j] %= MOD;
        }
        for (int j = 1; j <= k; j++) {
            dp[i][j] = psa[j] % MOD;
            if (j - candies[i] - 1 >= 0) {
                dp[i][j] -= (psa[j - candies[i] - 1] + MOD) % MOD;
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
            //dp[i][j]-psa[max(0LL, j - candies[i] - 1)];

        }
    }
    //show();
    cout << dp[n][k] << endl;
}
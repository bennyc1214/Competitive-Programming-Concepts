#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2002;
struct E {int u, v; ll d;};
int N, x[MM], y[MM], dp[MM], tmp[MM]; vector<E> edge; ll mx[MM];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> x[i] >> y[i];
        ll d = 1LL*x[i]*x[i] + 1LL*y[i]*y[i];
        edge.push_back(E{0, i, d});
        for(int j=1; j<i; j++){
            d=1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j]);
            edge.push_back(E{j, i, d});
        }
    }
    sort(edge.begin(), edge.end(), [](E &a, E &b){return a.d < b.d;});
    for(E e : edge){
        int u = e.u, v = e.v;  ll d = e.d;
        if(d > mx[u]){ mx[u] = d; tmp[u] = dp[u];}
        if(d > mx[v]){ mx[v] = d; tmp[v] = dp[v];}
        dp[u] = max(dp[u], tmp[v] + 1);
        if(u) dp[v] = max(dp[v], tmp[u]+1);
    }
    cout << dp[0] << endl;
}
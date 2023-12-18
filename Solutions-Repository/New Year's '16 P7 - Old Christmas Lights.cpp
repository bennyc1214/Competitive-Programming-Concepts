#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+5, LOG=17;
int N, K, Q, a[MM], lft[MM], rit[MM]; pi st[LOG][MM]; deque<int> mi, mx;
pi RMQ(int x, int y){
    int k = log2(y-x+1);
    return max(st[k][x], st[k][y-(1<<k)+1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> a[i];
    int l, r;
    for(l=1, r=1; r<=N; r++) {
        while(!mi.empty() && a[mi.back()] > a[r]) mi.pop_back();
        while(!mx.empty() && a[mx.back()] < a[r]) mx.pop_back();
        mi.push_back(r);  mx.push_back(r);
        while(a[mx.front()] - a[mi.front()] > K) {
            if(mx.front()==l) mx.pop_front();
            if(mi.front()==l) mi.pop_front();
            rit[l] = r - l;  l++;
        }
        lft[r] = r - l + 1;
    }
    for(; l<=N; l++) rit[l] = N+1-l;
    for(int i=1; i<=N; i++) st[0][i] = {rit[i], -i};
    for(int k=1; k<LOG; k++)
        for(int i=1; i+(1<<k)-1 <= N; i++)
            st[k][i] = max(st[k-1][i], st[k-1][i+(1<<k-1)]);
    cin >> Q;
    for(int i=1, x, y; i<=Q; i++) {
        cin >> x >> y;
        if(rit[x] >= y-x+1) cout << x << " " << y << "\n";
        else {
            pi tmp = RMQ(x, y-lft[y]);
            if(tmp.first >= lft[y])
                cout << (-tmp.second) << " " << -tmp.second + tmp.first - 1 << "\n";
            else
                cout << y-lft[y]+1 << " " << y << "\n";
        }
    }
}
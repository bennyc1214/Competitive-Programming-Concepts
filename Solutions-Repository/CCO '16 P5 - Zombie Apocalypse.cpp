#include <bits/stdc++.h>
using namespace std;
struct win {int x1, x2, y1, y2;} w[2001];
int N, M, K, Q, x[2001], y[2001], cntx, cnty; short dif[4002][4002]; map<int, int> cx, cy; vector<int> rx, ry; long long ans=0;
long long getArea(int d){
    memset(dif, 0, sizeof(dif)); memset(w, 0, sizeof(w));
    cx.clear(); cy.clear(); rx.clear(); ry.clear();  ans = 0;
    for(int i=1; i<=K; i++){
        w[i].x1 = max(x[i] - d - 1, 0); w[i].x2 = min(x[i] + d, N);
        w[i].y1 = max(y[i] - d - 1, 0); w[i].y2 = min(y[i] + d, M);
        cx[w[i].x1]=cx[w[i].x2]=0; cy[w[i].y1]=cy[w[i].y2]=0;
    }
    cntx=1; cnty=1;
    for(auto &it: cx){ it.second = cntx++; rx.push_back(it.first); }
    for(auto &it: cy){ it.second = cnty++; ry.push_back(it.first); }
    for(int i=1; i<=K; i++){
        dif[ cx[w[i].x1] ][ cy[w[i].y1] ] ++;
        dif[ cx[w[i].x2] ][ cy[w[i].y2] ] ++;
        dif[ cx[w[i].x1] ][ cy[w[i].y2] ] --;
        dif[ cx[w[i].x2] ][ cy[w[i].y1] ] --;
    }
    for(int i=1; i<cntx; i++){
        for(int j=1; j<cnty; j++){
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
            if(dif[i][j] > 0) ans += 1LL*(rx[i]-rx[i-1])*(ry[j]-ry[j-1]);
        }
    }
    return ans;
}
int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=K; i++) cin >> x[i] >> y[i];
    cin >> Q;
    if(Q == 0) cout << K << "\n";
    else cout << getArea(Q) - getArea(Q-1) << "\n";
}
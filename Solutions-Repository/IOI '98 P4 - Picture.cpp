#include <bits/stdc++.h>
using namespace std;
struct SEG{int k, lo, hi, flag; }sx[10002], sy[10002];
int N, ans, tx, ty, cnt[10002]; vector<int> px, py;
bool cmp(SEG x, SEG y) { return x.k < y.k || (x.k==y.k && x.flag>y.flag); }
int main(){
    scanf("%d", &N);
    for(int i=0, x1, x2, y1, y2; i<N; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        sy[ty++] = SEG{x1, y1, y2, 1};
        sy[ty++] = SEG{x2, y1, y2, 0};
        sx[tx++] = SEG{y1, x1, x2, 1};
        sx[tx++] = SEG{y2, x1, x2, 0};
        py.push_back(y1); py.push_back(y2);
        px.push_back(x1); px.push_back(x2);
    }
    sort(sy, sy+ty, cmp); sort(sx, sx+tx, cmp);
    sort(py.begin(), py.end()); sort(px.begin(), px.end());
    for(int i=0; i<ty; i++){
        int l=lower_bound(py.begin(), py.end(), sy[i].lo)-py.begin();
        int r=lower_bound(py.begin(), py.end(), sy[i].hi)-py.begin();
        if(sy[i].flag){
            for(int j=l; j<r; j++){
                if(!cnt[j]) ans += py[j+1]-py[j];
                cnt[j]++;
            }
        }else{
            for(int j=l; j<r; j++){
                cnt[j]--;
                if(!cnt[j]) ans += py[j+1]-py[j];
            }
        }
    }
    for(int i=0; i<tx; i++){
        int l=lower_bound(px.begin(), px.end(), sx[i].lo)-px.begin();
        int r=lower_bound(px.begin(), px.end(), sx[i].hi)-px.begin();
        if(sx[i].flag){
            for(int j=l; j<r; j++){
                if(!cnt[j]) ans += px[j+1]-px[j];
                cnt[j]++;
            }
        }else{
            for(int j=l; j<r; j++){
                cnt[j]--;
                if(!cnt[j]) ans += px[j+1]-px[j];
            }
        }
    }
    printf("%d\n", ans);
}
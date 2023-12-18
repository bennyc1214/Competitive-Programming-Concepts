#include <bits/stdc++.h>
using namespace std;
struct LINE{int x, yl, yh, v;}line[200002];
struct NODE{int v, lazy;} seg[3*8001];
struct POINT{int x, y;} mag[12], met[100002];
int M, N, dis[100002], tot, top=8000, ans;
bool cmp(LINE a, LINE b){ return a.x<b.x || (a.x==b.x && a.v<b.v);}
void push_down(int rt){
    if(seg[rt].lazy){
        seg[rt<<1].lazy += seg[rt].lazy; seg[rt<<1|1].lazy += seg[rt].lazy;
        seg[rt<<1].v += seg[rt].lazy; seg[rt<<1|1].v += seg[rt].lazy;
        seg[rt].lazy = 0;
    }
}
void update(int l0, int r0, int v, int l, int r, int rt){
    if(l0<=l && r<=r0){
        seg[rt].v += v; seg[rt].lazy += v; return;
    }
    push_down(rt);
    int mid = (l+r)/2;
    if(r0 <= mid)  update(l0, r0, v, l, mid, rt<<1);
    else if(l0>mid) update(l0, r0, v, mid+1, r, rt<<1|1);
    else{
        update(l0, mid, v, l, mid, rt<<1);
        update(mid+1, r0, v, mid+1, r, rt<<1|1);
    }
    seg[rt].v = max(seg[rt<<1].v, seg[rt<<1|1].v);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &M);
    for(int i=1; i<=M; i++)
        scanf("%d %d", &mag[i].x, &mag[i].y);
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d %d", &met[i].x, &met[i].y);
        dis[i] = 100000;
        for(int j=1; j<=M; j++){
            int d = abs(met[i].x-mag[j].x)+abs(met[i].y-mag[j].y);
            dis[i] = min(dis[i], d);
        }
        dis[i]--;
        int nx = met[i].y+met[i].x, ny = met[i].y-met[i].x+4000;
        line[tot++]=LINE{nx-dis[i], max(ny-dis[i], 1), min(ny+dis[i], top), 1};
        line[tot++]=LINE{nx+dis[i]+1, max(ny-dis[i], 1), min(ny+dis[i], top), -1};
    }
    sort(line, line+tot, cmp);
    for(int i=0; i<tot; i++){
        update(line[i].yl, line[i].yh, line[i].v, 1, top, 1);
        ans = max(ans, seg[1].v);
    }
    printf("%d\n", ans);

}
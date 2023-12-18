#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct event{
   int type, val, y; ll x;
   event(int id, ll a, int b, int c){ x = a; y = b; val = c; type = id; }
};
int T, NA, t, y; ll x, ft[1000010]; char ch, tmp[102];
bool cmp(event A, event B){ return A.x < B.x || (A.x==B.x && A.y<B.y) || (A.x==B.x && A.y==B.y && A.type < B.type);}
ll sum(int b){
    int sol = 0;
    for(; b; b-=b&-b) sol+=ft[b];
    return sol;
}
void update(int k, int v) {
   for (; k <=1000000; k += (k&(-k)))
       ft[k] += v;
}
int main(){
   //freopen("test.txt", "r", stdin);
   scanf("%d", &T);
   while(T--) {
       scanf("%s", tmp);
       memset(ft, 0, sizeof(ft));
       vector<event> events;
       for (int i = 0; i < 2; i++) {
           scanf("%lld %d %d", &x, &y, &NA);
           for (int j = 0; j < NA; j++) {
               scanf(" %c %d", &ch, &t);
               if (ch == 'R') {
                   events.push_back(event(0, x, y, 1));
                   events.push_back(event(0, x+=t, y, -1));
               } else if (ch == 'L') {
                   events.push_back(event(0, x, y, -1));
                   events.push_back(event(0, x-=t, y, 1));
               } else if (ch == 'D') {
                   events.push_back(event(1, x, y-t, y));
                   y -= t;
               } else {
                   events.push_back(event(1, x, y, y+t));
                   y += t;
               }
           }
       }
       ll ans = 0;
       sort(events.begin(), events.end(), cmp);
        for(event c: events){
           if (c.type == 1) {
               ans += sum(c.val-1) - sum(c.y);
           } else {
               update(c.y, c.val);
           }
       }
       printf("%lld\n", ans);
   }
}
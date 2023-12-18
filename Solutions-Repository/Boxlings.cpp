#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
struct event{ int x, yl, yh, val; };
int N, M, ans, bit[3*MM], cnt; vector<event> vec; map<int, int> mp;
bool cmp(event a, event b){
    if(a.x != b.x) return a.x < b.x;
    else return a.val > b.val;
}
void update(int pos, int val){
    for(int i=pos; i<= cnt; i+=i&-i) bit[i] += val;
}
int query(int pos){
    int sum = 0;
    for(int i=pos; i>0; i-=i&-i) sum += bit[i];
    return sum;
}
int main(){
    cin >> N >> M;
    for(int i=1, r1, c1, r2, c2; i<=N; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1 <= r2 && c1 <= c2) {
            vec.push_back({r1, c1, c2, 1});
            vec.push_back({r2, c1, c2, -1});
            mp[c1] = 0;  mp[c2] = 0;
        }
    }
    for(int i=1, x, y; i<=M; i++){
        cin >> x >> y;
        vec.push_back({x, y, y, 0});  mp[y] = 0;
    }
    for(auto& e: mp) e.second = ++cnt;
    sort(vec.begin(), vec.end(), cmp);
    for(event e: vec){
        if(e.val != 0){
            int lo = mp[e.yl], hi = mp[e.yh];
            update(lo, e.val);  update(hi+1, -e.val);
        }else {
            int pos = mp[e.yl];
            if(query(pos) > 0) ans++;
        }
    }
    cout << ans << endl;
}
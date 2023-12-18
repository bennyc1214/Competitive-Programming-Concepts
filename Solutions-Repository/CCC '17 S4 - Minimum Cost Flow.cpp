#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+2;

struct E {
    int u, v, w, f;
};

int n, m, d, p[M], ans, last;
vector<E> edge;

bool cmp(E x, E y) {
    return x.w < y.w || x.w==y.w && x.f< y.f;
}

int fd(int d) {
    return d == p[d] ? d : p[d] = fd(p[d]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i =1; i <=n; i++) {
        p[i] = i;
    }
    for (int i = 1, u, v, w; i<=m; i++) {
        cin >> u >> v >> w;
        edge.push_back(E{u, v, w, i>n-1});
    }
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 0; i < edge.size(); i++) {
        E e = edge[i];
        int u = fd(e.u), v = fd(e.v);
        if (u!=v) {
            p[u] = v;
            ans += e.f;
            last = i;
        }
    }
    if (edge[last].f) {
        for (int i =1; i <=n; i++) p[i] = i;
        for (int i = 0; i <last; i++) {
            if (!edge[i].f || edge[i].w < edge[last].w) {
                int u = fd(edge[i].u),v = fd(edge[i].v);
                if (u != v) p[u] = v;
            }
        }

        for (int i = last+1; i<edge.size(); i++) {
            if (!edge[i].f && edge[i].w <=d) {
                int u =fd(edge[i].u), v = fd(edge[i].v);
                if (u!=v) {
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
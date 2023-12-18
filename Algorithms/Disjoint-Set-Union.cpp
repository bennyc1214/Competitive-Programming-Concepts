#include <bits/stdc++.h>

using namespace std;

const int M = 2e5+9;
int sz[M], par[M];

void init() {
    //initializes disjoint set union so it is ready to use
    for (int i = 0; i < M; i++) {
        sz[i]=1;
        par[i]=i;
    }
}

int root(int a) {
    if (par[a]==a) return a;
    else return (par[a]=root(par[a]));
}

void unions(int a, int b) {
    a = root(a);
    b = root(b);
    if (a!=b) {
        if (sz[a]<sz[b]) swap(a, b);
        par[b] = a;
        sz[a]+=sz[b];
    }
}

int main() {
    //to check if two elements are connected, check if their roots are the same
    //ie. root(a)==root(b)
    
}
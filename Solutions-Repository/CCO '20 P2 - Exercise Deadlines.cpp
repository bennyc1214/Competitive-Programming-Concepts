#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int M = 2e5+5;
int n, a[M];
vector<int> d[M]; priority_queue<int> q;
int bit[M];

void update(int pos, int val) {
    for (int i = pos; i <M; i+=i&-i) {
        bit[i] += val;
    }
}

int query(int pos) {
    int ret = 0;
    for (int i = pos; i>0; i-=i&-i) {
        ret+=bit[i];
    }
    return ret;
}


int main() {
    cin >> n;
    for (int i =1, x; i <=n; i++) {
        cin >> x;
        d[x].push_back(i);
    }
    for (int i = n; i>=1; i--) {
        for (int x : d[i]) q.push(x);
        if (q.empty()) {
            cout << "-1\n";
            return 0;
        }
        a[i] = q.top();
        q.pop();
    }
    ll ans = 0;

    for (int i= 1; i<=n; i++) {
        update(a[i], 1);
        ans += i-query(a[i]);
    }
    cout << ans << endl;

}#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int M = 2e5+5;
int n, a[M];
vector<int> d[M]; priority_queue<int> q;
int bit[M];

void update(int pos, int val) {
    for (int i = pos; i <M; i+=i&-i) {
        bit[i] += val;
    }
}

int query(int pos) {
    int ret = 0;
    for (int i = pos; i>0; i-=i&-i) {
        ret+=bit[i];
    }
    return ret;
}


int main() {
    cin >> n;
    for (int i =1, x; i <=n; i++) {
        cin >> x;
        d[x].push_back(i);
    }
    for (int i = n; i>=1; i--) {
        for (int x : d[i]) q.push(x);
        if (q.empty()) {
            cout << "-1\n";
            return 0;
        }
        a[i] = q.top();
        q.pop();
    }
    ll ans = 0;

    for (int i= 1; i<=n; i++) {
        update(a[i], 1);
        ans += i-query(a[i]);
    }
    cout << ans << endl;

}#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int M = 2e5+5;
int n, a[M];
vector<int> d[M]; priority_queue<int> q;
int bit[M];

void update(int pos, int val) {
    for (int i = pos; i <M; i+=i&-i) {
        bit[i] += val;
    }
}

int query(int pos) {
    int ret = 0;
    for (int i = pos; i>0; i-=i&-i) {
        ret+=bit[i];
    }
    return ret;
}


int main() {
    cin >> n;
    for (int i =1, x; i <=n; i++) {
        cin >> x;
        d[x].push_back(i);
    }
    for (int i = n; i>=1; i--) {
        for (int x : d[i]) q.push(x);
        if (q.empty()) {
            cout << "-1\n";
            return 0;
        }
        a[i] = q.top();
        q.pop();
    }
    ll ans = 0;

    for (int i= 1; i<=n; i++) {
        update(a[i], 1);
        ans += i-query(a[i]);
    }
    cout << ans << endl;

}
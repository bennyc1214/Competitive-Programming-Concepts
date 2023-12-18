// COCI '14 Contest 6 P5 Neo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;
#define pii pair<int, int>

const int M = 2e3 + 5;
int r, c, ans;
int h[M];
int mat[M][M];
int a[M][M];
stack<pii> stk;

void getMaxRectInHist(int h[]) {
    assert(h[c - 1] == 0);
    for (int i = 0; i < c; i++) {
        while (!stk.empty() and h[i]<stk.top().first) {
            pii g = stk.top();
            stk.pop();
            int lft = stk.empty() ? -1 : stk.top().second;
            ans = max(ans, (i - lft-1+1) * (g.first+1));
        }
        stk.push(make_pair(h[i], i));
    }
    while (!stk.empty()) stk.pop();
}

int main()
{
    cin >> r >> c;
    //a(1, 1)+a(r, s) <= a(1, s) + a(r, 1)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    //a array is used to determine the matrix where we find the largest rectangle
    for (int i = 0; i < r-1; i++) {
        for (int j = 0; j < c-1; j++) {
            //(i, j) is the upper left corner
            if (mat[i][j] + mat[i + 1][j + 1] <= mat[i + 1][j] + mat[i][j + 1]) {
                a[i][j] = 1;
                h[j]++;
            }
            else h[j] = 0;

        }
        getMaxRectInHist(h);
    }
    cout << ans << endl;
}
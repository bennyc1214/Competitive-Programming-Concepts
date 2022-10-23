#include <iostream>
#include <algorithm>
#include <bit>
#include <cmath>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define f first
#define s second
#define pf push_front
#define pb push_back
#define p push
#define pis pair<int, string>
#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
char _;

using namespace std;

const int M = 5e6 + 6;
int arr[M];
int sparse[M][24];
int n, q;

/*
int log2_floor(int i) {
	return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
*/
int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << "How many elements are in your array?\n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Please enter element number " << i + 1 << ": ";
		cin >> arr[i];
	}
	//sparse[pos][k] means that, from position i in the array, the minimum element from the subarray of length 2^k
	//starting from i(inclusive)

	//now to compute the sparse table
	for (int i = 0; i < n; i++) {
		sparse[i][0] = arr[i];
	}
	//recurrence relation is sparse[pos][k] = min(sparse[pos][k-1], sparse[pos+(1<<k-1)][k-1])
	for (int i = 1; i < log2(n)+1; i++) {
		for (int j = 0; j < n; j++) {
			//i represents the 2^i for the length
			//j represents the current position of the array that we are starting from 
			sparse[j][i] = min(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
		}
	}
	//how to query?
	cout << "How many RMQ queries would you like make?\n";
	cin >> q;
	int l, r;
	while (q--) {
		cout << "Please enter the ranges of the query(inclusive) --> L R:";
		cin >> l >> r;
		int k = log2(r - l + 1);
		cout << min(sparse[l][k], sparse[r + 1 - (1 <<k)][k]) << endl;
	}
}

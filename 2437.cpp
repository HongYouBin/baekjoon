#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1005
using namespace std;

int n, arr[inf];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (arr[i] > ans) {
			cout << ans << '\n';
			return 0;
		}
		else {
			ans += arr[i];
		}
	}
	cout << ans << '\n';
}


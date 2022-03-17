#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 1005
#define pii pair<int,int>
using namespace std;

int n, s, t;
vector<pair<int, int>> vt;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s >> t;
		vt.push_back({ s,t });
	}
	sort(vt.begin(), vt.end());

	int ans = 1;
	pii tmp = vt[0];
	pq.push(tmp.second);
	for (int i = 1; i < vt.size(); ++i) {
		tmp = vt[i];
		if (tmp.first < pq.top()) ans++;
		else pq.pop();
		pq.push(tmp.second);
	}
	cout << ans << '\n';
}


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define inf 1000000
#define pii pair<int,int>
using namespace std;

int n, ans = inf;
string s, d, tmp;

void buttonON(int num) {
	tmp[num - 1] = (tmp[num - 1] == '0' ? '1' : '0');
	tmp[num] = (tmp[num] == '0' ? '1' : '0');
	if (num < n - 1) tmp[num + 1] = (tmp[num + 1] == '0' ? '1' : '0');
}

void solv(int flag) {
	int tmp_ans = 0;
	tmp = s;
	if (flag) {
		tmp[0] = (tmp[0] == '0' ? '1' : '0');
		tmp[1] = (tmp[1] == '0' ? '1' : '0');

		tmp_ans++;
	}
	for (int i = 1; i < n; ++i) {
		if (tmp[i - 1] != d[i - 1]) {
			buttonON(i);
			tmp_ans++;
		}
	}
	if (tmp == d)ans = min(ans, tmp_ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> s >> d;
	solv(0);
	solv(1);

	if (ans != inf)cout << ans << '\n';
	else cout << -1 << '\n';
}


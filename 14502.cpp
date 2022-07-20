#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int, int>
using namespace std;

int n, m, arr[10][10], wall, ans = 0;
vector<pii> emptyRoom, vir;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int count() {
	vector<pii> memo;
	int cnt = 0;
	queue<pii> que;
	for (int i = 0; i < vir.size(); ++i) {
		cnt++;
		que.push({ vir[i].first, vir[i].second });
		while (!que.empty()) {
			auto curVir = que.front(); que.pop();
			for (int i = 0; i < 4; ++i) {
				int nxtRow = curVir.first + dx[i];
				int nxtCol = curVir.second + dy[i];

				if (nxtRow < 0 || n <= nxtRow || nxtCol < 0 || m <= nxtCol) continue;
				if (arr[nxtRow][nxtCol] != 0) continue;
				cnt++;
				arr[nxtRow][nxtCol] = 2;
				memo.push_back({ nxtRow, nxtCol });
				que.push({ nxtRow, nxtCol });
			}
		}
	}
		
	for (auto i : memo) {
		arr[i.first][i.second] = 0;
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)emptyRoom.push_back({ i, j });
			else if (arr[i][j] == 2) vir.push_back({ i,j });
			else wall++;
		}
	}
	vector<bool> chosed(emptyRoom.size());
	fill(chosed.end() - 3, chosed.end(), true);
	do {
		vector<pii> reBuild;
		for (int i = 0; i < chosed.size(); ++i) {
			if (!chosed[i]) continue;
			reBuild.push_back({ emptyRoom[i] });
			arr[emptyRoom[i].first][emptyRoom[i].second] = 1;
		}
		ans = max(ans, n * m - count() - wall - 3);
		for (auto re : reBuild) {
			arr[re.first][re.second] = 0;
		}
	} while (next_permutation(chosed.begin(), chosed.end()));
	cout << ans;
}
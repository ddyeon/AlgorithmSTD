#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int arr[17][17] = { 0 };
int dx[3] = { 0,1,1 };
int dy[3] = { 1,1,0 };
int N;
// 방향: 가로0, 대각선1, 세로2
int main() {
	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	
	queue<pair<pair<int, int>, int>>q;
	q.push({ {1,2},0 });
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second, direction = q.front().second;

		if (x == N && y == N)
			answer++;
		q.pop();
		if (direction == 0) {
			for (int i = 0; i < 2; i++) {
				if (x + dx[i] >= 1 && x + dx[i] <= N && y + dy[i] >= 1 && y + dy[i] <= N) {
					if (i == 0 && arr[x + dx[i]][y + dy[i]] == 0)
						q.push({ {x + dx[i],y + dy[i]},i });

					else if (i == 1 && arr[x + dx[i]][y + dy[i]] == 0 && arr[x + dx[i]][y + dy[i] - 1] == 0 && arr[x + dx[i] - 1][y + dy[i]] == 0)
						q.push({ {x + dx[i],y + dy[i]},i });
				}
			}
		}

		else if (direction == 1) {
			for (int i = 0; i < 3; i++) {
				if (x + dx[i] >= 1 && x + dx[i] <= N && y + dy[i] >= 1 && y + dy[i] <= N) {
					if ((i == 0 || i == 2) && arr[x + dx[i]][y + dy[i]] == 0)
						q.push({ {x + dx[i],y + dy[i]},i });

					else if (i == 1 && arr[x + dx[i]][y + dy[i]] == 0 && arr[x + dx[i]][y + dy[i] - 1] == 0 && arr[x + dx[i] - 1][y + dy[i]] == 0)
						q.push({ {x + dx[i],y + dy[i]},i });
				}
			}
		}
		else if (direction == 2) {
			for (int i = 2; i > 0; i--) {
				if (x + dx[i] >= 1 && x + dx[i] <= N && y + dy[i] >= 1 && y + dy[i] <= N) {
					if (i == 2 && arr[x + dx[i]][y + dy[i]] == 0)
						q.push({ {x + dx[i],y + dy[i]},i });

					else if (i == 1 && arr[x + dx[i]][y + dy[i]] == 0 && arr[x + dx[i]][y + dy[i] - 1] == 0 && arr[x + dx[i] - 1][y + dy[i]] == 0)
						q.push({ {x + dx[i],y + dy[i]},i });
				}
			}
		}
	}

	cout << answer;
}
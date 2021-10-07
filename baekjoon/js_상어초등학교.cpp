#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[21][21] = { 0 };
int student[400][5] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool compare(pair<pair<int,int>,pair<int, int>>a, pair<pair<int, int>, pair<int, int>>b) {
	if (a.first.first > b.first.first)
		return true;
	else if (a.first.first < b.first.first)
		return false;
	else if (a.first.first == b.first.first) {
		if (a.first.second > b.first.second)
			return true;
		else if (a.first.second < b.first.second)
			return false;
		else if (a.first.second == b.first.second) {
			if (a.second.first < b.second.first)
				return true;
			else if (a.second.first > b.second.first)
				return false;
			else if (a.second.first == b.second.first) {
				if (a.second.second <= b.second.second)
					return true;
				else if (a.second.second > b.second.second)
					return false;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N * N; i++)
		cin >> student[i][0] >> student[i][1] >> student[i][2] >> student[i][3] >> student[i][4];
	int answer = 0;
	for (int studentnum = 0; studentnum < N * N; studentnum++) {
		int prefer1 = student[studentnum][1], prefer2 = student[studentnum][2], prefer3 = student[studentnum][3], prefer4 = student[studentnum][4];
		vector < pair<pair<int, int>, pair<int, int>>>v;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
			{
				int cnt = 0;
				int empty = 0;
				
				if (arr[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						if (i + dx[k] > 0 && i + dx[k] <= N && j + dy[k] > 0 && j + dy[k] <= N) {
							if (arr[i + dx[k]][j + dy[k]] == prefer1 || arr[i + dx[k]][j + dy[k]] == prefer2 || arr[i + dx[k]][j + dy[k]] == prefer3 || arr[i + dx[k]][j + dy[k]] == prefer4)
								cnt++;

							else if (arr[i + dx[k]][j + dy[k]] == 0)
								empty++;
						}
					}
					v.push_back({ { cnt,empty }, { i,j } });
				}
			}
		}
		sort(v.begin(), v.end(), compare);
		arr[v[0].second.first][v[0].second.second] = student[studentnum][0];
	}
	
	

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
		{
			for (int studentnum = 0; studentnum < N * N; studentnum++) {
				if (student[studentnum][0] != arr[i][j])
					continue;
				else {
					int prefer1 = student[studentnum][1], prefer2 = student[studentnum][2], prefer3 = student[studentnum][3], prefer4 = student[studentnum][4];
					int cnt = 0;

					for (int k = 0; k < 4; k++) {
						if (i + dx[k] > 0 && i + dx[k] <= N && j + dy[k] > 0 && j + dy[k] <= N) {
							if (arr[i + dx[k]][j + dy[k]] == prefer1 || arr[i + dx[k]][j + dy[k]] == prefer2 || arr[i + dx[k]][j + dy[k]] == prefer3 || arr[i + dx[k]][j + dy[k]] == prefer4)
								cnt++;
						}
					}

					if (cnt == 1)
						answer += 1;
					else if (cnt == 2)
						answer += 10;
					else if (cnt == 3)
						answer += 100;
					else if (cnt == 4)
						answer += 1000;
				}
			}
		}
	}


	cout << answer;
}
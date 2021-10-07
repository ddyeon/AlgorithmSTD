#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N;
int arr[21][21] = { 0 };
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int answer = 0;
int level = 2;
int main(){
	cin >> N;
	int startx=0, starty=0;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				startx = i;
				starty = j;
				arr[i][j] = -1;
			}
		}
	}
	int eat = 0;



	while (1) {
		bool end = true;
		queue < pair<int, pair<int, int>>>q;
		int visited[21][21] = { 0 };
		q.push({ 0,{startx,starty} });
		visited[startx][starty] = 1;
		int tmpx = 22, tmpy = 22, tmpcnt=1000;
		while (!q.empty()) {
			int cnt = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if (arr[x][y] > 0 && arr[x][y] < level) {
				if (cnt < tmpcnt) {
					tmpx = x;
					tmpy = y;
					tmpcnt = cnt;
					end = false;
				}
				else if (cnt == tmpcnt) {
					if (tmpx > x) {
						tmpx = x;
						tmpy = y;
						end = false;
					}
					else if (tmpx == x) {
						if (tmpy > y) {
							tmpx = x;
							tmpy = y;
							end = false;
						}
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				if (x + dx[i] >= 1 && x + dx[i] <= N && y + dy[i] >= 1 && y + dy[i] <= N) {
					if (arr[x + dx[i]][y + dy[i]] <= level && visited[x + dx[i]][y + dy[i]] == 0) {
						q.push({ cnt + 1,{x + dx[i],y + dy[i]} });
						visited[x + dx[i]][y + dy[i]] = 1;
					}
				}
			}
		}

		if (end)
			break;
		else {
			arr[startx][starty] = 0;
			arr[tmpx][tmpy] = -1;
			startx = tmpx;
			starty = tmpy;
			answer += tmpcnt;
			eat++;
			if (eat == level)
			{
				eat = 0;
				level++;
			}
		}
			
	}
	cout << answer;
}
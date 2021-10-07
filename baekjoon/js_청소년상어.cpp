#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
//먹혀서 사라진 물고기는 -1,-1로 바꾸고 arr에서 0으로 바꿈, 상어가 있는자리는 20으로 바꿈
void fishmove(pair<int, int> arr[4][4], pair<int, int> ar[17]) {
	for (int idx = 1; idx <= 16; idx++) {
		if (ar[idx].first == -1 && ar[idx].second == -1)
			continue;
		
		else {
			int x = ar[idx].first;
			int y = ar[idx].second;
			int dir = arr[x][y].second;

			if (x + dx[dir] >= 0 && x + dx[dir] < 4 && y + dy[dir] >= 0 && y + dy[dir] < 4 && arr[x + dx[dir]][y + dy[dir]].first!=20) {
				int tempfirst = arr[x][y].first;
				int tempsecond = arr[x][y].second;

				arr[x][y].first = arr[x + dx[dir]][y + dy[dir]].first;
				arr[x][y].second = arr[x + dx[dir]][y + dy[dir]].second;

				arr[x + dx[dir]][y + dy[dir]].first = tempfirst;
				arr[x + dx[dir]][y + dy[dir]].second = tempsecond; //arr에서 바꿔주기

				ar[arr[x][y].first].first = x;
				ar[arr[x][y].first].second = y;

				ar[arr[x+dx[dir]][y+dy[dir]].first].first = x + dx[dir];
				ar[arr[x + dx[dir]][y + dy[dir]].first].second = y + dy[dir];
			}

			else {
				int x = ar[idx].first;
				int y = ar[idx].second;
				int dir = arr[x][y].second;
				int tempdir = dir;
				while (1) {
					tempdir++;
					if (tempdir == 9)
						tempdir = 1;
					if (tempdir == dir)
						break;
					if (x + dx[tempdir] >= 0 && x + dx[tempdir] < 4 && y + dy[tempdir] >= 0 && y + dy[tempdir] < 4 && arr[x + dx[tempdir]][y + dy[tempdir]].first != 20)
					{
						dir = tempdir;
						arr[x][y].second = dir;
						int tempfirst = arr[x][y].first;
						int tempsecond = arr[x][y].second;

						arr[x][y].first = arr[x + dx[dir]][y + dy[dir]].first;
						arr[x][y].second = arr[x + dx[dir]][y + dy[dir]].second;

						arr[x + dx[dir]][y + dy[dir]].first = tempfirst;
						arr[x + dx[dir]][y + dy[dir]].second = tempsecond; //arr에서 바꿔주기

						ar[arr[x][y].first].first = x;
						ar[arr[x][y].first].second = y;

						ar[arr[x + dx[dir]][y + dy[dir]].first].first = x + dx[dir];
						ar[arr[x + dx[dir]][y + dy[dir]].first].second = y + dy[dir];
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << arr[i][j].first << "   ";
		cout<<endl;
	}
}

void simulate(pair<int,int> arr[4][4], pair<int,int> ar[17], int x, int y, int cnt) {

	if (x < 0 || x >= 4 || y < 0 || y >= 4) {
		answer = max(answer, cnt);
		return;
	}
	if (arr[x][y].first==0) {
		answer = max(answer, cnt);
		return;
	}
	
	int dir = arr[x][y].second;
	ar[arr[x][y].first].first = -1;
	ar[arr[x][y].first].second = -1;
	cnt += arr[x][y].first;
	arr[x][y].first = 20;
	fishmove(arr,ar);
	arr[x][y].first = 0;
	for (int i = 1; i < 4; i++) {
		
		simulate(arr, ar, x + dx[dir]*i, y + dy[dir]*i, cnt);
	}
}

int main() {
	pair<int, int> arr[4][4];
	pair<int, int>ar[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j].first >> arr[i][j].second;
			ar[arr[i][j].first].first = i;
			ar[arr[i][j].first].second = j;
		}
	}
	simulate(arr,ar,0, 0, 0);
	cout << answer;
}
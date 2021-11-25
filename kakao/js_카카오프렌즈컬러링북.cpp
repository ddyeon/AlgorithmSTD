#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<int>>visited(m, vector<int>(n));
    queue<pair<pair<int, int>, int>>q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visited[i][j] == 0) {
                q.push({ {i,j},picture[i][j] });
                visited[i][j] = 1;
                int tmp = 1;
                while (!q.empty()) {
                    int x = q.front().first.first;
                    int y = q.front().first.second;
                    int col = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        if (x + dx[k] >= 0 && x + dx[k] < m && y + dy[k] >= 0 && y + dy[k] < n) {
                            if (col == picture[x + dx[k]][y + dy[k]] && visited[x + dx[k]][y + dy[k]] == 0) {
                                visited[x + dx[k]][y + dy[k]] = 1;
                                q.push({ {x + dx[k],y + dy[k]},col });
                                tmp++;
                            }
                        }
                    }
                }
                number_of_area++;
                if (tmp > max_size_of_one_area)
                    max_size_of_one_area = tmp;
            }


        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
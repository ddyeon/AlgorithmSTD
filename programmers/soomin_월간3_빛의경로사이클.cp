//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visit[501][501][4];
int grid_map[501][501];
vector<int> answer;
int starty = 0; int startx = 0; int startdir = -1;
int check(int n, int l){
    if (n >= l) n %= l;
    else if (n < 0){
        while (n < 0){
            n = l + n;
            }
        }
    return n;
}
void dfs(int y, int x, int dir, int garo, int sero, int cnt){
    if (visit[y][x][dir]) {
        if ((y == starty) and (x == startx) and (dir == startdir)){
            answer.push_back(cnt);
        }
        else return;
    }
    else if (visit[y][x][dir] == 0){
        visit[y][x][dir] = 1;
        if (grid_map[y][x] == 'S'){
        }
        else if (grid_map[y][x] == 'L'){
            if (dir - 1 < 0) dir = 3;
            else dir -= 1;
        }else{
            dir = (dir + 1) % 4;
        }
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 or ny >= sero) ny = check(ny, sero);
        if (nx < 0 or nx >= garo) nx = check(nx, garo);
        dfs(ny, nx, dir, garo, sero, cnt + 1);
    }
}
vector<int> solution(vector<string> grid) {
    int sero = grid.size();
    int garo = grid[0].size();
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            grid_map[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < sero; i++){
        for (int j = 0; j < garo; j++){
            for (int k = 0; k < 4; k++){
                if (visit[i][j][k]) continue;
                startdir = k;
                starty = i; startx = j;
                dfs(i, j, k, garo, sero, 0);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

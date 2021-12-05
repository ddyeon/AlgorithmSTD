#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool check[101][101];

int bfs(int val, int x, int y, int m, int n, vector<vector<int>> picture) {
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    int cnt = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i][0];
            int ny = y + dx[i][1];
            if(nx <0 || nx>=m || ny<0 || ny>=n || check[nx][ny] || picture[nx][ny] !=val) continue;
            q.push({nx,ny});
            check[nx][ny] = true;
            cnt++;
    }
    }
    return cnt;
} 

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    
    for(int i = 0; i <m; i++) {
        for(int j = 0; j < n; j++) {
            check[i][j] = false;
        }
    }
    for(int i = 0; i< m; i++) {
        for(int j =0; j < n; j++) {
            if(!check[i][j] && picture[i][j] >0) {
                int cnt = bfs(picture[i][j], i, j , m, n, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, cnt);
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
 
}
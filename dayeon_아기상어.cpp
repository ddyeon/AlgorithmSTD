#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
//아기상어 사이즈2
//자기보다 크면 지나갈 수 없음.
//크기가 같은 경우 먹을 순 없고 지나갈 수는 있음.
//거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기
int arr[21][21];
int shark_size = 2;
int visit[21][21];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int shark_x, shark_y = 0;
vector<pair<pair<int, int>, int>> eat;
int eat_cnt = 0;
int eat_distance = 0;
int result = 0;
int N;
void bfs(int x, int y)
{
    eat_distance = 987654321;
    eat.clear();
    memset(visit,0, sizeof(visit));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (0 > nx || N <= nx || 0 > ny || N <= ny)
                continue;
            if (visit[nx][ny] == 0 && shark_size >= arr[nx][ny])
            {
                visit[nx][ny] = visit[cur_x][cur_y] + 1;
                if (arr[nx][ny] > 0 && arr[nx][ny] < shark_size)
                { 
                    if (eat_distance >= visit[nx][ny])
                    {
                        eat_distance = visit[nx][ny];
                        eat.push_back(make_pair(make_pair(eat_distance, nx), ny));
                    }
                }
                q.push(make_pair(nx, ny));
            }
        
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 9)
            {
                arr[i][j] = 0;
                shark_x = i;
                shark_y = j;
            }
        }
    }

    while (true)
    {
        bfs(shark_x, shark_y);
        if(eat.empty())break;
        else
        {
            sort(eat.begin(), eat.end());
            eat_cnt++;
            result += eat[0].first.first;
            arr[eat[0].first.second][eat[0].second] = 0;
            shark_x = eat[0].first.second;
            shark_y = eat[0].second;
            if(shark_size == eat_cnt)
            {
                shark_size++;
                eat_cnt = 0;
            }
                

            
        }
        

        
    }

    cout << result;
    return 0;
    
}
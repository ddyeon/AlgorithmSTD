#include <string.h>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
queue<int> q;
int arr[20010][20010];
int visit[20010];
int dist[20010];

void bfs(int n) {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 2; i <= n; i++) {
            if (arr[cur][i] == 1 && visit[i] == 0) {
                visit[i] = 1;
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }

}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        arr[edge[i][0]][edge[i][1]] = 1;
        arr[edge[i][1]][edge[i][0]] = 1;
    }

    visit[1] = 1;
    q.push(1);
    bfs(n);
    int check = 0;
    int maxCnt = *max_element(dist + 1, dist + n + 1);
    if (maxCnt == 0)return 0;
    for (int i = n; i >= 2; i--) {
        if (maxCnt == dist[i]) answer++;
        else if (dist[i] == 0) check++; //아니 이거는 문제에 얘기가 없었자냐!!!!
    }
    if (check != 0)answer = check;
    return answer;
}
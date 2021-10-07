#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v[52];
int dist[100];

void dijkstra(int N) {
    pq.push({ 0,1 }); // ¾ÕÀÌ °Å¸®, µÚ°¡ ÇöÀç À§Ä¡
    dist[1] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[loc].size(); i++) {
            int next = v[loc][i].first;
            int c = v[loc][i].second;

            if (dist[next] > cost + c) {
                dist[next] = cost + c;
                pq.push({ -dist[next], next });
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 1; i <= N; i++)dist[i] = 500001;
    for (int i = 0; i < road.size(); i++) {
        v[road[i][0]].push_back({ road[i][1], road[i][2] });
        v[road[i][1]].push_back({ road[i][0], road[i][2] });
    }
    dijkstra(N);
    for (int i = 1; i < N; i++) {
        if (dist[i] <= K)answer++;
    }
    return answer;
}

int main(void) {

    solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
    solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4);
}

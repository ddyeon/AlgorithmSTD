#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[20010] {};
vector<pair<int, int>> map[20010] {};

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    int max = 0;

    for (int i = 1; i <= n; i++) {
        dist[i] = __INT_MAX__;
    }

    for (int i = 0; i < edge.size(); i++) {
        map[edge[i][0]].push_back({edge[i][1], 1}); //map[from].push_back({to, distance})
        map[edge[i][1]].push_back({edge[i][0], 1});
    }

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        for (int i = 0; i < map[here].size(); i++) {
            int next = map[here][i].first;
            int nextcost = map[here][i].second;

            if (dist[next] > dist[here] + nextcost) {
                dist[next] = dist[here] + nextcost;
                max = max > dist[next] ? max : dist[next];
                pq.push({-dist[next], next});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == max) {
            answer++;
        }
    }

    return answer;
}

int main(void)
{
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, edge) << endl;;

    return 0;
}
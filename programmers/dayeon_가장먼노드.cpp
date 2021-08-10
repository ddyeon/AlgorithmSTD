#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    vector<vector<int>> v(n + 1);
    queue<int> q;
    vector<bool> visit(n+1, false);
    vector<int> distance(n+1);

    for(int i = 0; i < edge.size(); i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];

        v[start].push_back(end);
        v[end].push_back(start);
    }

    q.push(1);
    visit[1] = true;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(int i = 0; i< v[current].size(); i++)
        {
            int last = v[current][i]; //노드와 연결된 것들
            if(!visit[last])
            {
                visit[last] = true;
                distance[last] = distance[current] + 1;
                q.push(last);
        
            }
        }
    }

    sort(distance.begin(), distance.end(), comp);


    for(int i = 0; i <distance.size(); i++)
    {
        if(distance[i] == distance[0])
            answer++;
    }


    return answer;
}
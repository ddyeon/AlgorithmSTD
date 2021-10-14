#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//테케 2,11,12,13

int visit[101];
int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    //vector<int> v[101];
    int arr[101][101];
    for(int i = 0; i < wires.size(); i++)
    {
        arr[wires[i][0]][wires[i][1]] = 1;
        arr[wires[i][1]][wires[i][0]] = 1;
    }
    
    int cnt = 0;
    for(int i = 0; i < wires.size(); i++)
    {
        arr[wires[i][0]][wires[i][1]] = 0;
        arr[wires[i][1]][wires[i][0]] = 0;
        
        cnt = 0;
        memset(visit, false, sizeof(visit));
        queue <int> q;
        q.push(1);
        visit[1] = true;
        
        while(!q.empty())
        {
            int start = q.front();
            q.pop();
            cnt++;
            for(int j = 1; j <= n; j++)
            {
                if(arr[start][j] == 1 && !visit[j])
                {
                    q.push(j);
                    visit[j] = true;
                }
            }
        }
        arr[wires[i][0]][wires[i][1]] = 1;
        arr[wires[i][1]][wires[i][0]] = 1;
       
        int dummy = n - cnt;
        int min_val = abs(cnt - dummy);
        if(answer > min_val)
            answer = min_val; 
    }
    
   
    return answer;
}
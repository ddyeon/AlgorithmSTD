#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int city[52][52];
    priority_queue<int, vector<int>, greater<int>> start;
    bool visited[52];
    int result[52];
    memset(visited,false,sizeof(visited));
    memset(city, 0, sizeof(city));
    for (int i = 1; i <= N; i++){
        result[i] = 999999;
    }
    for (int i = 0; i < road.size(); i++){
        if (city[road[i][0]][road[i][1]] == 0){
            city[road[i][0]][road[i][1]]=road[i][2];
            city[road[i][1]][road[i][0]]=road[i][2];
        }
        else if (city[road[i][0]][road[i][1]]>road[i][2]){
            city[road[i][0]][road[i][1]]=road[i][2];
            city[road[i][1]][road[i][0]]=road[i][2];
        }
        else{
            continue;
        }
    }
    start.push(1);
    visited[1] = true;
    result[1] = 0;
    while (!start.empty()){
        int tmpstart = start.top();
        start.pop();
        for (int i = 2; i <= N; i++){
            if (visited[i]==false){
                if (city[tmpstart][i]!=0){
                    visited[i]=true;
                    start.push(i);
                    result[i] = result[tmpstart] + city[tmpstart][i];
                }
            }
            else{
                if (city[tmpstart][i]!=0){
                    result[i] = min(result[tmpstart]+city[tmpstart][i],result[i]);
                }
            }
        }
    }
    for (int i = 1 ;i <= N; i++){
        if (result[i] <= K){
            answer+=1;
        }
    }
    return answer;
}

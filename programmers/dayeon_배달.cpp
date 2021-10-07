#include <iostream>
#include <vector>
using namespace std;

//플로이드와샬
int visit[51][51];

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 1; //1로바꿔줘야함

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
            visit[i][j] = 100001; //최대값 초기화
    }

    for(int i = 0; i < road.size(); i++)
    {
        int x = road[i][0]; //출발지
        int y = road[i][1]; //도착지
        int z = road[i][2]; //가중치

        if(visit[x][y] >= z)
        {
            visit[x][y] = z;
            visit[y][x] = z;
        }
    }

    for(int k=1; k<=N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (k == i || k == j || i == j)
                    continue;                                              //전부1일때
                visit[i][j] = min(visit[i][j], visit[i][k] + visit[k][j]); //거처서 가는거랑 그냥가는거랑 비교
            }
        }
           
    }
        
    
    for(int i =2; i<=N;i++)
    {
        if(visit[1][i] <= K)
            answer++;
    }


    return answer;
}

//[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]
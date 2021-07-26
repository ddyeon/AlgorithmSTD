#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int current = 1; //현재위치
    int idx = 0;

    while (current <= n)
    { 

        if (idx < stations.size() && current >= stations[idx] - w) //거리가 된다면
        {

            current = stations[idx] + w + 1; 
            idx++;                           
        }
        else //기지국범위 밖
        { 

            current += 2 * w + 1;  //최대값
            answer++;             
        }
    }

    return answer;
}

int main()
{
    // 11 [4, 11] 1 3 
    // 16 [9] 2 3
}
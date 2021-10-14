//위클리 챌린지 9주차: 전력망을 둘로 나누기
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 0xFFFFF;
    int N = wires.size();
    for (int i = 0; i < N; i++){
        unordered_map <int, vector<int>> m; // 연결리스트
        for (int j = 0; j < N; j++){
            if (i == j){ continue;} //하나씩 끊어보기
            vector<int> t;
            t = m[wires[j][0]];
            t.push_back(wires[j][1]);
            m[wires[j][0]] = t;
            vector<int> t2;
            t2 = m[wires[j][1]];
            t2.push_back(wires[j][0]);
            m[wires[j][1]] = t2;
        }
        
        deque <int> q;
        q.push_back(1);
        int visited[100] = {0, };
        int cnt = 0; //연결된 애들
        while (q.size()){
            int now = q[0];
            q.pop_front();
            visited[now] = 1;
            cnt += 1;
            for (int k = 0; k < m[now].size(); k++){
                if (visited[m[now][k]] == 1) continue;
                q.push_back(m[now][k]);
            }
            
        }
        int second = n - cnt; //연결안된애들
        answer = min(answer , abs(cnt - second));
        
    }
    return answer;
}

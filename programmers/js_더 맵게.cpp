#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>>pq;
    int answer = 0;

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (true) {
        int a, b;
        if (pq.top() < K) {
            if (pq.size() < 2) {
                answer = -1;
                break;
            }

            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();
            pq.push(a + b * 2);
            if (a == 0 && b == 0) {
                answer = -1;
                break;
            }
            answer++;
        }

        else
            break;

    }
    return answer;
}
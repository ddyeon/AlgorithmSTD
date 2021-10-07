#include <string>
#include <vector>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) pq.push(scoville[i]); 
    
    while (!pq.empty()) {
        if (pq.size() == 1) {
            if (pq.top() < K) return -1;
        }
        if (pq.top() >= K)break;
        int k1 = pq.top();
        pq.pop();
        int k2 = pq.top();
        if (k1 == 0 && k2 == 0)return -1;
        pq.pop();
        pq.push(k1 + (k2 * 2));
        answer++;
    }
    return answer;
}
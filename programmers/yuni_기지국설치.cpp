#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> m;
int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int startIdx = 1;
    int endIdx = 0;
    for (int i = 0; i < stations.size(); i++) m[stations[i]] = 1;

    for (auto k = m.begin(); k != m.end(); ++k) {
        if (k->first > startIdx) {
            endIdx = k->first - w;
            answer += (endIdx - startIdx) / ((w * 2) + 1);
            if ((endIdx - startIdx) % ((w * 2) + 1) != 0)answer++;
            startIdx = k->first + w + 1;
        }
        else  startIdx = k->first + w + 1;
    }

    if (startIdx <= n) {
        answer += (n - startIdx + 1) / ((w * 2) + 1);
        if ((n - startIdx + 1) % ((w * 2) + 1) != 0) answer++;
    }

    return answer;
}
int main(void) {
    solution(10, { 2,3,4,5 }, 2);
}
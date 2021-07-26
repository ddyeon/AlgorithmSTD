#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int startIdx = 1;
    int endIdx = 0;
    sort(stations.begin(), stations.end());
    for (int i = 0; i < stations.size(); i++) {
        if (stations[i] - w > startIdx) {
            endIdx = stations[i] - w;
            answer += (endIdx - startIdx) / ((w * 2) + 1);
            if ((endIdx - startIdx) % ((w * 2) + 1) != 0)answer++;
            startIdx = stations[i] + w + 1;
        }
        else  startIdx = stations[i] + w + 1;
    }

    if (startIdx <= n) {
        answer += (n - startIdx + 1) / ((w * 2) + 1);
        if ((n - startIdx + 1) % ((w * 2) + 1) != 0) answer++;
    }

    return answer;
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//n명이 입국심사를 위해 줄을 서서 기다리고 있다. 입국 심사를 기다리는 사람 n, 심사하ㅡㄴ데 걸리는 시간 


long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long high = times[times.size() - 1] * n;
    long long low = 0;
    while (high != low) {
        long long mid = (high + low) / 2;
        long long cnt = 0;

        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        if (cnt >= n) {
            high = mid;

        }
        else {
            low = mid + 1;

        }
    }
    answer = low;
    return answer;
}

int main(void) {
    solution(6, {7,10});
}
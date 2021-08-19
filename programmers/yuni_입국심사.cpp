#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//n���� �Ա��ɻ縦 ���� ���� ���� ��ٸ��� �ִ�. �Ա� �ɻ縦 ��ٸ��� ��� n, �ɻ��ϤѤ��� �ɸ��� �ð� 


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
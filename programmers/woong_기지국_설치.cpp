#include <iostream>
#include <vector>
using namespace std;

/*
    기지국 하나가 커버: 2w+1
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1, end = 1;

    for (int i = 0; i < stations.size(); i++) {
        if (stations[i] - w < start) {
            start = stations[i] + w + 1;
            continue;
        }
        else {
            end = stations[i] - w - 1;
        }

        answer += (end - start + 1) % (2 * w + 1) == 0 ? (end - start + 1) / (2 * w + 1) : (end - start + 1) / (2 * w + 1) + 1;

        start = stations[i] + w + 1;
    }

    if (stations.back() + w < n) {
        start = stations.back() + w + 1;
        end = n;
        answer += (end - start + 1) % (2 * w + 1) == 0 ? (end - start + 1) / (2 * w + 1) : (end - start + 1) / (2 * w + 1) + 1;
    }

    return answer;
}

int main(void)
{
    int N = 11;
    vector<int> stations = {4, 11};
    int W = 1;

    cout << solution(N, stations, W) << endl;

    return 0;
}
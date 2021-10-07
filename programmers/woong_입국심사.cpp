#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    long long person = 0;
    long long start = 1, end, avg;

    end = *max_element(times.begin(), times.end()) * (long long)n;

    while (start <= end) {
        avg = (start + end) / 2;
        for (int i = 0; i < times.size(); i++) {
            person += avg/times[i];
        }
        if (n <= person) {
            answer = avg;
            end = avg - 1;
        }
        else {
            start = avg + 1;
        }
        person = 0;
    }

    return answer;
}

int main(void)
{
    int n = 6;
    vector<int> times = {7, 10};

    cout << solution(n, times) << endl;

    return 0;
}
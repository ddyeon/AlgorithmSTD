#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>>q;
    q.push(make_pair(0, 0));
    int idx = 0;
    while (!q.empty()) {
        int sum = q.front().first;
        int curIndex = q.front().second;
        if (sum == target && curIndex == numbers.size())
            answer++;
        q.pop();
        if (curIndex < numbers.size()) {
            q.push(make_pair(sum + numbers[curIndex], curIndex + 1));
            q.push(make_pair(sum - numbers[curIndex], curIndex + 1));
        }
    }
    return answer;
}

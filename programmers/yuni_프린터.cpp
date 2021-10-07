#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int,int>> priorityq;
vector <int> sortArr;
bool oper(int a, int b) {
    return a > b;
}
int solution(vector<int> priorities, int location) {

    int answer = 0;
    int j = priorities.size()-1;
    for (int i = 0; i < priorities.size(); i++, j--) {
        priorityq.push(make_pair(i, priorities[i]));
        sortArr.push_back( priorities[j]);
    }
    int id = 0;
    sort(sortArr.begin(), sortArr.end(), oper);
    while (!priorityq.empty()) {
        if (priorityq.front().second == sortArr[id]) {
            answer++;
            id++;
            if (priorityq.front().first == location)break;
            priorityq.pop();
            sortArr.pop_back();
        }
        else {
            int tmp = priorityq.front().second;
            int index = priorityq.front().first;
            priorityq.pop();
            priorityq.push(make_pair(index, tmp));

        }
    }
    return answer;
}
int main(void) {
    solution({2, 1, 3, 2
}, 2);
}
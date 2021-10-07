#include <string>
#include <vector>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> doublequeue;
priority_queue<int, vector<int>, greater<int>> doublequeue2;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            string tmp = operations[i].substr(2);
            doublequeue.push(stoi(tmp));
        }
        else {
            if (doublequeue.empty())continue;
            if (operations[i][2] == '1') { //ÃÖ´ñ°ª »èÁ¦
                while (doublequeue.size() != 1) {
                    doublequeue2.push(doublequeue.top());
                    doublequeue.pop();
                }
                doublequeue = doublequeue2;
                while (!doublequeue2.empty())doublequeue2.pop();
            }
            else { //ÃÖ¼Ú°ª »èÁ¦
                doublequeue.pop();
            }
        }
    }
    if (doublequeue.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        int min = doublequeue.top();
        while (doublequeue.size() != 1)doublequeue.pop();
        answer.push_back(doublequeue.top());
        answer.push_back(min);
    }
    return answer;

}
int main(void) {
//    solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
    solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
}
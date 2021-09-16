#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int arr[10] = { 0 };
    queue<pair<int, int>>q;
    for (int i = 0; i < priorities.size(); i++) {
        arr[priorities[i]]++;
        q.push({ i,priorities[i] });
    }
    
    while (!q.empty()) {
        int idx = q.front().first;
        int priority = q.front().second;
        bool isLargestNumber = true;
        for (int i = priority + 1; i < 10; i++) {
            if (arr[i] > 0) {
                q.pop();
                q.push({ idx,priority });
                isLargestNumber = false;
                break;
            }
        }
        if (isLargestNumber) {
            q.pop();
            arr[priority]--;
            if (idx == location)
                return answer;
            else
                answer++;
        }
        
    }
    

}


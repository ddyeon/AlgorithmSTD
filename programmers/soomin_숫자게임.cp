//
//  main.cpp
//  숫자게임
//
//  Created by 김수민 on 2021/07/29.
//

#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    deque <int> AA;
    deque <int> BB;
    for (int i = 0; i < A.size(); i++){
        AA.push_back(A[i]);
    }
    for (int i = 0; i < B.size(); i++){
        BB.push_back(B[i]);
    }
    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());
    while (!BB.empty()){
        if (AA.front() < BB.front()){
            answer += 1;
            AA.pop_front();
            BB.pop_front();
        }
        else{
            BB.pop_front();
        }
    }
    return answer;
}

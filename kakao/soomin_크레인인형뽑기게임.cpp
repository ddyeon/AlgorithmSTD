//
//  PG_크레인인형뽑기게임_김수민.cpp
//  
//
//  Created by 김수민 on 2021/07/01.
//

#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    deque<deque<int>> lists;
    vector <int> results;
    deque<int> l;
    for (int i = 0; i < board.size();i++) {
        l.clear();
        for (int j = 0; j < board[i].size();j++) {
            int doll = board[j][i];
            if (doll != 0) {
                l.push_back(doll);
                
            }
        }
        lists.push_back(l);
    }
    for (int i = 0; i < moves.size();i++) {
        if (lists[moves[i] - 1].empty()) {
            continue;
        }
        int pick = lists[moves[i] - 1].front();
        lists[moves[i] - 1].pop_front();
        results.push_back(pick);
    }
    while (true) {

        bool flag = false;
        for (int i = 0; i < results.size();i++) {
            if (i==results.size()-1){
                continue;
            }
            if (results[i] == results[i + 1]) {
                results.erase(results.begin() + i);
                results.erase(results.begin() + i);
                flag = true;
                answer += 2;
            }

        }
        if (flag == false)break;
    }

    return answer;
}

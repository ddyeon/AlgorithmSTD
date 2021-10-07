// 완전탐색 - 카펫 (김수민)
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for (int i = 3; i < total / 2; i++){
        if (total % i == 0){
            int sero = i;
            int garo = total / i;
            int tmp = sero * 2 + garo * 2 - 4; //테투리 길이 계산
            if (tmp == brown){
                answer.push_back(garo);
                answer.push_back(sero);
                break;
            }
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
압축 전의 정보를 복원 가능한 무손실 압축 알고리즘을 구현
LZW 알고리즘
-길이가 1인 모든 단어를 포함하도록 사전 초기화
-사전에서 현재 입력과 일치하는 가장 긴 문자열 W
-W에 해당하는 사전의 색인 번호를 출력하고 입력에서 W를 제거
-입력에서 처리되지 않은 다음 글자가 남아있다면 C, W+C에 해당하는 단어를 사전에 등록
-단계 2로 돌아간자.
*/
unordered_map<string, int> uno;
vector<int> solution(string msg) {
    vector<int> answer;
    int index = 1;
    for (char i = 'A'; i <= 'Z'; i++) uno[string(1, i)] = index++;
    string tmp = string(1,msg[0]);
    for (int i = 1; i < msg.size(); i++) {
        tmp += msg[i];

        if (tmp!="" && uno[tmp] == 0) {
            uno[tmp] = index++;
            answer.push_back(uno[tmp.erase(tmp.size() - 1)]);
            tmp = "";
            i--;
        }
    }
    if (tmp != "") answer.push_back(uno[tmp]);
    return answer;
}
int main(void) {
//    solution("KAKAO");
 //   solution("TOBEORNOTTOBEORTOBEORNOT");
    solution("ABABABABABABABAB");
}
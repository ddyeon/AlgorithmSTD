#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
���� ���� ������ ���� ������ ���ս� ���� �˰����� ����
LZW �˰���
-���̰� 1�� ��� �ܾ �����ϵ��� ���� �ʱ�ȭ
-�������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� W
-W�� �ش��ϴ� ������ ���� ��ȣ�� ����ϰ� �Է¿��� W�� ����
-�Է¿��� ó������ ���� ���� ���ڰ� �����ִٸ� C, W+C�� �ش��ϴ� �ܾ ������ ���
-�ܰ� 2�� ���ư���.
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
#include <string>
#include <vector>

using namespace std;
//���� ���� �迭�� ���� ���� �����Ͱ� �������
//������ 0���� �ʱ�ȭ �ؾ���
//MOVES�� ��� �Ÿ� ���ο� �迭�� ����־�� �ڳ� ����ְ� �����ϸ� POP
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    vector<int> temp;
    int tmp = 0;
    for (int i = 0; i < moves.size(); i++) {
        if (board[size - 1][moves[i] - 1] == 0) {
            tmp = -1;
            continue;
        }
        for (int j = 0; j < size; j++) {
            if (board[j][moves[i] - 1] != 0) {
                tmp = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
        if (temp.size() > 0 && temp.back() == tmp) {
            temp.pop_back();
            answer += 2;
        }
        else {
            temp.push_back(tmp);
        }
    }
    return answer;
}
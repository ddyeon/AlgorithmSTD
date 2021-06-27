#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;

    int b_size = board.size();
    vector<int> box;

    for (int i = 0; i < moves.size(); i++)
    {
        int cur_position = moves[i] - 1; //0���� ����

        for (int j = 0; j < b_size; j++)
        {
            if (board[j][cur_position] == 0)
                continue;
            else
            {
                int value = board[j][cur_position];

                if (box.size() != 0 && box.back() == value)
                {
                    answer += 2;
                    box.pop_back();
                }
                else //���� ������
                {
                    box.push_back(value);
                }
                board[j][cur_position] = 0;
                break;
            }
        }
    }

    return answer;
}

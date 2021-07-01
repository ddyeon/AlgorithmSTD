#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    stack<int> bucket;

    for (int i = 0; i < moves.size(); i++) {
        int c = moves[i] - 1;
        for (int r = 0; r < board.size(); r++) {
            if (board[r][c] == 0) {
                continue;
            }
            else {
                if (!bucket.empty() && bucket.top() == board[r][c]) {
                    bucket.pop();
                    board[r][c] = 0;
                    answer += 2;
                }
                else {
                    bucket.push(board[r][c]);
                    board[r][c] = 0;
                }
                break;
            }
        }
    }

    return answer;
}
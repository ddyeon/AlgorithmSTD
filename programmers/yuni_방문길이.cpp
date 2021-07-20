#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

//U : 위쪽으로 한칸 가기, D : 아래쪽으로 한 칸 가기
//R : 오른쪽으로 한 칸 가기, L : 왼쪽으로 한 칸 가기
struct Node {
    int a, b, c, d;
};
unordered_map <string, int> uno;

int solution(string dirs) {
    int answer = 0;
    int y = 0, x = 0;
    int tmpy =0, tmpx =0;
    int size = dirs.length();
    for (int i = 0; i <size; i++) {
        tmpy = y;
        tmpx = x;
        if (dirs[i] == 'U') y++;
        else if (dirs[i] == 'L')x--;
        else if (dirs[i] == 'R')x++;
        else if (dirs[i] == 'D') y--;
        string tmp = to_string(tmpy);
        tmp += to_string(tmpx);
        tmp += to_string(y);
        tmp += to_string(x);
        uno[tmp]++;
        if (uno[tmp] == 1) {
            uno[tmp] = 1;
            answer++;
        }
    }
    return answer;
}
int main(void) {
    solution("ULURRDLLU");
    solution("LULLLLLLU");
}
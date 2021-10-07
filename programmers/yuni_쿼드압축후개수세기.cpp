#include <string>
#include <vector>
using namespace std;

int zero = 0;
int one = 0;
vector<vector<int>> ar;

void quad(int y, int x, int size) {
   
    int tmp = ar[y][x];

    bool flag = true;
    for (int i = y; i < y + size; i++) {
        if (flag == false) break;
        for (int j = x; j < x + size; j++) {
            if (tmp != ar[i][j]) {
                flag = false;
                break;
            }
        }
    }
    if (flag == true) {
        if (tmp == 0)zero++;
        else one++;
        return;
    }
    quad(y, x, size / 2);
    quad(y, x + size / 2, size / 2);
    quad(y + size / 2, x, size / 2);
    quad(y + size / 2, x + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    ar = arr;

    if (arr.size() == 1) {
        if (arr[0][0] == 1) one++;
        else zero++;
    }
    else if (arr.size() == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (arr[i][j] == 1) one++;
                else zero++;
            }
        }
        if (zero == 4)zero = 1;
        if (one == 4) one = 1;
    }
    int size = arr.size();
    quad(0, 0, size);

    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
int main(void) {
    solution({ {1,1,0,0},{1,0,0,0}, {1,0,0,1}, {1,1,1,1} });
    solution({ {1,1,1,1,1,1,1,1}, {0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1}, 
        {0,1,0,0,1,1,1,1}, {0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1}, {0,0,0,0,1,1,1,1} });
}
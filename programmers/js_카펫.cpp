#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width, height;
    int whole = brown + yellow;
    for (int i = 1; i <= sqrt(whole); i++) {
        if (whole % i == 0) {
            width = whole / i;
            height = i;
            if ((width - 2) * (height - 2) == yellow)
                break;
        }
    }
    answer.push_back(width);
    answer.push_back(height);

    return answer;
}
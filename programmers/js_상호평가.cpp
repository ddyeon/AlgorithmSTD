#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    for (int j = 0; j < scores.size(); j++) {
        int mynum = scores[j][j];
        int sum = 0, avg=0;
        int maxnum = 0, minnum = 100, samenum = 0;
        for (int i = 0; i < scores.size(); i++) {
            maxnum = max(scores[i][j], maxnum);
            minnum = min(scores[i][j], minnum);
            sum += scores[i][j];
            if (scores[i][j] == mynum)
                samenum++;
        }

        if (samenum == 1 && maxnum == mynum) {
            sum -= mynum;
            avg = sum / (scores.size() - 1);
        }
        else if (samenum == 1 && minnum == mynum) {
            sum -= mynum;
            avg = sum / (scores.size() - 1);
        }
        else
            avg = sum / scores.size();

        if (avg >= 90)
            answer += 'A';
        else if (avg >= 80 && avg < 90)
            answer += 'B';
        else if (avg >= 70 && avg < 80)
            answer += 'C';
        else if (avg >= 50 && avg < 70)
            answer += 'D';
        else
            answer += 'F';

    }
    return answer;
}

int main() {
    vector<vector<int>>s = { {50, 90}, {50,87} };
    cout<<solution(s);
}
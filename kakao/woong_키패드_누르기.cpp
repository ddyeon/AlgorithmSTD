#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> coordinate(int curPos)
{
    switch(curPos) {
    case 1:
        return make_pair(0, 0);
    case 2:
        return make_pair(0, 1);
    case 3:
        return make_pair(0, 2);
    case 4:
        return make_pair(1, 0);
    case 5:
        return make_pair(1, 1);
    case 6:
        return make_pair(1, 2);
    case 7:
        return make_pair(2, 0);
    case 8:
        return make_pair(2, 1);
    case 9:
        return make_pair(2, 2);
    case '*':
        return make_pair(3, 0);
    case 0:
        return make_pair(3, 1);
    case '#':
        return make_pair(3, 2);
    }
}

int distance(pair<int, int> a, pair<int, int> b) {
    int x = a.first - b.first;
    int y = a.second - b.second;

    if (x < 0 && y < 0) {
        return -(x + y);
    }
    else if (x < 0) {
        return -x + y;
    }
    else if (y < 0) {
        return x - y;
    }

    return x + y;
}  

string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    int curRight = '#', curLeft = '*';

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            curLeft = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            curRight = numbers[i];
        }
        else {
            if (distance(coordinate(curRight), coordinate(numbers[i])) < distance(coordinate(curLeft), coordinate(numbers[i]))) {
                answer += "R";
                curRight = numbers[i];
            }
            else if (distance(coordinate(curRight), coordinate(numbers[i])) > distance(coordinate(curLeft), coordinate(numbers[i]))) {
                answer += "L";
                curLeft = numbers[i];
            }   
            else {
                if (hand == "right") {
                    answer += "R";
                    curRight = numbers[i];
                }
                else {
                    answer += "L";
                    curLeft = numbers[i];
                }
            }
        }
    }

    return answer;
}

int main(void)
{
    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "left";

    cout << solution(numbers, hand) << endl;

    return 0;
}
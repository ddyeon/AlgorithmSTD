#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
vector<pair<int, int>>v;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    v.push_back(make_pair(4, 2));
    int a = 0, b = 1;
    for (int i = 1; i <= 12; i++) {
        if (i % 3 == 1) {
            b = 1;
            a++;
            v.push_back(make_pair(a, b));
        }
        else {
            b++;
            v.push_back(make_pair(a, b));
        }
    }
    
    int L = 10, R = 12;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += 'L';
            L = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += 'R';
            R = numbers[i];
        }
        else {
            if (abs(v[L].first - v[numbers[i]].first)+ abs(v[L].second - v[numbers[i]].second) > abs(v[R].first - v[numbers[i]].first) + abs(v[R].second - v[numbers[i]].second)) {
                answer += 'R';
                R = numbers[i];
            }
            else if (abs(v[L].first - v[numbers[i]].first) + abs(v[L].second - v[numbers[i]].second) < abs(v[R].first - v[numbers[i]].first) + abs(v[R].second - v[numbers[i]].second)) {
                answer += 'L';
                L = numbers[i];
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    R = numbers[i];
                }
                else {
                    answer += 'L';
                    L = numbers[i];
                }
            }
        }
    }
    return answer;
}


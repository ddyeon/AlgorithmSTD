#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const pair<double, int>& a, const pair<double, int>& b)
{
    //If the first number is same
    if (a.first == b.first)
        return a.second < b.second; //The second number in Descending order
    return a.first > b.first; //The first number of bigger numbers to move forward -> Descending order
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> arr(N + 1, 0);
    vector<pair<double, int>> failureRatio;

    int len = stages.size();

    for (int i = 0; i < len; i++)
        arr[stages[i] - 1]++;


    for (int i = 1; i <= N; i++) {
        if (len != 0)
            failureRatio.push_back({ (double)arr[i - 1] / len,i });
        else
            failureRatio.push_back({ (double)0,i });
        len -= arr[i - 1];
    }

    sort(failureRatio.begin(), failureRatio.end(), compare);


    for (int i = 0; i < failureRatio.size(); i++) {
        answer.push_back(failureRatio[i].second);
    }


    return answer;
}
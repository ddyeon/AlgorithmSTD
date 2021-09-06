#include <string>
#include <vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
������
���������� ���������� ���� Ŭ�������� ���� �÷��̾�� / ���������� ������ �÷��̾� ��
�������� �������� �����ؼ� ���
*/
unordered_map<int, int> uno;
vector<pair<int, double>> v;
bool oper1(pair<int, double> p1, pair<int, double> p2) {
    return p1.first < p2.first;
}
bool oper2(pair<int, double> p1, pair<int, double> p2) {
    return p1.second > p2.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for (int i = 0; i < stages.size(); i++) uno[stages[i]]++;
    int check = stages[0];
    double cnt = 0;

    double size = stages.size();
    double failure = 0.0;
    for (int i = 1; i < N + 1; i++) {
        failure = uno[i] / (size - cnt);
        v.push_back({ i, failure });
        cnt += uno[i];
    }
    stable_sort(v.begin(), v.end(), oper1);
    stable_sort(v.begin(), v.end(), oper2);
    for (int i = 0;i < v.size(); i++)answer.push_back(v[i].first);
    return answer;
}

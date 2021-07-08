#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer;
    unordered_map<string, int> m;
    int start = 0;
    int end = gems.size() - 1;

    for (int i = 0; i < gems.size(); i++) {
        if(m.find(gems[i]) == m.end()) {
            m.insert(make_pair(gems[i], 1));
        }
        else {
            m.find(gems[i])->second++;
        }
    }

    for (int i = 0; i < gems.size(); i++) {
        if (--m.find(gems[end - i])->second == 0) {
            end -= i;
            break;
        }
    }

    for (int i = 0; i < gems.size(); i++) {
        if (--m.find(gems[start + i])->second == 0) {
            start += i;
            break;
        }
    }

    answer.push_back(start + 1);
    answer.push_back(end + 1);

    return answer;
}

int main(void)
{
    vector<string> gems = {"e", "a", "e", "b", "c", "d", "e"};
    vector<int> answer = solution(gems);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
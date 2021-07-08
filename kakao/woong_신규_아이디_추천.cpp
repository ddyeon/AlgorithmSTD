#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string answer = "";
    vector<char> tmp;

    for (int i = 0; i < new_id.length(); i++) {
        tmp.push_back(new_id[i]);
    }

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] >= 65 && tmp[i] <= 90) {
            tmp[i] += 32;
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '-' || tmp[i] == '_' || tmp[i] == '.') {
            continue;
        }
        tmp.erase(tmp.begin() + i);
        i--;
    }

    for (int i = 0; i < tmp.size(); i++) {
        if (i > 0 && tmp[i] == '.' && tmp[i - 1] == '.') {
            tmp.erase(tmp.begin() + i);
            i--;
        }
    }

    if (tmp.front() == '.') {
        tmp.erase(tmp.begin());
    }

    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i];
    }
    cout << endl;
    
    if (tmp.back() == '.') {
        tmp.pop_back();
    }

    if (tmp.empty()) {
        tmp.push_back('a');
    }

    if (tmp.size() > 15) {
        int loop = tmp.size();
        for (int i = 0; i < loop - 15; i++) {
            tmp.pop_back();
        }
    }

    if (tmp.back() == '.') {
        tmp.pop_back();
    }

    if (tmp.size() < 3) {
        char append = tmp.back();
        while (tmp.size() != 3) {
            tmp.push_back(append);
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        answer += tmp[i];
    }

    return answer;
}

int main(void)
{
    string input;

    cin >> input;

    cout << solution(input) << endl;

    return 0;
}
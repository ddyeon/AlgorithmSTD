#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) 
{
    vector<int> answer;
    vector<int> applicant[108];

    string str_arr[8];
    char *str_buff = new char[1000];
    int str_cnt = 0;

    for (int i = 0; i < info.size(); i++) {
        vector<int> pos;
        strcpy(str_buff, info[i].c_str());

        char *tok = strtok(str_buff, " ");
        while (tok != nullptr) {
            str_arr[str_cnt++] = string(tok);
            tok = strtok(nullptr, " ");
        }

        if (str_arr[0] == "cpp") {
            pos.push_back(0);
            pos.push_back(3); //-
        }
        else if (str_arr[0] == "java") {
            pos.push_back(1);
            pos.push_back(3);
        }
        else if (str_arr[0] == "python") {
            pos.push_back(2);
            pos.push_back(3); 
        }

        if (str_arr[1] == "backend") {
            for (int j = 0; j < 2; j++) {
                pos[j] *= 3;
                pos.push_back(pos[j] + 2);
            }
        }
        else if (str_arr[1] == "frontend") {
            for (int j = 0; j < 2; j++) {
                pos[j] *= 3;
                pos[j] += 1;
                pos.push_back(pos[j] + 1);
            }
        }

        if (str_arr[2] == "junior") {
            for (int j = 0; j < 4; j++) {
                pos[j] *= 3;
                pos.push_back(pos[j] + 2);
            }
        }
        else if (str_arr[2] == "senior") {
            for (int j = 0; j < 4; j++) {
                pos[j] *= 3;
                pos[j] += 1;
                pos.push_back(pos[j] + 1);
            }
        }

        if (str_arr[3] == "chicken") {
            for (int j = 0; j < 8; j++) {
                pos[j] *= 3;
                pos.push_back(pos[j] + 2);
            }
        }
        else if (str_arr[3] == "pizza") {
            for (int j = 0; j < 8; j++) {
                pos[j] *= 3;
                pos[j] += 1;
                pos.push_back(pos[j] + 1);
            }
        }

        for (int j = 0; j < pos.size(); j++) {
            applicant[pos[j]].push_back(atoi(str_arr[4].c_str()));
        }
        str_cnt = 0;
    }

    for (int i = 0; i < query.size(); i++) {
        int pos = 0;
        int cnt = 0;

        strcpy(str_buff, query[i].c_str());

        char *tok = strtok(str_buff, " ");
        while (tok != nullptr) {
            str_arr[str_cnt++] = string(tok);
            tok = strtok(nullptr, " ");
        }

        if (str_arr[0] == "cpp") {
            pos = 0;
        }
        else if (str_arr[0] == "java") {
            pos = 1;
        }
        else if (str_arr[0] == "python") {
            pos = 2;
        }
        else if (str_arr[0] == "-") {
            pos = 3;
        }

        if (str_arr[2] == "backend") {
            pos *= 3;
        }
        else if (str_arr[2] == "frontend") {
            pos *= 3;
            pos += 1;
        }
        else if (str_arr[2] == "-") {
            pos *= 3;
            pos += 2;
        }

        if (str_arr[4] == "junior") {
            pos *= 3;
        }
        else if (str_arr[4] == "senior") {
            pos *= 3;
            pos += 1;
        }
        else if(str_arr[4] == "-") {
            pos *= 3;
            pos += 2;
        }

        if (str_arr[6] == "chicken") {
            pos *= 3;
        }
        else if (str_arr[6] == "pizza") {
            pos *= 3;
            pos += 1;
        }
        else if (str_arr[6] == "-") {
            pos *= 3;
            pos += 2;
        }

        int target = atoi(str_arr[7].c_str());
        for (int j = 0; j < applicant[pos].size(); j++) {
            if (applicant[pos][j] >= target) {
                cnt++;
            }
        }
        answer.push_back(cnt);
        str_cnt = 0;
    }
    delete[] str_buff;

    return answer;
}

int main(void)
{
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int> answer = solution(info, query);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
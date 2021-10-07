#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int column = relation[0].size();
    int arr[8] = { 10,10,10,10,10,10,10,10 };
    unordered_map<string, int>m;
    vector<string>v;
    vector<vector<int>>uniqueList;

    for (int i = 1; i < pow(2, column); i++) {
        int tmp = i;
        string str;
        while (tmp > 0) {
            str += to_string(tmp % 2);
            tmp /= 2;
        }
        while (str.size() < column) {
            str += '0';
        }
        v.push_back(str);
    }

    for (int i = 0; i < v.size(); i++) {
        bool isUnique = true;
        vector <int> temp;
        for (int k = 0; k < column; k++) {
            if (v[i][k] == '1') {
                temp.push_back(k);
            }
        }
        for (int j = 0; j < relation.size(); j++) {
            string str;



            for (int k = 0; k < temp.size(); k++) {
                if (v[i][temp[k]] == '1') {

                    str += relation[j][temp[k]];
                }
            }
            if (m.find(str) == m.end()) {
                m.insert({ str,1 });
            }
            else {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueList.push_back(temp);
        }
    }

    for (int i = 0; i < uniqueList.size(); i++)
    {
        for (int j = 0; j < uniqueList[i].size(); j++)
            cout << uniqueList[i][j] << " ";
        cout << endl;
    }



    for (int i = 1; i < column; i++) {
        for (int j = 0; j < uniqueList.size(); j++) {
            if (uniqueList[j].size() == i) {
                bool isMinimal = true;
                for (int k = 0; k < uniqueList[j].size(); k++) {
                    if (arr[uniqueList[j][k]] < i) {
                        isMinimal = false;
                        break;
                    }
                }
                if (isMinimal) {
                    for (int k = 0; k < uniqueList[j].size(); k++) {
                        arr[uniqueList[j][k]] = i;
                    }
                    answer++;
                }
            }
        }
    }


    return answer;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int tmp1 = arr1[i] | arr2[i];
        string tmp2 = "";

        for (int j = 0; j < n; j++, tmp1 >>= 1) {
            if (0x00000001 & tmp1) {
                tmp2 = "#" + tmp2;
            }
            else {
                tmp2 = " " + tmp2;
            }
        }
        answer.push_back(tmp2);
    }

    return answer;
}

int main(void)
{
    // int n = 5;
    // vector<int> arr1 = {9, 20, 28, 18, 11};
    // vector<int> arr2 = {30, 1, 21, 17, 28};

    int n = 6;
    vector<int> arr1 = {46, 33, 33, 22, 31, 50};
    vector<int> arr2 = {27, 56, 19, 14, 14, 10};

    vector<string> answer = solution(n, arr1, arr2);
    for (auto i : answer) {
        cout << i << endl;
    }

    return 0;
}
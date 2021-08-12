#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] <= answer) {
            break;
        }
        answer++;
    }

    return answer;
}

int main(void)
{
    vector<int> citations = {3, 0, 6, 1, 5};

    cout << solution(citations) << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	int diff = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++) {
        	if (i + diff >= B.size()) {
            		break;
        	}
		if (A[i] < B[i + diff]) {
			answer++;
            		continue;
		}
        	diff++;
        	i--;
	}

	return answer;
}

int main(void)
{

	return 0;
}

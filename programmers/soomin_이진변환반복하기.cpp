// soomin_이진변환.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
string binary(int n) {
	if (n == 1) {
		return "1";
	}
	else if (n <= 3) {
		return to_string((n / 2)) + to_string((n % 2));
	}
	return binary(n / 2) + to_string((n % 2));
}
vector<int> solution(string s) {
	vector<int> answer;
	int erase = 0;
	int bin_count = 0;
	while (s != "1") {
		while ((s.find("0") >= 0) && (s.find("0") < s.size())) {
			s.erase(s.find("0"), 1);
			erase += 1;
		}
		bin_count += 1;
		int new_s = s.size();
		s = binary(new_s);
	}
	answer.push_back(bin_count);
	answer.push_back(erase);
	return answer;
}
int main() {
	solution("110010101001");
	return 0;
}
// soomin_문자열압축.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> l;
void find(string s, int dan, int len) {
	string shorten;
	string now = s.substr(0, dan);
	int cnt = 1;
	for (int i = dan; i < len; i++) {
		if (s.substr(i,dan) == now) {
			cnt += 1;
			i += (dan - 1);
		}
		else {
			if (cnt > 1) {
				shorten += to_string(cnt);
				shorten += now;
				now = s.substr(i,dan);
				cnt = 1;
			}
			else {
				if (i == dan) { shorten += now[0]; }
				shorten += now[0];
				now = s.substr(i +1 ,dan);
				cnt = 1;
			}
		}

	}
	if (cnt > 1) {
		shorten += to_string(cnt);
	}
	shorten += now[dan-1];
	l.push_back(shorten.size());
	
}
int solution(string s) {
	int answer = 0;
	int len = s.size();
	for (int i = 1; i < len / 2; i++) {
		find(s,i, len);
	}
	return answer;
}
int main()
{
	//ababcdcdababcdcd
	solution("abcabcdede");
  
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

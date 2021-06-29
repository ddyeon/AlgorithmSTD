#include <string>
#include <vector>
#include<unordered_map>
using namespace std;
unordered_map<long long, long long> uno;
vector<long long> answer;

long long find(int num) {
    if (uno[num] == 0) return num;
    return find(uno[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    long long checkin = 0;
    for (int i = 0; i < room_number.size(); i++) {
        if (uno[room_number[i]] == 0) {
            answer.push_back(room_number[i]);
            uno[room_number[i]] = find(room_number[i] + 1);
        }
        else {
            checkin = find(uno[room_number[i]]);
            answer.push_back(checkin);
            uno[checkin] = find(checkin + 1);

        }
    }
    return answer;
}


int main(void) {
    solution(10, {1,3,4,1,3,1 });
}

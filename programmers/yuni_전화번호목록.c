#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size(); i++) {
        for(int j=0; j<i; j++){
            
            if(phone_book[i][0]!=phone_book[j][0]) continue;
            if(phone_book[i].substr(0, phone_book[j].size()) == phone_book[j]) {
                answer = false;
                break;
            }
        }
        if(!answer)break;
    }    
    return answer;
}

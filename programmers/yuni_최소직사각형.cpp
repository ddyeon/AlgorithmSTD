#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> big;
vector<int> small;
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][0] > sizes[i][1]){
            small.push_back(sizes[i][1]);
            big.push_back(sizes[i][0]);
        }
        else if(sizes[i][0] <= sizes[i][1]){
            small.push_back(sizes[i][0]);
            big.push_back(sizes[i][1]);
        }
    }
    sort(big.begin(), big.end());
    sort(small.begin(), small.end());
    
    answer = big[sizes.size()-1] * small[sizes.size()-1];
    return answer;
}

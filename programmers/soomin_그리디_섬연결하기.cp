// 섬연결하기
// MST, 크루스칼
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
// 부모 노드 찾기
int getParent(vector<int>& parent, int x){
    if (parent[x]==x){
        return x;
    }
    // 부모노드가 자신이 아니면 최상위 부모노드 찾기
    return parent[x] = getParent(parent, parent[x]);
}
// 부모 노드 병합
void unionParent(vector<int>& parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }
}
bool find(vector<int> &parent, int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b; //사이클 방지
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int maxi = 0;
    vector <int> parent;
    // 가중치 기준 정렬
    sort(costs.begin(), costs.end(), cmp);
    for (auto a: costs) { //제일 높은 노드 찾기
        if (maxi < a[1]){
            maxi = a[1];
        }
    }
    for (int i=0 ; i<= maxi; i++){
        parent.push_back(i);
    }
    for (auto a: costs){
        if (!find(parent, a[0], a[1])){ // 두개의 부모노드가 같지 않다면: 사이클 생성 X
            answer += a[2];
            unionParent(parent, a[0], a[1]);
        }
    }
    return answer;
}

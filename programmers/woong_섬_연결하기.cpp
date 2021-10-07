#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check[110] {};

bool comp(vector<int> a, vector<int> b)
{
    if (a[2] <= b[2]) {
        return true;
    }

    return false;
}

int getParent(int node)
{
    if (check[node] == node) {
        return node;
    }

    return getParent(check[node]);
}

void unionParent(int node1, int node2)
{
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) {
        check[node2] = node1;
    }
    else {
        check[node1] = node2;
    }
}

bool isCycle(int node1, int node2)
{
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) {
        return true;
    }

    return false;
}

//최소신장트리 => 크루스칼 알고리즘 or 프림 알고리즘?
int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;

    sort(costs.begin(), costs.end(), comp);

    for (int i = 0; i < n; i++) {
        check[i] = i;
    }

    for (int i = 0; i < costs.size(); i++) {
        if (!isCycle(costs[i][0], costs[i][1])) {
            answer += costs[i][2];
            unionParent(costs[i][0], costs[i][1]);
        }
    }

    return answer;
}

int main(void)
{
    int n = 4;
    vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

    cout << solution(n, costs) << endl;

    return 0;
}
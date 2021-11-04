from collections import defaultdict
import sys
sys.setrecursionlimit(300000)

answer = 0
def dfs(u, visit, graph, a):
    global answer;
    visit[u] = 1
    for node in graph[u]:
        if visit[node] == 0:
            visit[node] = 1
            a[u] += dfs(node, visit, graph, a)
    answer += abs(a[u])
    return a[u]

def solution(a, edges):
    global answer
    if sum(a) != 0: return -1
    graph = defaultdict(list)
    V = len(a)
    for i in range(V - 1):
        u, v = edges[i][0], edges[i][1]
        graph[u].append(v)
        graph[v].append(u)
    visit = [0] * (V)
    dfs(0, visit, graph, a)
    return answer
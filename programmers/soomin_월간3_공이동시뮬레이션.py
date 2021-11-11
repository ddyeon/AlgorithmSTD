# 월간 3 - 공이동 시뮬레이션 김수민
def solution(n, m, x, y, queries):
    # 도착점을 시작으로해서 거꾸로 시작점 찾아나가기
    # 시작점이 될 수 있는 행, 열의 시작과 끝 지점을 찾아나가서
    # 시작점이 될 수 있는 행의 길이 x 열의 길이 = 정답
    l, r = y, y
    t, b = x, x
    for i in range(len(queries) -1, -1, -1):
        dx = queries[i][1]
        dr = queries[i][0]
        if dr == 0:
            if l != 0:
                l = l + dx
            r += dx
            if r > m - 1:
                r = m - 1
        elif dr == 1:
            l -= dx
            if l < 0: l = 0
            if r != m - 1:
                r -= dx
        elif dr == 2:
            if t != 0:
                t += dx
            b += dx
            if b > n - 1:
                b = n - 1
        else:
            t -= dx
            if t < 0: t = 0
            if b != n - 1:
                b -= dx
        if l > m - 1 or r < 0 or t > n - 1 or b < 0:
            return 0
    answer = (r - l + 1) * (b - t + 1)
    return answer
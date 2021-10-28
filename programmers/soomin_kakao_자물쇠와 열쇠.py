dy = [0, 1, 0]
dx = [1, 0, -1]
def rotate(key, N):
    ret = [[0] * N for _ in range(N)]
    for r in range(N):
        for c in range(N):
            ret[c][N - 1 - r] = key[r][c]
    return ret
def copy(tmp, tmp2, N):
    for i in range(N):
        for j in range(N):
            tmp[i][j] = tmp2[i][j]

def move(dir, N, tmp, key, how):
    for i in range(N):
        for j in range(N):
            ny = i + dy[dir] * how; nx = j + dx[dir] * how
            if ny < 0 or ny >= N or nx <0 or nx >= N: continue
            tmp[ny][nx] = key[i][j]
    return tmp

def check(keyy, lockk):
    N = len(lockk)
    M = len(keyy)
    flag = True
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            for r in range(M):
                for c in range(M):
                    if lockk[i + r][j + c] == keyy[r][c]:
                        flag = False
                        break
                if flag ==False:
                    break
            if flag == True:
                return True
            flag = True

    return False


def solution(key, lock):
    answer = False
    N = len(key)
    if check(key, lock):
        return True
    # key 회전
    for i in range(4):
        if i > 0:
            turn_key = [[0] * N for _ in range(N)]
            turn_key = rotate(key, N)
            copy(key, turn_key, N)
        # key 이동
        for y in range(-(N-1), N-1, 1):
            tmp2 = [[0] * N for _ in range(N)]
            # 아래이동
            tmp2 = move(1, N, tmp2, key,y)
            if check(tmp2, lock):
                answer = True
            for x in range(N-1):
            # 오른쪽이동
                tmp = [[0] * N for _ in range(N)]
                move(0, N, tmp, tmp2,x)
                if check(tmp, lock):
                    answer = True
                if answer:
                    break
            for x in range(N-1):
                tmp = [[0] * N for _ in range(N)]
                move(2, N, tmp, tmp2, x)
                if check(tmp, lock):
                    answer = True
                if answer:
                    break
            if answer:
                break
        if answer: break

    # 맞는지 확인
    return answer

key = [[0,0,0],[1,0,0],[0,1,1]]
lock = [[1,1,1],[1,1,0],[1,0,1]]
print(solution(key, lock))

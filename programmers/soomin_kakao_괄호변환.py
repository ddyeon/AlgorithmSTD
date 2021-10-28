# 괄호변환
def check(st):
    if st[0] == ')':
        return False
    stack = []
    stack.append(st[0])
    i = 1
    while stack:
        if st[i] == '(':
            stack.append('(')
            i += 1
        else:
            if len(stack) == 0:
                return False
            if stack[-1] == '(':
                stack.pop()
            else:
                return False
    return True


def dfs(w):
    left, right = 0, 0
    if len(w) == 0: return ''
    for i in range(len(w)):
        if w[i] == '(':
            left += 1
        else:
            right += 1
        if left == right and left >= 1:
            uidx = i
            break
    u = w[0: uidx + 1]
    v = w[uidx + 1:]
    # 올바른 괄호 문자열이면
    if check(u):
        if len(v) == 0:
            return u
        else:
            u += dfs(v)
            return u
    # 아니면

    else:
        s = ''
        s += '('
        s += dfs(v)
        s += ')'
        u2 = u[1: len(u) - 1]
        for j in range(len(u2)):
            if u2[j] == '(':
                s += ')'
            else:
                s += '('
        return s


def solution(p):
    answer = ''
    answer = dfs(p)
    print(answer)
    return answer
def solution(s):
    answer = len(s)
    len_s = len(s)
    for i in range(1, len_s//2 + 1):
        tmp = 1
        word = ''; before_word = s[0:i]
        for j in range(i, len_s, i):
            if before_word == s[j:j + i]:
                tmp += 1
            else:
                if tmp > 1:
                    word += str(tmp)
                    tmp = 1
                word += before_word
                before_word = s[j:j + i]
        if tmp > 1:
            word += str(tmp)
        word += before_word
        answer = min(answer, len(word))
    return answer
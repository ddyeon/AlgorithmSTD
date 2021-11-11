def solution(a, b, g, s, w, t):
    answer = (10**9) * (10**5) * 4
    start = 0
    end = (10**9) * (10**5) * 4
    while start <= end:
        mid = (start + end) // 2
        gold = 0; silver = 0; total = 0;
        for i in range(len(g)):
            now_g = g[i]
            now_s = s[i]
            now_w = w[i]
            now_t = t[i]
            move_cnt = mid // (now_t * 2)
            if mid % (now_t * 2) >= now_t:
                move_cnt += 1
            if now_g < move_cnt * now_w:
                gold += now_g
            else: gold += move_cnt * now_w
            if now_s < move_cnt * now_w:
                silver += now_s
            else: silver += move_cnt * now_w
            if now_g + now_s < move_cnt * now_w:
                total += now_g + now_s
            else: total += move_cnt * now_w

        # 가능하면 시간 줄여보기
        if gold >= a and silver >= b and total >= a+b:
            end = mid - 1
            answer = min(answer, mid)
        else:
            start = mid + 1

    return answer
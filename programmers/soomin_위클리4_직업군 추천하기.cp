// 위클리챌린지 _ 4주차 직업군 추천하기
def solution(table, languages, preference):
    answer = ''
    gasan = {}
    jobs = ["SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"]
    score = {"SI": 0, "CONTENTS": 0, "HARDWARE": 0, "PORTAL":0, "GAME":0}
    for i in range(5):
        arr = tuple(table[i].split(' '))
        job = arr[0]
        gasan[job] = arr[1:6]
        
    for i in range(len(languages)):
        for j in range(5): # 직업별로 탐색
            for k in range(5): # 직업에서의 언어 가산점
                if gasan[jobs[j]][k] == languages[i]:
                    score[jobs[j]] += (5 - k) * preference[i]
                    break
    tmp = 0
    for i in range(5):
        if score[jobs[i]] > tmp:
            tmp = score[jobs[i]]
            answer = jobs[i]
        elif score[jobs[i]] == tmp:
            if jobs[i] < answer:
                answer = jobs[i]
 
    return answer

def solution(numbers):
    answer = []
    for num in numbers:
        if num % 2 == 0:
            answer.append(num + 1)
        else:
            binNum = "0" + bin(num)[2:]
            zeroIdx = binNum.rfind("0")
            binNum_list = list(binNum)
            binNum_list[zeroIdx] = "1"
            binNum_list[zeroIdx + 1] = "0"
            answer.append(int("".join(binNum_list),2))
    print(*answer)
solution([7, 9])
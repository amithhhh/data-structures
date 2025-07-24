def toBinary(num):
    if num == 0:
        return
    else:
        print(num % 2, end="")
        toBinary(num // 2)

toBinary(4)
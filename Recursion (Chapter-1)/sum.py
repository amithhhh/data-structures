def sumOfDigits(n):
    if n == 0:
        return n
    else:
        return n % 10 + sumOfDigits(n // 10)

print(sumOfDigits(51111111113333333334444444444))

def generateString(n, k, current=""):
    if len(current) == n:
        print(current)
        return
    for i in range(k):
        generateString(n, k, current + str(i))

generateString(3, 3)
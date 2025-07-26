def subsets(nums):
    result = []

    def backtrack(index, path: list):
        result.append(path[:])

        for i in range(index, len(nums)):
            path.append(i)
            backtrack(i + 1, path=path)
            path.pop()

    backtrack(0, [])
    return result

print(subsets([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
def backtrack(nums, path, used):
    if (len(path) == len(nums)):
        result.append(path[:])
    for i in range(len(nums)):
        if used[i]:
            continue
        used[i] = True
        path.append(nums[i])
        backtrack(nums, path, used)
        path.pop()
        used[i] = False
        
nums = [1, 2, 3, 4, 5]
result = []
backtrack(nums, [], [False] * len(nums))
print(result)